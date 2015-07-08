/*
 * =======================================================================================
 *
 *       Filename: eth.h
 *    Description: Ethernet handling
 *       Compiler: gcc
 *         Author: Simon L. J. Robin - http://sljrobin.com
 *        Created: 2015-04-30 15:27:53
 *       Modified: 2015-07-08 10:16:55
 *
 * =======================================================================================
 */

#ifndef _ROSNLIB_ETH_H_
#define _ROSNLIB_ETH_H_

#define ROSNLIB_ETH_ADDRLEN 6   /* Ethernet address length */

typedef struct rosn_ethhdr rosn_ethhdr;     /* Ethernet Header              */
struct rosn_ethhdr {
    uint8_t addrdst[ROSNLIB_ETH_ADDRLEN];   /* Ethernet Destination Address */
    uint8_t addrsrc[ROSNLIB_ETH_ADDRLEN];   /* Ethernet Source Address      */
    uint16_t ethtype;                       /* Ethernet Ether Type          */
};

uint16_t rosn_prots_eth_getethtype(const u_char *pkt);              /* Get EtherType */
void rosn_prots_eth_handle(const u_char *pkt, uint32_t pktlen);     /* Handle Ethernet protocol */

#endif
