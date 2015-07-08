/*
 * =======================================================================================
 *
 *       Filename: ip.h
 *    Description: IP handling
 *       Compiler: gcc
 *         Author: Simon L. J. Robin - http://sljrobin.com
 *        Created: 2015-04-30 15:27:53
 *       Modified: 2015-07-08 10:51:09
 *
 * =======================================================================================
 */

#ifndef _ROSNLIB_IP_H_
#define _ROSNLIB_IP_H_

typedef struct rosn_ipv4hdr rosn_ipv4hdr;   /* IPv4 Header                   */
struct rosn_ipv4hdr {
#if __BYTE_ORDER == __LITTLE_ENDIAN
    uint8_t hlen:4;                         /* IPv4 Header length            */
    uint8_t v:4;                            /* IPv4 Version                  */
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
    uint8_t v:4;                            /* IPv4 Version                  */
    uint8_t hlen:4;                         /* IPv4 Header length            */
#endif
    uint8_t tos;                            /* IPv4 Type Of Service          */
    uint16_t tlen;                          /* IPv4 Total length             */
    uint16_t id;                            /* IPv4 Identification           */
#define RF 0x8000                           /* IPv4 Flag `Reserved`          */
#define DF 0x4000                           /* IPv4 Flag `Don't Fragment`    */
#define MF 0x2000                           /* IPv4 Flag `More Fragments`    */
#define OFFMASK 0x1fff                      /* IPv4 Mask for fragmented bits */
    uint16_t foff;                          /* IPv4 Fragment Offset Field    */
    uint8_t ttl;                            /* IPv4 Time To Live             */
    uint8_t prot;                           /* IPv4 Protocol                 */
    uint16_t csum;                          /* IPv4 Checksum                 */
    struct in_addr addrsrc;                 /* IPv4 Source Address           */
    struct in_addr addrdst;                 /* IPv4 Destination Address      */
};

typedef struct rosn_ipv6hdr rosn_ipv6hdr;   /* IPv6 Header                             */
struct rosn_ipv6hdr {
#if __BYTE_ORDER == __LITTLE_ENDIAN
    uint32_t tc:4, v:4, fl:20;              /* IPv6 Traffic Class, Version, Flow Label */
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
    uint32_t v:4, tc:4, fl:20;              /* IPv6 Version, Traffic Class, Flow Label */
#endif
    uint16_t lenp;                          /* IPv6 Payload length                     */
    uint8_t nhdr;                           /* IPv6 Next Header                        */
    uint8_t hlmt;                           /* IPv6 Hop Limit                          */
    struct in6_addr addrsrc;                /* IPv6 Source Address                     */
    struct in6_addr addrdst;                /* IPv6 Destination Address                */
};

uint8_t rosn_prots_ipv4_getprot(const u_char *pkt);                 /* Get IPv4 protocol */
void rosn_prots_ipv4_handle(const u_char *pkt, uint32_t pktlen);    /* Handle IPv4 */
void rosn_prots_ipv6_handle(const u_char *pkt, uint32_t pktlen);    /* Handle IPv6 */

#endif
