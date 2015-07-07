/*
 * =======================================================================================
 *
 *       Filename: udp.h
 *    Description:
 *       Compiler: gcc
 *         Author: Simon L. J. Robin - http://sljrobin.com
 *        Created: 2015-04-24 12:27:32
 *       Modified: 2015-07-07 16:10:58
 *
 * =======================================================================================
 */

#ifndef _ROSNLIB_UDP_H_
#define _ROSNLIB_UDP_H_

typedef struct rosn_udphdr rosn_udphdr;
struct rosn_udphdr {
    uint16_t portsrc;                         /* Source Port      */
    uint16_t portdst;                         /* Destination Port */
    uint16_t len;                             /* Length           */
    uint16_t csum;                            /* Checksum         */
};

void rosn_prots_udp_handle(const u_char *pkt, uint32_t pktlen);     /* Handle UDP */
void rosn_prots_udp_payload(const u_char *pkt, int sizehdr);        /* Print payload of a UDP packet */

#endif
