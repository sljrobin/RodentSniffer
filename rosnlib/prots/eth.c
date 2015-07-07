/*
 * =======================================================================================
 *
 *       Filename: eth.c
 *    Description:
 *       Compiler: gcc
 *         Author: Simon L. J. Robin - http://sljrobin.com
 *        Created: 2015-04-30 15:28:41
 *       Modified: 2015-07-07 11:15:49
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

uint16_t rosn_prots_eth_getethtype(const u_char *pkt)
{
    uint16_t etht;
    struct rosn_ethhdr *ethhdr;

    ethhdr = (struct rosn_ethhdr *)pkt;
    etht = ntohs(ethhdr->ethtype);

    return etht;
}


void rosn_prots_eth_handle(const u_char *pkt, uint32_t pktlen)
{
    int cnt_addr = 0;   /* A counter for printing addresses */
    struct rosn_ethhdr *ethhdr;

    ethhdr = (struct rosn_ethhdr *)pkt;

    rosn_clrset ptsep; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptsep), ROSN_CLR_WHITE), ROSN_ATTR_NONE);
    rosn_clrset pteth; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_init(&pteth), ROSN_ATTR_UNDERLINE);
    rosn_clrset pteth_ethtype; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pteth_ethtype), ROSN_CLR_GREEN), ROSN_ATTR_NONE);
    rosn_clrset pteth_addrdst; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pteth_addrdst), ROSN_CLR_CYAN), ROSN_ATTR_NONE);
    rosn_clrset pteth_addrsrc; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pteth_addrsrc), ROSN_CLR_BLUE), ROSN_ATTR_NONE);


    cprintf(&ptsep, "¤");
    printf("["); cprintf(&pteth, "Eth"); printf("]");
    /*** Ethernet Destination Address ***/
    printf("[");
    for (cnt_addr = 0; cnt_addr < (ROSNLIB_ETH_ADDRLEN); cnt_addr++) {
        cprintf(&pteth_addrdst, "%02x:", ethhdr->addrdst[cnt_addr]);
        if (cnt_addr == (ROSNLIB_ETH_ADDRLEN - 1))
            cprintf(&pteth_addrdst, "%02x", ethhdr->addrdst[cnt_addr]);
    }
    printf("]");

    /*** Ethernet Source Address ***/
    printf("[");
    for (cnt_addr = 0; cnt_addr < (ROSNLIB_ETH_ADDRLEN); cnt_addr++) {
        cprintf(&pteth_addrsrc, "%02x:", ethhdr->addrsrc[cnt_addr]);
        if (cnt_addr == (ROSNLIB_ETH_ADDRLEN - 1))
            cprintf(&pteth_addrsrc, "%02x", ethhdr->addrsrc[cnt_addr]);
    }
    printf("]");

    /*** Ethernet Type ***/
    printf("["); cprintf(&pteth_ethtype, "%x", ntohs(ethhdr->ethtype)); printf("]");
}
