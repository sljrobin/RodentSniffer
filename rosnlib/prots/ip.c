/*
 * =======================================================================================
 *
 *       Filename: ip.c
 *    Description: IP handling
 *       Compiler: gcc
 *         Author: Simon L. J. Robin - http://sljrobin.com
 *        Created: 2015-04-30 15:28:41
 *       Modified: 2015-07-08 10:51:24
 *
 * =======================================================================================
 */

#include <arpa/inet.h>
#include <pcap.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "../utils/clrprnt.h"
#include "eth.h"
#include "ip.h"


/** 
 * rosn_prots_ipv4_getprot()
 * 
 * Get IPv4 protocol
 *      pkt: the packet
 * Return IPv4 protocol
 */
uint8_t rosn_prots_ipv4_getprot(const u_char *pkt)
{
    struct rosn_ipv4hdr *ipv4hdr;   /* IPv4 Header */
    uint8_t ipprot;                 /* IPv4 Protocol */

    ipv4hdr = (struct rosn_ipv4hdr *)(pkt + sizeof(struct rosn_ethhdr));    /* Pointing to the IPv4 Header */
    ipprot = ipv4hdr->prot;                                                 /* Getting the protocol */

    return ipprot;
}


/** 
 * rosn_prots_ipv4_handle()
 * 
 * Handle IPv4
 *      pkt: the packet
 *      pktlen: packet length
 */
void rosn_prots_ipv4_handle(const u_char *pkt, uint32_t pktlen)
{
    char *addrdst = NULL;                       /* Destination Address */
    char *addrsrc = NULL;                       /* Source Address */
    char buf_addrdst[INET_ADDRSTRLEN] = {0};    /* Buffer for the Destination Address */
    char buf_addrsrc[INET_ADDRSTRLEN] = {0};    /* Buffer for the Source Address */
    struct rosn_ipv4hdr *ipv4hdr;               /* IPv4 Header */

    /* Printers */
    rosn_clrset ptipv4;
    rosn_clrset ptipv4_addrdst;
    rosn_clrset ptipv4_addrsrc;
    rosn_clrset ptipv4_csum;
    rosn_clrset ptipv4_foff;
    rosn_clrset ptipv4_hlen;
    rosn_clrset ptipv4_id;
    rosn_clrset ptipv4_prot;
    rosn_clrset ptipv4_tlen;
    rosn_clrset ptipv4_tos;
    rosn_clrset ptipv4_ttl;
    rosn_clrset ptipv4_v;
    rosn_clrset ptsep;

    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_init(&ptipv4), ROSN_ATTR_UNDERLINE);                                              /* IPv4 */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv4_addrdst), ROSN_CLR_CYAN), ROSN_ATTR_NONE);  /* IPv4 Destination Address */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv4_addrsrc), ROSN_CLR_BLUE), ROSN_ATTR_NONE);  /* IPv4 Source Address */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv4_csum), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);   /* IPv4 Checksum */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv4_foff), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);   /* IPv4 Fragment Offset Field */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv4_hlen), ROSN_CLR_MAGENTA), ROSN_ATTR_NONE);  /* IPv4 Header length */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv4_id), ROSN_CLR_RED), ROSN_ATTR_NONE);        /* IPv4 Identification */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv4_prot), ROSN_CLR_GREEN), ROSN_ATTR_NONE);    /* IPv4 Protocol */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv4_tlen), ROSN_CLR_MAGENTA), ROSN_ATTR_NONE);  /* IPv4 Total length */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv4_tos), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);    /* IPv4 Type Of Service */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv4_ttl), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);    /* IPv4 Time To Live */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv4_v), ROSN_CLR_GREEN), ROSN_ATTR_NONE);       /* IPv4 Version */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptsep), ROSN_CLR_WHITE), ROSN_ATTR_NONE);          /* Separator */

    ipv4hdr = (struct rosn_ipv4hdr *)(pkt + sizeof(struct rosn_ethhdr));    /* Pointing to the IPv4 Header */

    addrdst = strndup(inet_ntop(AF_INET, &(ipv4hdr->addrdst), buf_addrdst, sizeof(buf_addrdst)), sizeof(buf_addrdst));  /* Duplicating the Destination Address into its buffer */
    addrsrc = strndup(inet_ntop(AF_INET, &(ipv4hdr->addrsrc), buf_addrsrc, sizeof(buf_addrsrc)), sizeof(buf_addrsrc));  /* Duplicating the Source Address into its buffer */

    cprintf(&ptsep, "¤"); printf("["); cprintf(&ptipv4, "IPv4"); printf("]");       /* IPv4 */
    printf("["); cprintf(&ptipv4_v, "%d", ipv4hdr->v); printf("]");                 /* IPv4 Version */
    printf("["); cprintf(&ptipv4_hlen, "%d", ipv4hdr->hlen * 4); printf("]");       /* IPv4 Header length */
    printf("["); cprintf(&ptipv4_tos, "%d", ipv4hdr->tos); printf("]");             /* IPv4 Type Of Service */
    printf("["); cprintf(&ptipv4_tlen, "%d", ntohs(ipv4hdr->tlen)); printf("]");    /* IPv4 Total length */
    printf("["); cprintf(&ptipv4_id, "%d", ntohs(ipv4hdr->id)); printf("]");        /* IPv4 Identification */
    printf("["); cprintf(&ptipv4_foff, "%d", ipv4hdr->foff); printf("]");           /* IPv4 Fragment Offset Field */
    printf("["); cprintf(&ptipv4_ttl, "%d", ipv4hdr->ttl); printf("]");             /* IPv4 Time To Live */
    printf("["); cprintf(&ptipv4_prot, "%x", ipv4hdr->prot); printf("]");           /* IPv4 Protocol */
    printf("["); cprintf(&ptipv4_csum, "%d", ipv4hdr->csum); printf("]");           /* IPv4 Checksum */
    printf("["); cprintf(&ptipv4_addrsrc, "%s", addrsrc); printf("]");              /* IPv4 Source Address */
    printf("["); cprintf(&ptipv4_addrdst, "%s", addrdst); printf("]");              /* IPv4 Destination Address */
}


/** 
 * rosn_prots_ipv6_handle()
 * 
 * Handle IPv6
 *      pkt: the packet
 *      pktlen: packet length
 */
void rosn_prots_ipv6_handle(const u_char *pkt, uint32_t pktlen)
{
    char *addrdst = NULL;                       /* Destination Address */
    char *addrsrc = NULL;                       /* Source Address */
    char buf_addrdst[INET6_ADDRSTRLEN] = {0};   /* Buffer for the Destination Address */
    char buf_addrsrc[INET6_ADDRSTRLEN] = {0};   /* Buffer for the Source Address */
    struct rosn_ipv6hdr *ipv6hdr;               /* IPv6 header */

    /* Printers */
    rosn_clrset ptipv6;
    rosn_clrset ptipv6_addrdst;
    rosn_clrset ptipv6_addrsrc;
    rosn_clrset ptipv6_fl;
    rosn_clrset ptipv6_hlmt;
    rosn_clrset ptipv6_lenp;
    rosn_clrset ptipv6_nhdr;
    rosn_clrset ptipv6_tc;
    rosn_clrset ptipv6_v;
    rosn_clrset ptsep;

    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_init(&ptipv6), ROSN_ATTR_UNDERLINE);                                              /* IPv6 */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv6_addrdst), ROSN_CLR_CYAN), ROSN_ATTR_NONE);  /* IPv6 Destination Address */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv6_addrsrc), ROSN_CLR_BLUE), ROSN_ATTR_NONE);  /* IPv6 Source Address */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv6_fl), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);     /* IPv6 Flow Label */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv6_hlmt), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);   /* IPv6 Hop Limit */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv6_lenp), ROSN_CLR_MAGENTA), ROSN_ATTR_NONE);  /* IPv6 Payload length */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv6_nhdr), ROSN_CLR_GREEN), ROSN_ATTR_NONE);    /* IPv6 Next Header */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv6_tc), ROSN_CLR_RED), ROSN_ATTR_NONE);        /* IPv6 Traffic Class */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv6_v), ROSN_CLR_GREEN), ROSN_ATTR_NONE);       /* IPv6 Version */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptsep), ROSN_CLR_WHITE), ROSN_ATTR_NONE);          /* Separator */

    ipv6hdr = (struct rosn_ipv6hdr *)(pkt + sizeof(struct rosn_ethhdr));    /* Pointing to the IPv6 Header */
    
    addrdst = strndup(inet_ntop(AF_INET6, &(ipv6hdr->addrdst), buf_addrdst, sizeof(buf_addrdst)), sizeof(buf_addrdst)); /* Duplicating the Destination Address into its buffer */
    addrsrc = strndup(inet_ntop(AF_INET6, &(ipv6hdr->addrsrc), buf_addrsrc, sizeof(buf_addrsrc)), sizeof(buf_addrsrc)); /* Duplicating the Source Address into its buffer */

    cprintf(&ptsep, "¤"); printf("["); cprintf(&ptipv6, "IPv6"); printf("]");       /* IPv6 */
    printf("["); cprintf(&ptipv6_v, "%d", ipv6hdr->v); printf("]");                 /* IPv6 Version */
    printf("["); cprintf(&ptipv6_tc, "%d", ipv6hdr->tc); printf("]");               /* IPv6 Traffic Class */
    printf("["); cprintf(&ptipv6_fl, "%d", ipv6hdr->fl); printf("]");               /* IPv6 Flow Label */
    printf("["); cprintf(&ptipv6_lenp, "%d", ntohs(ipv6hdr->lenp)); printf("]");    /* IPv6 Payload length */
    printf("["); cprintf(&ptipv6_nhdr, "%d", ipv6hdr->nhdr); printf("]");           /* IPv6 Next Header */
    printf("["); cprintf(&ptipv6_hlmt, "%d", ipv6hdr->hlmt); printf("]");           /* IPv6 Hop Limit */
    printf("["); cprintf(&ptipv6_addrsrc, "%s", addrsrc); printf("]");              /* IPv6 Source Address */
    printf("["); cprintf(&ptipv6_addrdst, "%s", addrdst); printf("]");              /* IPv6 Destination Address */
}
