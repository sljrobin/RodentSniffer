/*
 * =======================================================================================
 *
 *       Filename: arp.c
 *    Description: ARP handling
 *       Compiler: gcc
 *         Author: Simon L. J. Robin | https://sljrobin.org
 *        Created: 2015-04-30 15:28:41
 *       Modified: 2016-02-13 13:41:33
 *
 * =======================================================================================
 */

#include <netinet/in.h>
#include <pcap.h>
#include <stdint.h>
#include <stdio.h>

#include "../utils/clrprnt.h"
#include "arp.h"
#include "eth.h"


/** 
 * rosn_prots_arp_handle()
 * 
 * Handle ARP
 *      pkt: the packet
 *      pktlen: packet length
 */
void rosn_prots_arp_handle(const u_char *pkt, uint32_t pktlen)
{
    int cnt_addr = 0;                   /* A counter for printing addresses */
    struct rosn_arphdr *arphdr;         /* ARP Header */

    /* Printers */
    rosn_clrset ptarp;
    rosn_clrset ptarp_addrhdwrsndr;
    rosn_clrset ptarp_addrhdwrtrgt;
    rosn_clrset ptarp_addripsndr;
    rosn_clrset ptarp_addriptrgt;
    rosn_clrset ptarp_lenaddrhdwr;
    rosn_clrset ptarp_lenaddrprot;
    rosn_clrset ptarp_op;
    rosn_clrset ptarp_typehdwr;
    rosn_clrset ptarp_typeprot;
    rosn_clrset ptsep;

    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_init(&ptarp), ROSN_ATTR_UNDERLINE);                                                       /* ARP */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptarp_addrhdwrsndr), ROSN_CLR_BLUE), ROSN_ATTR_NONE);      /* ARP Sender Hardware Address */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptarp_addrhdwrtrgt), ROSN_CLR_CYAN), ROSN_ATTR_NONE);      /* ARP Target Hardware Address */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptarp_addripsndr), ROSN_CLR_BLUE), ROSN_ATTR_NONE);        /* ARP Sender IP Address */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptarp_addriptrgt), ROSN_CLR_CYAN), ROSN_ATTR_NONE);        /* ARP Sender Target Address */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptarp_lenaddrhdwr), ROSN_CLR_MAGENTA), ROSN_ATTR_NONE);    /* ARP Hardware Address length */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptarp_lenaddrprot), ROSN_CLR_MAGENTA), ROSN_ATTR_NONE);    /* ARP Protocol Address length */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptarp_op), ROSN_CLR_BLUE), ROSN_ATTR_NONE);                /* ARP Operation */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptarp_typehdwr), ROSN_CLR_GREEN), ROSN_ATTR_NONE);         /* ARP Hardware Type */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptarp_typeprot), ROSN_CLR_GREEN), ROSN_ATTR_NONE);         /* ARP Protocol Type */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptsep), ROSN_CLR_WHITE), ROSN_ATTR_NONE);                  /* Separator */

    arphdr = (struct rosn_arphdr *)(pkt + 14);                                          /* Pointing to the ARP Header */

    cprintf(&ptsep, "¤"); printf("["); cprintf(&ptarp, "ARP"); printf("]");             /* ARP */
    printf("["); cprintf(&ptarp_typehdwr, "%d", ntohs(arphdr->typehdwr)); printf("]");  /* ARP Hardware Type */
    printf("["); cprintf(&ptarp_typeprot, "%x", ntohs(arphdr->typeprot)); printf("]");  /* ARP Protocol Type */
    printf("["); cprintf(&ptarp_lenaddrhdwr, "%d", arphdr->lenaddrhdwr); printf("]");   /* ARP Hardware Address length */
    printf("["); cprintf(&ptarp_lenaddrprot, "%d", arphdr->lenaddrprot); printf("]");   /* ARP Protocol Address length */
    printf("["); cprintf(&ptarp_op, "%d", ntohs(arphdr->op)); printf("]");              /* ARP Operation */

    /* ARP Sender Hardware Address */
    printf("[");
    for (cnt_addr = 0; cnt_addr < (ROSNLIB_ARP_ADDRHWLEN - 1); cnt_addr++) {
        cprintf(&ptarp_addrhdwrsndr, "%02x:", arphdr->addrhdwrsndr[cnt_addr]);
    }
    cprintf(&ptarp_addrhdwrsndr, "%02x", arphdr->addrhdwrsndr[ROSNLIB_ARP_ADDRHWLEN - 1]);
    printf("]");

    /* ARP Sender IP Address */
    printf("[");
    for (cnt_addr = 0; cnt_addr < (ROSNLIB_ARP_ADDRIPLEN - 1); cnt_addr++) {
        cprintf(&ptarp_addripsndr, "%d.", arphdr->addripsndr[cnt_addr]);
    }
    cprintf(&ptarp_addripsndr, "%d", arphdr->addripsndr[ROSNLIB_ARP_ADDRIPLEN - 1]);
    printf("]");

    /* ARP Target Hardware Address */
    printf("[");
    for (cnt_addr = 0; cnt_addr < (ROSNLIB_ARP_ADDRHWLEN - 1); cnt_addr++) {
        cprintf(&ptarp_addrhdwrtrgt, "%02x:", arphdr->addrhdwrtrgt[cnt_addr]);
    }
    cprintf(&ptarp_addrhdwrtrgt, "%02x", arphdr->addrhdwrtrgt[ROSNLIB_ARP_ADDRHWLEN - 1]);
    printf("]");

    /* ARP Target IP Address */
    printf("[");
    for (cnt_addr = 0; cnt_addr < (ROSNLIB_ARP_ADDRIPLEN - 1); cnt_addr++) {
        cprintf(&ptarp_addriptrgt, "%d.", arphdr->addriptrgt[cnt_addr]);
    }
    cprintf(&ptarp_addriptrgt, "%d", arphdr->addriptrgt[ROSNLIB_ARP_ADDRIPLEN - 1]);
    printf("]");
}
