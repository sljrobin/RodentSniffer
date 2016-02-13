/*
 * =======================================================================================
 *
 *       Filename: udp.h
 *    Description: UDP handling
 *       Compiler: gcc
 *         Author: Simon L. J. Robin | https://sljrobin.org
 *        Created: 2015-04-24 12:27:32
 *       Modified: 2016-02-13 13:40:24
 *
 * =======================================================================================
 */

#ifndef _ROSNLIB_UDP_H_
#define _ROSNLIB_UDP_H_

typedef struct rosn_udphdr rosn_udphdr;         /* UDP Header           */
struct rosn_udphdr {
    uint16_t portsrc;                           /* UDP Source Port      */
    uint16_t portdst;                           /* UDP Destination Port */
    uint16_t len;                               /* UDP Length           */
    uint16_t csum;                              /* UDP Checksum         */
};

void rosn_prots_udp_handle(const u_char *pkt, uint32_t pktlen);     /* Handle UDP */
void rosn_prots_udp_payload(const u_char *pkt, int sizehdr);        /* Print payload of a UDP packet */

#endif
