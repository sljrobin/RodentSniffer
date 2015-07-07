/*
 * =======================================================================================
 *
 *       Filename: pkttime.h
 *    Description:
 *       Compiler: gcc
 *         Author: Simon L. J. Robin - http://sljrobin.com
 *        Created: 2015-04-30 10:38:33
 *       Modified: 2015-04-30 15:57:13
 *
 * =======================================================================================
 */

#ifndef _ROSNLIB_PKTTIME_H_
#define _ROSNLIB_PKTTIME_H_

/* Get and print the date of a packet */
void rosn_utils_pkttime_date(const struct pcap_pkthdr *pkthdr);
/* Get and print the hour of a packet */
void rosn_utils_pkttime_hour(const struct pcap_pkthdr *pkthdr);
#endif
