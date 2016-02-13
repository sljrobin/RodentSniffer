/*
 * =======================================================================================
 *
 *       Filename: devs.c
 *    Description: Handle of the devices
 *       Compiler: gcc
 *         Author: Simon L. J. Robin | https://sljrobin.org
 *        Created: 2015-04-30 10:40:12
 *       Modified: 2016-02-13 13:36:27
 *
 * =======================================================================================
 */

#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/clrprnt.h"
#include "devs.h"

/** 
 * rosn_boot_devs_list()
 * 
 * Find and print all the available devices
 */
void rosn_boot_devs_list(void)
{
    char errbuf[PCAP_ERRBUF_SIZE] = {0};                        /* Buffer to store error messages */
    char devslst[ROSN_MAX_DEVICES][ROSN_MAX_DEVICES] = {{0}};   /* Buffer for devices list */
    int cnt_dev = 1;                                            /* A counter for devices */
    pcap_if_t *alldevs;                                         /* All available devices */
    pcap_if_t *dev;                                             /* A device */

    /* Printers */
    rosn_clrset ptstep_error;
    rosn_clrset ptstep_info;
    rosn_clrset ptstep_inprogress;
    rosn_clrset ptstep_valid;

    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptstep_error), ROSN_CLR_RED), ROSN_ATTR_NONE);         /* Step error */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptstep_info), ROSN_CLR_WHITE), ROSN_ATTR_NONE);        /* Step info */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptstep_inprogress), ROSN_CLR_BLUE), ROSN_ATTR_NONE);   /* Step in progress */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptstep_valid), ROSN_CLR_GREEN), ROSN_ATTR_NONE);       /* Step valid */

    /* Searching devices */
    cprintf(&ptstep_inprogress, "Searching for devices to sniff\t\t\t\t");
    if (pcap_findalldevs(&alldevs, errbuf)) {
        cprintf(&ptstep_error, "[ERROR]: Can not find devices: %s", errbuf);
        exit(1);
    }
    cprintf(&ptstep_valid, "[DONE]\n");

    /* Printing devices */
    cprintf(&ptstep_inprogress, "Printing all the devices\n");
    for (dev = alldevs; dev != NULL; dev = dev->next) {
        cprintf(&ptstep_info, "    %d. %s - %s\n", cnt_dev, dev->name, dev->description);
        if (dev->name != NULL)
            strcpy(devslst[cnt_dev], dev->name);
        cnt_dev++;
    }
    cprintf(&ptstep_valid, "\t\t\t\t\t\t\t[DONE]\n");
}
