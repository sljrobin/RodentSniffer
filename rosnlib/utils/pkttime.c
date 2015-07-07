/*
 * =======================================================================================
 *
 *       Filename: pkttime.c
 *    Description:
 *       Compiler: gcc
 *         Author: Simon L. J. Robin - http://sljrobin.com
 *        Created: 2015-04-30 10:40:12
 *       Modified: 2015-06-30 16:01:34
 *
 * =======================================================================================
 */

#include <pcap.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

#include "../utils/clrprnt.h"
#include "pkttime.h"

/* Get and print the date of a packet */
void rosn_utils_pkttime_date(const struct pcap_pkthdr *pkthdr)
{
    char date[11] = {0};
    struct tm *ltime;
    time_t local_tv_sec;
    rosn_clrset ptdate; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptdate), ROSN_CLR_YELLOW), ROSN_ATTR_NONE);

    local_tv_sec = pkthdr->ts.tv_sec;
    ltime = localtime(&local_tv_sec);
    strftime(date, sizeof(date), "%Y-%m-%d", ltime);

    printf("["); cprintf(&ptdate, "%s", date); printf("]");
}

/* Get and print the hour of a packet */
void rosn_utils_pkttime_hour(const struct pcap_pkthdr *pkthdr)
{
    char hour[11] = {0};
    struct tm *ltime;
    time_t local_tv_sec;
    rosn_clrset pthour; rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pthour), ROSN_CLR_MAGENTA), ROSN_ATTR_NONE);


    local_tv_sec = pkthdr->ts.tv_sec;
    ltime = localtime(&local_tv_sec);
    strftime(hour, sizeof(hour), "%H:%M:%S", ltime);

    printf("["); cprintf(&pthour, "%s", hour); printf("]");
}
