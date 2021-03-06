/*
 * =======================================================================================
 *
 *       Filename: pkttime.h
 *    Description: Packet time
 *       Compiler: gcc
 *         Author: Simon L. J. Robin | https://sljrobin.org
 *        Created: 2015-04-30 10:38:33
 *       Modified: 2016-02-13 13:42:44
 *
 * =======================================================================================
 */

#ifndef _ROSNLIB_PKTTIME_H_
#define _ROSNLIB_PKTTIME_H_

void rosn_utils_pkttime_date(const struct pcap_pkthdr *pkthdr);     /* Get and print the date of a packet */
void rosn_utils_pkttime_hour(const struct pcap_pkthdr *pkthdr);     /* Get and print the hour of a packet */

#endif
