/*
 * =======================================================================================
 *
 *       Filename: sniffing.c
 *    Description: Sniffing functions
 *       Compiler: gcc
 *         Author: Simon L. J. Robin - http://sljrobin.com
 *        Created: 2015-04-30 15:28:41
 *       Modified: 2015-07-08 11:43:48
 *
 * =======================================================================================
 */

#include <netinet/ether.h>
#include <netinet/in.h>
#include <pcap.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "../boot/dtlnk.h"
#include "../prots/arp.h"
#include "../prots/eth.h"
#include "../prots/icmp.h"
#include "../prots/ip.h"
#include "../prots/tcp.h"
#include "../prots/udp.h"
#include "../utils/clrprnt.h"
#include "../utils/pkttime.h"
#include "sniff.h"


/** 
 * rosn_process_sniff_capture()
 * 
 * Capture function for sniffing
 *      args: user pointer passed to the rosn_process_sniff_loop() function
 *      pkthdr: information about the captured packet
 *      pkt: the captured packet
 */
void rosn_process_sniff_capture(u_char *args, const struct pcap_pkthdr *pkthdr, const u_char *pkt)
{
    static int cnt_pkt = 1;               /* A counter for packets */
    uint8_t ipprot = 0;                   /* IP Protocol */
    uint16_t ethtype = 0;                 /* EtherType */
    uint32_t pktlen = 0;                  /* Length of the current packet */
   
    /* Printers */
    rosn_clrset ptprot_nothandledid;
    rosn_clrset ptprot_nothandledname;
    rosn_clrset ptprot_number;
    rosn_clrset ptsep;

    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptprot_nothandledid), ROSN_CLR_GREEN), ROSN_ATTR_NONE);  /* Protocol ID not handled */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_init(&ptprot_nothandledname), ROSN_ATTR_UNDERLINE);                                     /* Protocol Name not handled */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptprot_number), ROSN_CLR_RED), ROSN_ATTR_NONE);          /* Protocol number */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptsep), ROSN_CLR_WHITE), ROSN_ATTR_NONE);                /* Separator */
    
    ethtype = rosn_prots_eth_getethtype(pkt);                               /* Getting the EtherType of the current packet */
    pktlen = pkthdr->len;                                                   /* Getting the length of the current packet */
    printf("["); cprintf(&ptprot_number, "%03d", cnt_pkt++); printf("]");   /* Getting the number of the current packet */
    rosn_utils_pkttime_date(pkthdr);                                        /* Getting the time of the current packet */
    rosn_utils_pkttime_hour(pkthdr);                                        /* Getting the hour of the current packet */
    cprintf(&ptsep, "¤");

    rosn_prots_eth_handle(pkt, pktlen);                                     /* Handling Ethernet */

    switch (ethtype) {
        /* IPv4 */
        case ETHERTYPE_IP:
            ipprot = rosn_prots_ipv4_getprot(pkt);                          /* Getting the IP Protocol */
            rosn_prots_ipv4_handle(pkt, pktlen);
            switch (ipprot) {
                /* ICMP */
                case IPPROTO_ICMP:
                    rosn_prots_icmp_handle(pkt, pktlen);
                    break;
                /* TCP */
                case IPPROTO_TCP:
                    rosn_prots_tcp_handle(pkt, pktlen);
                    break;
                /* UDP */
                case IPPROTO_UDP:
                    rosn_prots_udp_handle(pkt, pktlen);
                    break;
                /* Miscellaneous */
                default:
                    cprintf(&ptsep, "¤"); printf("[");
                    cprintf(&ptprot_nothandledid, "%d", ipprot); printf(": ");
                    cprintf(&ptprot_nothandledname, "IPv4 protocol not handled"); printf("]");
                    break;
            }
        break;
        /* IPv6 */
        case ETHERTYPE_IPV6:
            rosn_prots_ipv6_handle(pkt, pktlen);
            break;
        /* ARP */
        case ETHERTYPE_ARP:
            rosn_prots_arp_handle(pkt, pktlen);
            break;
        /* Miscellaneous */
        default:
            cprintf(&ptsep, "¤"); printf("[");
            cprintf(&ptprot_nothandledid, "%d", ethtype); printf(": ");
            cprintf(&ptprot_nothandledname, "Protocol not handled"); printf("]");
            break;
    }
    printf("\n");
}


/** 
 * rosn_process_sniff_loop()
 * 
 * Loop function for sniffing
 *      dev: device to use for sniffing
 *      fltr: network filter
 *      mode: setter for the Promiscuous mode
 */
void rosn_process_sniff_loop(char *dev, char *fltr, int mode)
{
    char errbuf[PCAP_ERRBUF_SIZE] = {0};        /* Buffer to store error messages */
    int dlhdrt = 0;                             /* Link-Layer Header Type */
    pcap_t *handle;                             /* A handle for the device which is sniffed */ 
    struct bpf_program bpf;                     /* Berkeley Packet Filter */
    uint32_t bpf_submask;                       /* Device Subnet mask */
    uint32_t bpf_srcip;                         /* Device Source IP */

    /* Printers */
    rosn_clrset ptstep_error;
    rosn_clrset ptstep_info;
    rosn_clrset ptstep_inprogress;
    rosn_clrset ptstep_valid;

    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptstep_error), ROSN_CLR_RED), ROSN_ATTR_NONE);         /* Step error */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptstep_info), ROSN_CLR_BLUE), ROSN_ATTR_NONE);         /* Step info */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptstep_inprogress), ROSN_CLR_WHITE), ROSN_ATTR_NONE); /* Step in progress */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptstep_valid), ROSN_CLR_GREEN), ROSN_ATTR_NONE);       /* Step valid */

    /* Promiscuous mode handling */
    switch (mode) {
        /* ON */
        case ROSN_PROMISCUOUS_ON:
            cprintf(&ptstep_inprogress, "Checking the status of the Promiscuous mode: ");
            cprintf(&ptstep_info, "on");
            cprintf(&ptstep_valid, "\t\t[DONE]\n");
            break;
        /* OFF */
        case ROSN_PROMISCUOUS_OFF:
            cprintf(&ptstep_inprogress, "Checking the status of the Promiscuous mode: ");
            cprintf(&ptstep_info, "off");
            cprintf(&ptstep_valid, "\t[DONE]\n");
            break;
        /* Error */
        default:
            cprintf(&ptstep_error, "[ERROR]: Could not check the state of the Promiscuous mode!\n");
            exit(1);
    }

    /* Opening device */
    cprintf(&ptstep_inprogress, "Opening device: ");
    cprintf(&ptstep_info, "%s\t\t\t\t\t", dev);
    handle = pcap_open_live(dev, ROSN_MAX_CAPTURED_BYTES, mode, ROSN_WAIT_COPY, errbuf);
    if (handle == NULL) {
        cprintf(&ptstep_error, "[ERROR]: Could not open device: %s\n", errbuf);
        exit(1);
    }
    cprintf(&ptstep_valid, "[DONE]\n");

    /* Getting the device's source IP and subnet mask */
    cprintf(&ptstep_inprogress, "Getting IP address and subnet mask\t\t\t");
    if (pcap_lookupnet(dev, &bpf_srcip, &bpf_submask, errbuf) < 0) {
        cprintf(&ptstep_error, "[ERROR]: Could not find the device's source IP and subnet mask: %s\n", errbuf);
        exit(1);
    }
    cprintf(&ptstep_valid, "[DONE]\n");

    /* Converting the packet filter */
    cprintf(&ptstep_inprogress, "Converting filter\t\t\t\t\t");
    if (pcap_compile(handle, &bpf, fltr, 0, bpf_submask)) {
        cprintf(&ptstep_error, "[ERROR]: Could not convert the packet filter '%s': %s\n", fltr, pcap_geterr(handle));
        exit(1);
    }
    cprintf(&ptstep_valid, "[DONE]\n");

    /* Assign filter to the given libpcap socket */
    cprintf(&ptstep_inprogress, "Assigning filter\t\t\t\t\t");
    if (pcap_setfilter(handle, &bpf) < 0) {
        cprintf(&ptstep_error, "[ERROR]: Could not assing the filter to the given socket: %s\n", pcap_geterr(handle));
        exit(1);
    }
    cprintf(&ptstep_valid, "[DONE]\n");

    /* Getting the Link-Layer Header Type */
    cprintf(&ptstep_inprogress, "Getting the Link-Layer Header Type: ");
    dlhdrt = rosn_boot_dtlnk_findhdrt(handle);
    cprintf(&ptstep_info, "%d\t\t\t", dlhdrt);
    cprintf(&ptstep_valid, "[DONE]\n");
    printf("\n");

    /* Sniffing */
    pcap_loop(handle, -1, rosn_process_sniff_capture, NULL);
}
