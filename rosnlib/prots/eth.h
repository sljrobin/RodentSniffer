/*
 * =======================================================================================
 *
 *       Filename: eth.h
 *    Description:
 *       Compiler: gcc
 *         Author: Simon L. J. Robin - http://sljrobin.com
 *        Created: 2015-04-30 15:27:53
 *       Modified: 2015-07-07 11:15:50
 *
 * =======================================================================================
 */

#ifndef _ROSNLIB_ETH_H_
#define _ROSNLIB_ETH_H_

#define ROSNLIB_ETH_ADDRLEN 6   /* Ethernet address length */

typedef struct rosn_ethhdr rosn_ethhdr;
struct rosn_ethhdr {
    uint8_t addrdst[ROSNLIB_ETH_ADDRLEN];   /* Destination Address */
    uint8_t addrsrc[ROSNLIB_ETH_ADDRLEN];   /* Source Address      */
    uint16_t ethtype;                       /* Ether Type          */
};


uint16_t rosn_prots_eth_getethtype(const u_char *pkt);              /* Get EtherType */
void rosn_prots_eth_handle(const u_char *pkt, uint32_t pktlen);     /* Handle Ethernet */
#endif
