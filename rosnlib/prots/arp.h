/*
 * =======================================================================================
 *
 *       Filename: arp.h
 *    Description: ARP handling
 *       Compiler: gcc
 *         Author: Simon L. J. Robin | https://sljrobin.org
 *        Created: 2015-04-30 15:27:53
 *       Modified: 2016-02-13 13:41:27
 *
 * =======================================================================================
 */

#ifndef _ROSNLIB_ARP_H_
#define _ROSNLIB_ARP_H_

#define ROSNLIB_ARP_ADDRHWLEN 6   /* Hardware address length */
#define ROSNLIB_ARP_ADDRIPLEN 4   /* IP address length       */

typedef struct rosn_arphdr rosn_arphdr;             /* ARP Header                  */
struct rosn_arphdr {
    uint16_t typehdwr;                              /* ARP Hardware Type           */
    uint16_t typeprot;                              /* ARP Protocol Type           */
    uint8_t lenaddrhdwr;                            /* ARP Hardware Address length */
    uint8_t lenaddrprot;                            /* ARP Protocol Address length */
    uint16_t op;                                    /* ARP Operation               */
    uint8_t addrhdwrsndr[ROSNLIB_ARP_ADDRHWLEN];    /* ARP Sender Hardware Address */
    uint8_t addripsndr[ROSNLIB_ARP_ADDRIPLEN];      /* ARP Sender IP Address       */ 
    uint8_t addrhdwrtrgt[ROSNLIB_ARP_ADDRHWLEN];    /* ARP Target Hardware Address */
    uint8_t addriptrgt[ROSNLIB_ARP_ADDRIPLEN];      /* ARP Target IP Address       */
};

void rosn_prots_arp_handle(const u_char *pkt, uint32_t pktlen);     /* Handle ARP */

#endif
