/*
 * =======================================================================================
 *
 *       Filename: dtlnk.h
 *    Description: Get the Data Link Header Type
 *       Compiler: gcc
 *         Author: Simon L. J. Robin - http://sljrobin.com
 *        Created: 2015-04-30 15:27:53
 *       Modified: 2015-07-08 09:33:18
 *
 * =======================================================================================
 */

#ifndef _ROSNLIB_DTLNK_H_
#define _ROSNLIB_DTLNK_H_

int rosn_boot_dtlnk_findhdrt(pcap_t *handle);   /* Find the Data Link Header Type */

#endif
