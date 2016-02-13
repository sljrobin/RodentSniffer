/*
 * =======================================================================================
 *
 *       Filename: eth.c
 *    Description: Ethernet handling
 *       Compiler: gcc
 *         Author: Simon L. J. Robin | https://sljrobin.org
 *        Created: 2015-04-30 15:28:41
 *       Modified: 2016-02-13 13:41:22
 *
 * =======================================================================================
 */

#include <netinet/in.h>
#include <pcap.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../utils/clrprnt.h"
#include "eth.h"


/** 
 * rosn_prots_eth_getethtype()
 * 
 * Get EtherType
 *      pkt: the packet
 * Return EtherType
 */
uint16_t rosn_prots_eth_getethtype(const u_char *pkt)
{
    struct rosn_ethhdr *ethhdr;     /* Ethernet Header */
    uint16_t etht;                  /* EtherType */

    ethhdr = (struct rosn_ethhdr *)pkt;     /* Pointing to the Ethernet Header */
    etht = ntohs(ethhdr->ethtype);          /* Getting the EtherType */

    return etht;
}


/** 
 * rosn_prots_eth_handle()
 * 
 * Handle Ethernet protocol
 *      pkt: the packet
 *      pktlen: packet length
 */
void rosn_prots_eth_handle(const u_char *pkt, uint32_t pktlen)
{
    int cnt_addr = 0;               /* A counter for printing addresses */
    struct rosn_ethhdr *ethhdr;     /* Ethernet Header */

    /* Printers */
    rosn_clrset pteth;
    rosn_clrset pteth_addrdst;
    rosn_clrset pteth_addrsrc;
    rosn_clrset pteth_ethtype;
    rosn_clrset ptsep;

    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_init(&pteth), ROSN_ATTR_UNDERLINE);                                               /* Ethernet */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pteth_addrdst), ROSN_CLR_CYAN), ROSN_ATTR_NONE);   /* Ethernet Destination Address */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pteth_addrsrc), ROSN_CLR_BLUE), ROSN_ATTR_NONE);   /* Ethernet Source Address */ 
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pteth_ethtype), ROSN_CLR_GREEN), ROSN_ATTR_NONE);  /* Ethernet Ether Type */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptsep), ROSN_CLR_WHITE), ROSN_ATTR_NONE);          /* Separator */

    ethhdr = (struct rosn_ethhdr *)pkt;                                         /* Pointing to the Ethernet Header */

    cprintf(&ptsep, "¤"); printf("["); cprintf(&pteth, "Eth"); printf("]");     /* Ethernet */

    /* Ethernet Destination Address */
    printf("[");
    for (cnt_addr = 0; cnt_addr < (ROSNLIB_ETH_ADDRLEN); cnt_addr++) {
        cprintf(&pteth_addrdst, "%02x:", ethhdr->addrdst[cnt_addr]);
        if (cnt_addr == (ROSNLIB_ETH_ADDRLEN - 1))
            cprintf(&pteth_addrdst, "%02x", ethhdr->addrdst[cnt_addr]);
    }
    printf("]");

    /* Ethernet Source Address */
    printf("[");
    for (cnt_addr = 0; cnt_addr < (ROSNLIB_ETH_ADDRLEN); cnt_addr++) {
        cprintf(&pteth_addrsrc, "%02x:", ethhdr->addrsrc[cnt_addr]);
        if (cnt_addr == (ROSNLIB_ETH_ADDRLEN - 1))
            cprintf(&pteth_addrsrc, "%02x", ethhdr->addrsrc[cnt_addr]);
    }
    printf("]");

    /* Ethernet Ether Type */
    printf("["); cprintf(&pteth_ethtype, "%x", ntohs(ethhdr->ethtype)); printf("]");
}
