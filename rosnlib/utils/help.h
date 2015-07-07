/*
 * =======================================================================================
 *
 *       Filename: help.h
 *    Description:
 *       Compiler: gcc
 *         Author: Simon L. J. Robin - http://sljrobin.com
 *        Created: 2015-04-30 10:38:33
 *       Modified: 2015-07-07 15:07:40
 *
 * =======================================================================================
 */

#ifndef _ROSNLIB_HELP_H_
#define _ROSNLIB_HELP_H_

void rosn_utils_help_args(void);    /* Print help for Arguments */
void rosn_utils_help_arp(void);     /* Print help for ARP */
void rosn_utils_help_eth(void);     /* Print help for Ethernet */
void rosn_utils_help_full(void);    /* Print full help */
void rosn_utils_help_icmp(void);    /* Print help for ICMP */
void rosn_utils_help_ipv4(void);    /* Print help for IPv4 */
void rosn_utils_help_ipv6(void);    /* Print help for IPv6 */
void rosn_utils_help_tcp(void);     /* Print help for TCP */
void rosn_utils_help_udp(void);     /* Print help for UDP */

#endif
