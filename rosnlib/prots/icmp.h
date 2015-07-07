/*
 * =======================================================================================
 *
 *       Filename: icmp.h
 *    Description:
 *       Compiler: gcc
 *         Author: Simon L. J. Robin - http://sljrobin.com
 *        Created: 2015-04-30 15:27:53
 *       Modified: 2015-07-07 11:15:51
 *
 * =======================================================================================
 */

#ifndef _ROSNLIB_ICMP_H_
#define _ROSNLIB_ICMP_H_

typedef struct rosn_icmphdr rosn_icmphdr;
struct rosn_icmphdr {
    uint8_t type;                /* ICMP Type       */
    uint8_t code;                /* ICMP Code       */
    uint16_t csum;               /* ICMP Checksum   */
    uint16_t id;                 /* ICMP Identifier */
    uint16_t seq;                /* ICMP Sequence   */
};
    
void rosn_prots_icmp_handle(const u_char *pkt, uint32_t pktlen);     /* Handle ICMP */
#endif
