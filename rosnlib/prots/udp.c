/*
 * =======================================================================================
 *
 *       Filename: udp.c
 *    Description: UDP handling
 *       Compiler: gcc
 *         Author: Simon L. J. Robin | https://sljrobin.org
 *        Created: 2015-04-24 12:27:23
 *       Modified: 2016-02-13 13:40:31
 *
 * =======================================================================================
 */

#include <arpa/inet.h>
#include <pcap.h>
#include <stdint.h>
#include <stdio.h>

#include "../utils/clrprnt.h"
#include "eth.h"
#include "ip.h"
#include "udp.h"


/** 
 * rosn_prots_udp_handle()
 * 
 * Handle UDP
 *      pkt: the packet
 *      pktlen: packet length
 */
void rosn_prots_udp_handle(const u_char *pkt, uint32_t pktlen)
{
    struct rosn_ipv4hdr *iphdr;         /* IP Header */
    struct rosn_udphdr *udphdr = NULL;  /* UDP Header */
    unsigned int len_ethhdr = 0;        /* Size of an Ethernet header */
    unsigned int len_iphdr = 0;         /* Size of an IP header */
    unsigned int len_udphdr = 0;        /* Size of a UDP header */
    unsigned int sizehdr = 0;           /* Size for the main header */

    /* Printers */
    rosn_clrset ptsep;
    rosn_clrset ptudp;
    rosn_clrset ptudp_csum; 
    rosn_clrset ptudp_len; 
    rosn_clrset ptudp_portdst;
    rosn_clrset ptudp_portsrc;

    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptsep), ROSN_CLR_WHITE), ROSN_ATTR_NONE);          /* Separator */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_init(&ptudp), ROSN_ATTR_UNDERLINE);                                               /* UDP */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptudp_csum), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);    /* UDP Checksum */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptudp_len), ROSN_CLR_MAGENTA), ROSN_ATTR_NONE);    /* UDP Length */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptudp_portdst), ROSN_CLR_BLUE), ROSN_ATTR_NONE);   /* UDP Destination Port */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptudp_portsrc), ROSN_CLR_CYAN), ROSN_ATTR_NONE);   /* UDP Source Port */

    iphdr = (struct rosn_ipv4hdr *)(pkt + sizeof(struct rosn_ethhdr));                      /* Pointing to the IP Header */
    udphdr = (struct rosn_udphdr *)(pkt + (iphdr->hlen * 4) + sizeof(struct rosn_ethhdr));  /* Pointing to the UDP Header */

    len_ethhdr = sizeof(struct rosn_ethhdr);        /* Getting the size of an Ethernet header */
    len_iphdr = iphdr->hlen * 4;                    /* Getting the size of an IP header */
    len_udphdr = sizeof(udphdr);                    /* Getting the size of a UDP header */
    sizehdr = len_ethhdr + len_iphdr + len_udphdr;  /* Getting the size for the main header */

    cprintf(&ptsep, "¤"); printf("["); cprintf(&ptudp, "UDP"); printf("]");             /* UDP */
    printf("["); cprintf(&ptudp_portsrc, "%d", ntohs(udphdr->portsrc)); printf("]");    /* UDP Source Port */
    printf("["); cprintf(&ptudp_portdst, "%d", ntohs(udphdr->portdst)); printf("]");    /* UDP Destination Port */
    printf("["); cprintf(&ptudp_len, "%d", ntohs(udphdr->len)); printf("]");            /* UDP Length */
    printf("["); cprintf(&ptudp_csum, "%x", ntohs(udphdr->csum)); printf("]");          /* UDP Checksum */

    /* Print payload */
    printf("\n");
    rosn_prots_udp_payload(pkt + sizehdr, pktlen - sizehdr);
}


/** 
 * rosn_prots_udp_payload()
 * 
 * Print payload for a UDP packet
 *      pkt: the packet
 *      sizehdr: header size
 */
void rosn_prots_udp_payload(const u_char *pkt, int sizehdr)
{

    int cnti = 0;      /* A counter for loops */
    int cntj = 0;      /* A counter for loops */

    for (cnti = 0; cnti < sizehdr; cnti++) {
        /* If 1 line of hexadecimal is completed */
        if (cnti != 0 && cnti % 16 == 0) {
            printf("\t");
            /* Printer; ASCII */
            for (cntj = cnti - 16; cntj < cnti; cntj++) {
                /* Printable character (number or alphabet) */
                if (pkt[cntj] >= 32 && pkt[cntj] <= 128)
                    printf("%c", (unsigned char)pkt[cntj]);
                /* Else print `.` */
                else
                    printf(".");
            }

            printf("\n");
        }
         
        /* Printer; Hexadecimal, Indentation */
        if (cnti % 16 == 0)
            printf("\t");

        /* Printer; Hexadecimal, Character */
        printf(" %02X", (unsigned int)pkt[cnti]);
        
        /* Printer; Hexadecimal, Last space */
        if (cnti == sizehdr - 1) {
            /* Print extra spaces */
            for (cntj = 0; cntj < 15 - cnti % 16; cntj++)
                printf("   ");
            
            /* Complete last line */
            printf("        ");
            
            /* Printer; ASCII, Last line */
            for (cntj = cnti - cnti % 16 ; cntj <= cnti; cntj++) {
                /* Printable character (number or alphabet) */
                if (pkt[cntj] >= 32 && pkt[cntj] <= 128)
                    printf("%c", (unsigned char)pkt[cntj]);
                /* Else print `.` */
                else
                    printf(".");
            }
             
            printf("\n");
        }
    }
}
