/*
 * =======================================================================================
 *
 *       Filename: pkttime.c
 *    Description: Packet time
 *       Compiler: gcc
 *         Author: Simon L. J. Robin | https://sljrobin.org
 *        Created: 2015-04-30 10:40:12
 *       Modified: 2016-02-13 13:42:50
 *
 * =======================================================================================
 */

#include <pcap.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

#include "../utils/clrprnt.h"
#include "pkttime.h"


/** 
 * rosn_utils_pkttime_date()
 * 
 * Get and print the date of a packet
 *      pkthdr: information about the captured packet
 */
void rosn_utils_pkttime_date(const struct pcap_pkthdr *pkthdr)
{
    char date[11] = {0};    /* Buffer for the packet's date */
    rosn_clrset ptdate;     /* Printer */
    struct tm *ltime;       /* Time structure */
    time_t local_tv_sec;    /* Local time */

    /* Packet date */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptdate), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);

    /* Converting the timestamp to a readable format */
    local_tv_sec = pkthdr->ts.tv_sec;
    ltime = localtime(&local_tv_sec);

    /* Defining date's format: <year>-<month>-<day> */
    strftime(date, sizeof(date), "%Y-%m-%d", ltime); 

    /* Printing the date */
    printf("["); cprintf(&ptdate, "%s", date); printf("]");
}


/** 
 * rosn_utils_pkttime_hour()
 * 
 * Get and print the hour of a packet
 *      pkthdr: information about the captured packet
 */
void rosn_utils_pkttime_hour(const struct pcap_pkthdr *pkthdr)
{
    char hour[11] = {0};    /* Buffer for the packet's hour */
    rosn_clrset pthour;     /* Printer */
    struct tm *ltime;       /* Time structure */
    time_t local_tv_sec;    /* Local time */

    /* Packet hour */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pthour), ROSN_CLR_MAGENTA), ROSN_ATTR_NONE);

    /* Converting the timestamp to a readable format */
    local_tv_sec = pkthdr->ts.tv_sec;
    ltime = localtime(&local_tv_sec);

    /* Defining the hour's format: <hours>:<minutes>:<seconds> */
    strftime(hour, sizeof(hour), "%H:%M:%S", ltime);

    /* Printing the hour */
    printf("["); cprintf(&pthour, "%s", hour); printf("]");
}
