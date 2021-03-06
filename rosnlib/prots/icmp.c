/*
 * =======================================================================================
 *
 *       Filename: icmp.c
 *    Description: ICMP handling
 *       Compiler: gcc
 *         Author: Simon L. J. Robin | https://sljrobin.org
 *        Created: 2015-04-30 15:28:41
 *       Modified: 2016-02-13 13:41:11
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
#include "icmp.h"


/** 
 * rosn_prots_icmp_handle()
 * 
 * Handle ICMP
 *      pkt: the packet
 *      pktlen: packet length
 */
void rosn_prots_icmp_handle(const u_char *pkt, uint32_t pktlen)
{
    struct rosn_icmphdr *icmphdr;   /* ICMP Header */
    struct rosn_ipv4hdr *ipv4hdr;   /* IPv4 Header */
    
    /* Printers */
    rosn_clrset pticmp;
    rosn_clrset pticmp_code;
    rosn_clrset pticmp_csum; 
    rosn_clrset pticmp_id;
    rosn_clrset pticmp_seq;
    rosn_clrset pticmp_type;
    rosn_clrset ptsep;

    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_init(&pticmp), ROSN_ATTR_UNDERLINE);                                              /* ICMP */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pticmp_code), ROSN_CLR_BLUE), ROSN_ATTR_NONE);     /* ICMP Code */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pticmp_csum), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);   /* ICMP Checksum */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pticmp_id), ROSN_CLR_RED), ROSN_ATTR_NONE);        /* ICMP Identifier */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pticmp_seq), ROSN_CLR_CYAN), ROSN_ATTR_NONE);      /* ICMP Sequence */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pticmp_type), ROSN_CLR_GREEN), ROSN_ATTR_NONE);    /* ICMP Type */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptsep), ROSN_CLR_WHITE), ROSN_ATTR_NONE);          /* Separator */

    ipv4hdr = (struct rosn_ipv4hdr *)(pkt + sizeof(struct rosn_ethhdr));                        /* Pointing to the IP Header */
    icmphdr = (struct rosn_icmphdr *)(pkt + (ipv4hdr->hlen * 4) + sizeof(struct rosn_ethhdr));  /* Pointing to the ICMP Header*/

    cprintf(&ptsep, "¤"); printf("["); cprintf(&pticmp, "ICMP"); printf("]");   /* ICMP */
    printf("["); cprintf(&pticmp_type, "%d", icmphdr->type); printf("]");       /* ICMP Type */
    printf("["); cprintf(&pticmp_code, "%d", icmphdr->code); printf("]");       /* ICMP Code */
    printf("["); cprintf(&pticmp_csum, "%d", icmphdr->csum); printf("]");       /* ICMP Checksum */
    printf("["); cprintf(&pticmp_id, "%d", icmphdr->id); printf("]");           /* ICMP Identifier */
    printf("["); cprintf(&pticmp_seq, "%d", icmphdr->seq); printf("]");         /* ICMP Sequence */
}
