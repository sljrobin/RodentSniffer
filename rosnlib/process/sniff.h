/*
 * =======================================================================================
 *
 *       Filename: sniff.h
 *    Description: Sniffing functions
 *       Compiler: gcc
 *         Author: Simon L. J. Robin | https://sljrobin.org
 *        Created: 2015-04-30 15:27:53
 *       Modified: 2016-02-13 13:37:28
 *
 * =======================================================================================
 */

#ifndef _ROSNLIB_SNIFF_H_
#define _ROSNLIB_SNIFF_H_

#define ROSN_MAX_CAPTURED_BYTES 65536   /* Max bytes to capture */
#define ROSN_MAX_LENGTH_DEV 256         /* Max length for a device's name */
#define ROSN_MAX_LENGTH_FLTR 256        /* Max length for a filter */
#define ROSN_PROMISCUOUS_OFF 0          /* Promiscuous mode disabled */
#define ROSN_PROMISCUOUS_ON 1           /* Promiscuous mode enabled */
#define ROSN_WAIT_COPY 512              /* Wait (in ms) before copying the information to User space */

void rosn_process_sniff_capture(u_char *args, const struct pcap_pkthdr *pkthdr, const u_char *pkt);     /* Capture function for sniffing */
void rosn_process_sniff_loop(char *dev, char *fltr, int mod);                                           /* Loop function for sniffing */

#endif
