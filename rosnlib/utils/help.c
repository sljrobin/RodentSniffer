/*
 * =======================================================================================
 *
 *       Filename: help.c
 *    Description: Help of the program
 *       Compiler: gcc
 *         Author: Simon L. J. Robin | https://sljrobin.org
 *        Created: 2015-04-30 10:40:12
 *       Modified: 2016-02-13 13:43:01
 *
 * =======================================================================================
 */

#include <stdio.h>

#include "clrprnt.h"
#include "help.h"


/** 
 * rosn_utils_help_args()
 * 
 * Print help for Arguments
 */
void rosn_utils_help_args(void)
{
    rosn_clrset ptargs_arg; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptargs_arg), ROSN_CLR_WHITE), ROSN_ATTR_NONE);     /* Argument */
    rosn_clrset ptargs_warn; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptargs_warn), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);  /* Warning  */

    printf("\nUsage\n");
    cprintf(&ptargs_arg, "\t./rosn -h\n");                                                                            /* Usage -h                           */
    cprintf(&ptargs_arg, "\t./rosn -l\n");                                                                            /* Usage -l                           */
    cprintf(&ptargs_arg, "\t./rosn -p -f\"<filter>\" -s <device>\n");                                                 /* Usage -p -f "<filter>" -s <device> */
    cprintf(&ptargs_arg, "\n\t-f \"<filter>\""); printf(": "); printf("add a filter with the pcap filter syntax");    /* -f                                 */
    cprintf(&ptargs_arg, "\n\t-h"); printf(": "); printf("print this help");                                          /* -h                                 */
    cprintf(&ptargs_arg, "\n\t-l"); printf(": "); printf("list the available devices");                               /* -l                                 */
    cprintf(&ptargs_arg, "\n\t-p"); printf(": "); printf("enable the Promiscuous mode (disabled by default)");        /* -p                                 */
    cprintf(&ptargs_arg, "\n\t-s <device>"); printf(": "); printf("indicate the device to open");                     /* -s                                 */

    cprintf(&ptargs_warn, "\n\n\tThe order of the options matters");
    printf("\n\t\t1. "); cprintf(&ptargs_arg, "-p");
    printf("\n\t\t2. "); cprintf(&ptargs_arg, "-f \"<filter>\"");
    printf("\n\t\t3. "); cprintf(&ptargs_arg, "-s <device>");
}


/** 
 * rosn_utils_help_arp()
 * 
 * Print help for ARP
 */
void rosn_utils_help_arp(void)
{
    rosn_clrset ptarp_typehdwr; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptarp_typehdwr), ROSN_CLR_GREEN), ROSN_ATTR_NONE);             /* ARP Hardware Type           */
    rosn_clrset ptarp_typeprot; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptarp_typeprot), ROSN_CLR_GREEN), ROSN_ATTR_NONE);             /* ARP Protocol Type           */
    rosn_clrset ptarp_lenaddrhdwr; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptarp_lenaddrhdwr), ROSN_CLR_MAGENTA), ROSN_ATTR_NONE);     /* ARP Hardware Address length */
    rosn_clrset ptarp_lenaddrprot; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptarp_lenaddrprot), ROSN_CLR_MAGENTA), ROSN_ATTR_NONE);     /* ARP Protocol Address length */
    rosn_clrset ptarp_op; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptarp_op), ROSN_CLR_BLUE), ROSN_ATTR_NONE);                          /* ARP Operation               */
    rosn_clrset ptarp_addrhdwrsndr; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptarp_addrhdwrsndr), ROSN_CLR_BLUE), ROSN_ATTR_NONE);      /* ARP Sender Hardware Address */
    rosn_clrset ptarp_addripsndr; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptarp_addripsndr), ROSN_CLR_BLUE), ROSN_ATTR_NONE);          /* ARP Sender IP Address       */
    rosn_clrset ptarp_addrhdwrtrgt; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptarp_addrhdwrtrgt), ROSN_CLR_CYAN), ROSN_ATTR_NONE);      /* ARP Target Hardware Address */
    rosn_clrset ptarp_addriptrgt; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptarp_addriptrgt), ROSN_CLR_CYAN), ROSN_ATTR_NONE);          /* ARP Target IP Address       */

    printf("\nARP  ");
    printf("["); cprintf(&ptarp_typehdwr, "01"); printf("]");       /* ARP Hardware Type           */
    printf("["); cprintf(&ptarp_typeprot, "02"); printf("]");       /* ARP Protocol Type           */
    printf("["); cprintf(&ptarp_lenaddrhdwr, "03"); printf("]");    /* ARP Hardware Address length */
    printf("["); cprintf(&ptarp_lenaddrprot, "04"); printf("]");    /* ARP Protocol Address length */
    printf("["); cprintf(&ptarp_op, "05"); printf("]");             /* ARP Operation               */
    printf("["); cprintf(&ptarp_addrhdwrsndr, "06"); printf("]");   /* ARP Sender Hardware Address */
    printf("["); cprintf(&ptarp_addripsndr, "07"); printf("]");     /* ARP Sender IP Address       */
    printf("["); cprintf(&ptarp_addrhdwrtrgt, "08"); printf("]");   /* ARP Target Hardware Address */
    printf("["); cprintf(&ptarp_addriptrgt, "09"); printf("]");     /* ARP Target IP Address       */

    printf("\n\t- ["); cprintf(&ptarp_typehdwr, "01"); printf("] -> ["); cprintf(&ptarp_typehdwr, "hardware type"); printf("]");                    /* ARP Hardware Type           */
    printf("\n\t- ["); cprintf(&ptarp_typeprot, "02"); printf("] -> ["); cprintf(&ptarp_typeprot, "protocol type"); printf("]");                    /* ARP Protocol Type           */
    printf("\n\t- ["); cprintf(&ptarp_lenaddrhdwr, "03"); printf("] -> ["); cprintf(&ptarp_lenaddrhdwr, "hardware address length"); printf("]");    /* ARP Hardware Address length */
    printf("\n\t- ["); cprintf(&ptarp_lenaddrprot, "04"); printf("] -> ["); cprintf(&ptarp_lenaddrprot, "protocol address length"); printf("]");    /* ARP Protocol Address length */
    printf("\n\t- ["); cprintf(&ptarp_op, "05"); printf("] -> ["); cprintf(&ptarp_op, "operation"); printf("]");                                    /* ARP Operation               */
    printf("\n\t- ["); cprintf(&ptarp_addrhdwrsndr, "06"); printf("] -> ["); cprintf(&ptarp_addrhdwrsndr, "sender hardware address"); printf("]");  /* ARP Sender Hardware Address */
    printf("\n\t- ["); cprintf(&ptarp_addripsndr, "07"); printf("] -> ["); cprintf(&ptarp_addripsndr, "sender ip address"); printf("]");            /* ARP Sender IP Address       */
    printf("\n\t- ["); cprintf(&ptarp_addrhdwrtrgt, "08"); printf("] -> ["); cprintf(&ptarp_addrhdwrtrgt, "target hardware address"); printf("]");  /* ARP Target Hardware Address */
    printf("\n\t- ["); cprintf(&ptarp_addriptrgt, "09"); printf("] -> ["); cprintf(&ptarp_addriptrgt, "target ip address"); printf("]");            /* ARP Target IP Address       */
}


/** 
 * rosn_utils_help_eth()
 * 
 * Print help for Ethernet protocol
 */
void rosn_utils_help_eth(void)
{
    rosn_clrset pteth_addrdst; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pteth_addrdst), ROSN_CLR_CYAN), ROSN_ATTR_NONE);    /* Ethernet Destination Address */ 
    rosn_clrset pteth_addrsrc; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pteth_addrsrc), ROSN_CLR_BLUE), ROSN_ATTR_NONE);    /* Ethernet Source Address      */
    rosn_clrset pteth_ethtype; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pteth_ethtype), ROSN_CLR_GREEN), ROSN_ATTR_NONE);   /* Ethernet Ether Type          */

    printf("\n\nEthernet  ");
    printf("["); cprintf(&pteth_addrdst, "01"); printf("]");    /* Ethernet Destination Address */
    printf("["); cprintf(&pteth_addrsrc, "02"); printf("]");    /* Ethernet Source Address      */
    printf("["); cprintf(&pteth_ethtype, "03"); printf("]");    /* Ethernet Ether Type          */

    printf("\n\t- ["); cprintf(&pteth_addrdst, "01"); printf("] -> ["); cprintf(&pteth_addrdst, "destination address"); printf("]");    /* Ethernet Destination Address */
    printf("\n\t- ["); cprintf(&pteth_addrsrc, "02"); printf("] -> ["); cprintf(&pteth_addrsrc, "source address"); printf("]");         /* Ethernet Source Address      */
    printf("\n\t- ["); cprintf(&pteth_ethtype, "03"); printf("] -> ["); cprintf(&pteth_ethtype, "ethertype"); printf("]");              /* Ethernet Ether Type          */
}


/** 
 * rosn_utils_help_full()
 * 
 * Print full help
 */
void rosn_utils_help_full(void)
{
    rosn_clrset ptfull_header; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptfull_header), ROSN_CLR_WHITE), ROSN_ATTR_NONE);   /* Header */

    /* Arguments */
    cprintf(&ptfull_header, "\n--------------------------------------------------------------------------------");
    cprintf(&ptfull_header, "\nArguments");
    cprintf(&ptfull_header, "\n--------------------------------------------------------------------------------");
    rosn_utils_help_args();

    /* Protocols */
    cprintf(&ptfull_header, "\n\n--------------------------------------------------------------------------------");
    cprintf(&ptfull_header, "\nProtocols");
    cprintf(&ptfull_header, "\n--------------------------------------------------------------------------------");
    rosn_utils_help_arp();
    rosn_utils_help_eth();
    rosn_utils_help_icmp();
    rosn_utils_help_ipv4();
    rosn_utils_help_ipv6();
    rosn_utils_help_tcp();
    rosn_utils_help_udp();
    printf("\n");
}


/** 
 * rosn_utils_help_icmp()
 * 
 * Print help for ICMP
 */
void rosn_utils_help_icmp(void)
{
    rosn_clrset pticmp_type; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pticmp_type), ROSN_CLR_GREEN), ROSN_ATTR_NONE);   /* ICMP Type       */
    rosn_clrset pticmp_code; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pticmp_code), ROSN_CLR_BLUE), ROSN_ATTR_NONE);    /* ICMP Code       */
    rosn_clrset pticmp_csum; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pticmp_csum), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);  /* ICMP Checksum   */
    rosn_clrset pticmp_id; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pticmp_id), ROSN_CLR_RED), ROSN_ATTR_NONE);         /* ICMP Identifier */
    rosn_clrset pticmp_seq; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pticmp_seq), ROSN_CLR_CYAN), ROSN_ATTR_NONE);      /* ICMP Sequence   */

    printf("\n\nICMP  ");
    printf("["); cprintf(&pticmp_type, "01"); printf("]");  /* ICMP Type       */
    printf("["); cprintf(&pticmp_code, "02"); printf("]");  /* ICMP Code       */
    printf("["); cprintf(&pticmp_csum, "03"); printf("]");  /* ICMP Checksum   */
    printf("["); cprintf(&pticmp_id, "04"); printf("]");    /* ICMP Identifier */
    printf("["); cprintf(&pticmp_seq, "05"); printf("]");   /* ICMP Sequence   */

    printf("\n\t- ["); cprintf(&pticmp_type, "01"); printf("] -> ["); cprintf(&pticmp_type, "type"); printf("]");       /* ICMP Type       */
    printf("\n\t- ["); cprintf(&pticmp_code, "02"); printf("] -> ["); cprintf(&pticmp_code, "code"); printf("]");       /* ICMP Code       */
    printf("\n\t- ["); cprintf(&pticmp_csum, "03"); printf("] -> ["); cprintf(&pticmp_csum, "checksum"); printf("]");   /* ICMP Checksum   */
    printf("\n\t- ["); cprintf(&pticmp_id, "04"); printf("] -> ["); cprintf(&pticmp_id, "identifier"); printf("]");     /* ICMP Identifier */
    printf("\n\t- ["); cprintf(&pticmp_seq, "05"); printf("] -> ["); cprintf(&pticmp_seq, "sequence"); printf("]");     /* ICMP Sequence   */
}


/** 
 * rosn_utils_help_ipv4()
 * 
 * Print help for IPv4
 */
void rosn_utils_help_ipv4(void)
{
    rosn_clrset ptipv4_v; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv4_v), ROSN_CLR_GREEN), ROSN_ATTR_NONE);             /* IPv4 Version             */
    rosn_clrset ptipv4_hlen; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv4_hlen), ROSN_CLR_MAGENTA), ROSN_ATTR_NONE);     /* IPv4 Header length       */
    rosn_clrset ptipv4_tos; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv4_tos), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);        /* IPv4 Type Of Service     */
    rosn_clrset ptipv4_tlen; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv4_tlen), ROSN_CLR_MAGENTA), ROSN_ATTR_NONE);     /* IPv4 Total length        */
    rosn_clrset ptipv4_id; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv4_id), ROSN_CLR_RED), ROSN_ATTR_NONE);             /* IPv4 Identification      */
    rosn_clrset ptipv4_foff; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv4_foff), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);      /* IPv4 Fragment Offset     */
    rosn_clrset ptipv4_ttl; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv4_ttl), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);        /* IPv4 Time To Live        */
    rosn_clrset ptipv4_prot; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv4_prot), ROSN_CLR_GREEN), ROSN_ATTR_NONE);       /* IPv4 Protocol            */
    rosn_clrset ptipv4_csum; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv4_csum), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);      /* IPv4 Checksum            */
    rosn_clrset ptipv4_srcaddr; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv4_srcaddr), ROSN_CLR_BLUE), ROSN_ATTR_NONE);  /* IPv4 Source Address      */
    rosn_clrset ptipv4_dstaddr; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv4_dstaddr), ROSN_CLR_CYAN), ROSN_ATTR_NONE);  /* IPv4 Destination Address */

    printf("\n\nIPv4  ");
    printf("["); cprintf(&ptipv4_v, "01"); printf("]");           /* IPv4 Version             */
    printf("["); cprintf(&ptipv4_hlen, "02"); printf("]");        /* IPv4 Header length       */
    printf("["); cprintf(&ptipv4_tos, "03"); printf("]");         /* IPv4 Type Of Service     */
    printf("["); cprintf(&ptipv4_tlen, "04"); printf("]");        /* IPv4 Total length        */
    printf("["); cprintf(&ptipv4_id, "05"); printf("]");          /* IPv4 Identification      */
    printf("["); cprintf(&ptipv4_foff, "06"); printf("]");        /* IPv4 Fragment Offset     */
    printf("["); cprintf(&ptipv4_ttl, "07"); printf("]");         /* IPv4 Time To Live        */
    printf("["); cprintf(&ptipv4_prot, "08"); printf("]");        /* IPv4 Protocol            */
    printf("["); cprintf(&ptipv4_csum, "09"); printf("]");        /* IPv4 Checksum            */
    printf("["); cprintf(&ptipv4_srcaddr, "10"); printf("]");     /* IPv4 Source Address      */
    printf("["); cprintf(&ptipv4_dstaddr, "11"); printf("]");     /* IPv4 Destination Address */

    printf("\n\t- ["); cprintf(&ptipv4_v, "01"); printf("] -> ["); cprintf(&ptipv4_v, "version"); printf("]");                          /* IPv4 Version             */
    printf("\n\t- ["); cprintf(&ptipv4_hlen, "02"); printf("] -> ["); cprintf(&ptipv4_hlen, "header length"); printf("]");              /* IPv4 Header length       */
    printf("\n\t- ["); cprintf(&ptipv4_tos, "03"); printf("] -> ["); cprintf(&ptipv4_tos, "type of service"); printf("]");              /* IPv4 Type Of Service     */
    printf("\n\t- ["); cprintf(&ptipv4_tlen, "04"); printf("] -> ["); cprintf(&ptipv4_tlen, "total length"); printf("]");               /* IPv4 Total length        */
    printf("\n\t- ["); cprintf(&ptipv4_id, "05"); printf("] -> ["); cprintf(&ptipv4_id, "identification"); printf("]");                 /* IPv4 Identification      */
    printf("\n\t- ["); cprintf(&ptipv4_foff, "06"); printf("] -> ["); cprintf(&ptipv4_foff, "fragment offset"); printf("]");            /* IPv4 Fragment Offset     */
    printf("\n\t- ["); cprintf(&ptipv4_ttl, "07"); printf("] -> ["); cprintf(&ptipv4_ttl, "time to live"); printf("]");                 /* IPv4 Time To Live        */
    printf("\n\t- ["); cprintf(&ptipv4_prot, "08"); printf("] -> ["); cprintf(&ptipv4_prot, "protocol"); printf("]");                   /* IPv4 Protocol            */
    printf("\n\t- ["); cprintf(&ptipv4_csum, "09"); printf("] -> ["); cprintf(&ptipv4_csum, "checksum"); printf("]");                   /* IPv4 Checksum            */
    printf("\n\t- ["); cprintf(&ptipv4_srcaddr, "10"); printf("] -> ["); cprintf(&ptipv4_srcaddr, "source address"); printf("]");       /* IPv4 Source Address      */
    printf("\n\t- ["); cprintf(&ptipv4_dstaddr, "11"); printf("] -> ["); cprintf(&ptipv4_dstaddr, "destination address"); printf("]");  /* IPv4 Destination Address */
}


/** 
 * rosn_utils_help_ipv6()
 * 
 * Print help for IPv6
 */
void rosn_utils_help_ipv6(void)
{

    rosn_clrset ptipv6_v; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv6_v), ROSN_CLR_GREEN), ROSN_ATTR_NONE);             /* IPv6 Version             */
    rosn_clrset ptipv6_tc; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv6_tc), ROSN_CLR_RED), ROSN_ATTR_NONE);             /* IPv6 Traffic Class       */
    rosn_clrset ptipv6_fl; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv6_fl), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);          /* IPv6 Flow Label          */
    rosn_clrset ptipv6_lenp; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv6_lenp), ROSN_CLR_MAGENTA), ROSN_ATTR_NONE);     /* IPv6 Payload length      */
    rosn_clrset ptipv6_nhdr; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv6_nhdr), ROSN_CLR_GREEN), ROSN_ATTR_NONE);       /* IPv6 Next Header         */
    rosn_clrset ptipv6_hlmt; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv6_hlmt), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);      /* IPv6 Hop Limit           */
    rosn_clrset ptipv6_srcaddr; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv6_srcaddr), ROSN_CLR_BLUE), ROSN_ATTR_NONE);  /* IPv6 Source Address      */
    rosn_clrset ptipv6_dstaddr; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptipv6_dstaddr), ROSN_CLR_CYAN), ROSN_ATTR_NONE);  /* IPv6 Destination Address */

    printf("\n\nIPv6  ");
    printf("["); cprintf(&ptipv6_v, "01"); printf("]");         /* IPv6 Version             */
    printf("["); cprintf(&ptipv6_tc, "02"); printf("]");        /* IPv6 Traffic Class       */
    printf("["); cprintf(&ptipv6_fl, "03"); printf("]");        /* IPv6 Flow Label          */
    printf("["); cprintf(&ptipv6_lenp, "04"); printf("]");      /* IPv6 Payload length      */
    printf("["); cprintf(&ptipv6_nhdr, "05"); printf("]");      /* IPv6 Next Header         */
    printf("["); cprintf(&ptipv6_hlmt, "06"); printf("]");      /* IPv6 Hop Limit           */
    printf("["); cprintf(&ptipv6_srcaddr, "07"); printf("]");   /* IPv6 Source Address      */
    printf("["); cprintf(&ptipv6_dstaddr, "08"); printf("]");   /* IPv6 Destination Address */

    printf("\n\t- ["); cprintf(&ptipv6_v, "01"); printf("] -> ["); cprintf(&ptipv6_v, "version"); printf("]");                          /* IPv6 Version             */
    printf("\n\t- ["); cprintf(&ptipv6_tc, "02"); printf("] -> ["); cprintf(&ptipv6_tc, "traffic class"); printf("]");                  /* IPv6 Traffic Class       */
    printf("\n\t- ["); cprintf(&ptipv6_fl, "03"); printf("] -> ["); cprintf(&ptipv6_fl, "flow label"); printf("]");                     /* IPv6 Flow Label          */
    printf("\n\t- ["); cprintf(&ptipv6_lenp, "04"); printf("] -> ["); cprintf(&ptipv6_lenp, "payload length"); printf("]");             /* IPv6 Payload length      */
    printf("\n\t- ["); cprintf(&ptipv6_nhdr, "05"); printf("] -> ["); cprintf(&ptipv6_nhdr, "next header"); printf("]");                /* IPv6 Next Header         */
    printf("\n\t- ["); cprintf(&ptipv6_hlmt, "06"); printf("] -> ["); cprintf(&ptipv6_hlmt, "hop limit"); printf("]");                  /* IPv6 Hop Limit           */
    printf("\n\t- ["); cprintf(&ptipv6_srcaddr, "07"); printf("] -> ["); cprintf(&ptipv6_srcaddr, "source address"); printf("]");       /* IPv6 Source Address      */
    printf("\n\t- ["); cprintf(&ptipv6_dstaddr, "08"); printf("] -> ["); cprintf(&ptipv6_dstaddr, "destination address"); printf("]");  /* IPv6 Destination Address */
}


/** 
 * rosn_utils_help_tcp()
 * 
 * Print help for TCP
 */
void rosn_utils_help_tcp(void)
{
    rosn_clrset pttcp_portsrc; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pttcp_portsrc), ROSN_CLR_BLUE), ROSN_ATTR_NONE);    /* TCP Source Port           */
    rosn_clrset pttcp_portdst; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pttcp_portdst), ROSN_CLR_CYAN), ROSN_ATTR_NONE);    /* TCP Destination Port      */
    rosn_clrset pttcp_seq; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pttcp_seq), ROSN_CLR_RED), ROSN_ATTR_NONE);             /* TCP Sequence number       */
    rosn_clrset pttcp_ack; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pttcp_ack), ROSN_CLR_RED), ROSN_ATTR_NONE);             /* TCP Acknowledgment number */
    rosn_clrset pttcp_doff; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pttcp_doff), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);        /* TCP Data Offset           */
    rosn_clrset pttcp_flgs; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pttcp_flgs), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);        /* TCP Flags                 */
    rosn_clrset pttcp_wins; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pttcp_wins), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);        /* TCP Window Size           */
    rosn_clrset pttcp_csum; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pttcp_csum), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);        /* TCP Checksum              */
    rosn_clrset pttcp_uptr; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pttcp_uptr), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);        /* TCP Urgent Pointer        */

    printf("\n\nTCP  ");
    printf("["); cprintf(&pttcp_portsrc, "01"); printf("]");  /* TCP Source Port           */
    printf("["); cprintf(&pttcp_portdst, "02"); printf("]");  /* TCP Destination Port      */
    printf("["); cprintf(&pttcp_seq, "03"); printf("]");      /* TCP Sequence number       */
    printf("["); cprintf(&pttcp_ack, "04"); printf("]");      /* TCP Acknowledgment number */
    printf("["); cprintf(&pttcp_doff, "05"); printf("]");     /* TCP Data Offset           */
    printf("["); cprintf(&pttcp_flgs, "06"); printf("]");     /* TCP Flags                 */
    printf("["); cprintf(&pttcp_wins, "07"); printf("]");     /* TCP Window Size           */
    printf("["); cprintf(&pttcp_csum, "08"); printf("]");     /* TCP Checksum              */
    printf("["); cprintf(&pttcp_uptr, "09"); printf("]");     /* TCP Urgent Pointer        */

    printf("\n\t- ["); cprintf(&pttcp_portsrc, "01"); printf("] -> ["); cprintf(&pttcp_portsrc, "source port"); printf("]");        /* TCP Source Port           */
    printf("\n\t- ["); cprintf(&pttcp_portdst, "02"); printf("] -> ["); cprintf(&pttcp_portdst, "destination port"); printf("]");   /* TCP Destination Port      */
    printf("\n\t- ["); cprintf(&pttcp_seq, "03"); printf("] -> ["); cprintf(&pttcp_seq, "sequence number"); printf("]");            /* TCP Sequence number       */
    printf("\n\t- ["); cprintf(&pttcp_ack, "04"); printf("] -> ["); cprintf(&pttcp_ack, "acknowledgment number"); printf("]");      /* TCP Acknowledgment number */
    printf("\n\t- ["); cprintf(&pttcp_doff, "05"); printf("] -> ["); cprintf(&pttcp_doff, "data offset"); printf("]");              /* TCP Data Offset           */
    printf("\n\t- ["); cprintf(&pttcp_flgs, "06"); printf("] -> ["); cprintf(&pttcp_flgs, "flags"); printf("]");                    /* TCP Flags                 */
    printf("\n\t- ["); cprintf(&pttcp_wins, "07"); printf("] -> ["); cprintf(&pttcp_wins, "window size"); printf("]");              /* TCP Window Size           */
    printf("\n\t- ["); cprintf(&pttcp_csum, "08"); printf("] -> ["); cprintf(&pttcp_csum, "checksum"); printf("]");                 /* TCP Checksum              */
    printf("\n\t- ["); cprintf(&pttcp_uptr, "09"); printf("] -> ["); cprintf(&pttcp_uptr, "urgent pointer"); printf("]");           /* TCP Urgent Pointer        */
}


/** 
 * rosn_utils_help_udp()
 * 
 * Print help for UDP
 */
void rosn_utils_help_udp(void)
{
    rosn_clrset ptudp_portdst; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptudp_portdst), ROSN_CLR_BLUE), ROSN_ATTR_NONE);    /* UDP Source Port      */
    rosn_clrset ptudp_portsrc; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptudp_portsrc), ROSN_CLR_CYAN), ROSN_ATTR_NONE);    /* UDP Destination Port */
    rosn_clrset ptudp_len; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptudp_len), ROSN_CLR_MAGENTA), ROSN_ATTR_NONE);         /* UDP Length           */
    rosn_clrset ptudp_csum; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptudp_csum), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);        /* UDP Checksum         */

    printf("\n\nUDP  ");
    printf("["); cprintf(&ptudp_portdst, "01"); printf("]");     /* UDP Source Port      */
    printf("["); cprintf(&ptudp_portsrc, "02"); printf("]");     /* UDP Destination Port */
    printf("["); cprintf(&ptudp_len, "03"); printf("]");         /* UDP Length           */
    printf("["); cprintf(&ptudp_csum, "04"); printf("]");        /* UDP Checksum         */

    printf("\n\t- ["); cprintf(&ptudp_portdst, "01"); printf("] -> ["); cprintf(&ptudp_portdst, "source port"); printf("]");        /* UDP Source Port      */
    printf("\n\t- ["); cprintf(&ptudp_portsrc, "02"); printf("] -> ["); cprintf(&ptudp_portsrc, "destination port"); printf("]");   /* UDP Destination Port */
    printf("\n\t- ["); cprintf(&ptudp_len, "03"); printf("] -> ["); cprintf(&ptudp_len, "length"); printf("]");                     /* UDP Length           */
    printf("\n\t- ["); cprintf(&ptudp_csum, "04"); printf("] -> ["); cprintf(&ptudp_csum, "checksum"); printf("]");                 /* UDP Checksum         */
}
