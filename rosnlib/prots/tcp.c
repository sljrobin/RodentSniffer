/*
 * =======================================================================================
 *
 *       Filename: tcp.c
 *    Description: TCP handling
 *       Compiler: gcc
 *         Author: Simon L. J. Robin - http://sljrobin.com
 *        Created: 2015-04-24 12:27:23
 *       Modified: 2015-07-08 11:09:31
 *
 * =======================================================================================
 */

#include <netinet/in.h>
#include <pcap.h>
#include <stdint.h>
#include <stdio.h>

#include "../utils/clrprnt.h"
#include "eth.h"
#include "ip.h"
#include "tcp.h"


/** 
 * rosn_prots_tcp_handle()
 * 
 * Handle TCP
 *      pkt: the packet
 *      pktlen: packet length
 */
void rosn_prots_tcp_handle(const u_char *pkt, uint32_t pktlen)
{
    struct rosn_ipv4hdr *iphdr;         /* IP Header */
    struct rosn_tcphdr *tcphdr = NULL;  /* TCP Header */
    unsigned int len_ethhdr = 0;        /* Size of an Ethernet header */
    unsigned int len_iphdr = 0;         /* Size of an IP header */
    unsigned int len_tcphdr = 0;        /* Size of a TCP header */
    unsigned int sizehdr = 0;           /* Size for the main header */

    /* Printers */
    rosn_clrset ptsep;
    rosn_clrset pttcp;
    rosn_clrset pttcp_ack;
    rosn_clrset pttcp_csum;
    rosn_clrset pttcp_doff;
    rosn_clrset pttcp_flgs;
    rosn_clrset pttcp_portdst;
    rosn_clrset pttcp_portsrc;
    rosn_clrset pttcp_seq;
    rosn_clrset pttcp_uptr;
    rosn_clrset pttcp_wins;

    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptsep), ROSN_CLR_WHITE), ROSN_ATTR_NONE);          /* Separator */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_init(&pttcp), ROSN_ATTR_UNDERLINE);                                               /* TCP */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pttcp_ack), ROSN_CLR_RED), ROSN_ATTR_NONE);        /* TCP Acknowledgment number */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pttcp_csum), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);    /* TCP Checksum */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pttcp_doff), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);    /* TCP Data Offset */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pttcp_flgs), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);    /* TCP Flags */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pttcp_portdst), ROSN_CLR_CYAN), ROSN_ATTR_NONE);   /* TCP Destination Port */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pttcp_portsrc), ROSN_CLR_BLUE), ROSN_ATTR_NONE);   /* TCP Source Port */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pttcp_seq), ROSN_CLR_RED), ROSN_ATTR_NONE);        /* TCP Sequence number */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pttcp_uptr), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);    /* TCP Urgent Pointer */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pttcp_wins), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);    /* TCP Window Size */ 

    iphdr = (struct rosn_ipv4hdr *)(pkt + sizeof(struct rosn_ethhdr));                      /* Pointing to the IP Header */
    tcphdr = (struct rosn_tcphdr *)(pkt + (iphdr->hlen * 4) + sizeof(struct rosn_ethhdr));  /* Pointing to the TCP Header*/

    len_ethhdr = sizeof(struct rosn_ethhdr);        /* Getting the size of an Ethernet header */
    len_iphdr = iphdr->hlen * 4;                    /* Getting the size of an IP header */
    len_tcphdr = sizeof(tcphdr);                    /* Getting the size of a TCP header */
    sizehdr = len_ethhdr + len_iphdr + len_tcphdr;  /* Getting the size for the main header */

    cprintf(&ptsep, "¤"); printf("["); cprintf(&pttcp, "TCP"); printf("]");             /* TCP */
    printf("["); cprintf(&pttcp_portsrc, "%u", ntohs(tcphdr->portsrc)); printf("]");    /* TCP Source Port */
    printf("["); cprintf(&pttcp_portdst, "%u", ntohs(tcphdr->portdst)); printf("]");    /* TCP Destination Port */
    printf("["); cprintf(&pttcp_seq, "%u", ntohl(tcphdr->seq)); printf("]");            /* TCP Sequence number */
    printf("["); cprintf(&pttcp_ack, "%u", ntohl(tcphdr->ack)); printf("]");            /* TCP Acknowledgment number */
    printf("["); cprintf(&pttcp_doff, "%d", tcphdr->doff * 4); printf("]");             /* TCP Data Offset */
    printf("["); cprintf(&pttcp_flgs, "%d", tcphdr->flgs); printf("]");                 /* TCP Flags */
    printf("["); cprintf(&pttcp_wins, "%d", tcphdr->wins); printf("]");                 /* TCP Window Size */
    printf("["); cprintf(&pttcp_csum, "%d", tcphdr->csum); printf("]");                 /* TCP Checksum */
    printf("["); cprintf(&pttcp_uptr, "%d", tcphdr->uptr); printf("]");                 /* TCP Urgent Pointer */

    /* Print payload */
    printf("\n");
    rosn_prots_tcp_payload(pkt + sizehdr, pktlen - sizehdr);
}


/** 
 * rosn_prots_tcp_payload()
 * 
 * Print payload for a TCP packet
 *      pkt: the packet
 *      sizehdr: header size
 */
void rosn_prots_tcp_payload(const u_char *pkt, int sizehdr)
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
