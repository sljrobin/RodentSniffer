/*
 * =======================================================================================
 *
 *       Filename: arp.h
 *    Description:
 *       Compiler: gcc
 *         Author: Simon L. J. Robin - http://sljrobin.com
 *        Created: 2015-04-30 15:27:53
 *       Modified: 2015-07-07 11:13:39
 *
 * =======================================================================================
 */

#ifndef _ROSNLIB_ARP_H_
#define _ROSNLIB_ARP_H_

#define ROSNLIB_ARP_ADDRHWLEN 6   /* Hardware address length */
#define ROSNLIB_ARP_ADDRIPLEN 4   /* IP address length       */

typedef struct rosn_arphdr rosn_arphdr;
struct rosn_arphdr {
    uint16_t typehdwr;                              /* Hardware Type           */
    uint16_t typeprot;                              /* Protocol Type           */
    uint8_t lenaddrhdwr;                            /* Hardware Address length */
    uint8_t lenaddrprot;                            /* Protocol Address length */
    uint16_t op;                                    /* Operation               */
    uint8_t addrhdwrsndr[ROSNLIB_ARP_ADDRHWLEN];    /* Sender Hardware Address */
    uint8_t addripsndr[ROSNLIB_ARP_ADDRIPLEN];      /* Sender IP Address       */ 
    uint8_t addrhdwrtrgt[ROSNLIB_ARP_ADDRHWLEN];    /* Target Hardware Address */
    uint8_t addriptrgt[ROSNLIB_ARP_ADDRIPLEN];      /* Target IP Address       */
};

void rosn_prots_arp_handle(const u_char *pkt, uint32_t pktlen);     /* Handle ARP */
#endif
