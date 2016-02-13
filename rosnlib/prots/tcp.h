/*
 * =======================================================================================
 *
 *       Filename: tcp.h
 *    Description: TCP handling
 *       Compiler: gcc
 *         Author: Simon L. J. Robin | https://sljrobin.orgm
 *        Created: 2015-04-24 12:27:32
 *       Modified: 2016-02-13 13:40:38
 *
 * =======================================================================================
 */

#ifndef _ROSNLIB_TCP_H_
#define _ROSNLIB_TCP_H_

typedef struct rosn_tcphdr rosn_tcphdr;         /* TCP Header                */
struct rosn_tcphdr {
    uint16_t portsrc;                           /* TCP Source Port           */
    uint16_t portdst;                           /* TCP Destination Port      */
    uint32_t seq;                               /* TCP Sequence number       */
    uint32_t ack;                               /* TCP Acknowledgment number */
    uint8_t doff;                               /* TCP Data Offset           */
    uint8_t flgs;                               /* TCP Flags                 */
    uint16_t wins;                              /* TCP Window Size           */
    uint16_t csum;                              /* TCP Checksum              */
    uint16_t uptr;                              /* TCP Urgent Pointer        */
};

void rosn_prots_tcp_handle(const u_char *pkt, uint32_t pktlen); /* Handle TCP */
void rosn_prots_tcp_payload(const u_char *pkt, int sizehdr);    /* Print payload for a TCP packet */

#endif
