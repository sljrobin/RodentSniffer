/*
 * =======================================================================================
 *
 *       Filename: dtlnk.c
 *    Description: Get the Data Link Header Type
 *       Compiler: gcc
 *         Author: Simon L. J. Robin | https://sljrobin.org
 *        Created: 2015-04-30 15:28:41
 *       Modified: 2016-02-13 13:36:15
 *
 * =======================================================================================
 */

#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

#include "dtlnk.h"


/** 
 * rosn_boot_dtlnk_findhdrt()
 * 
 * Find the Data Link Header Type
 *      handle: session handle
 * Return the Data Link Header Type
 */
int rosn_boot_dtlnk_findhdrt(pcap_t *handle)
{
    int dlhdrt = 0;     /* Link-Layer Header Type */

    /* Getting the Link-Layer Header Type */
    dlhdrt = pcap_datalink(handle);

    /* Error */
    if (dlhdrt < 0) {
        printf("[ERROR]: Could not find Link-Layer Header Type: %s\n", pcap_geterr(handle));
        exit(1);
    }

    return dlhdrt;
}
