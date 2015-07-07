/*
 * =======================================================================================
 *
 *       Filename: dtlnk.c
 *    Description:
 *       Compiler: gcc
 *         Author: Simon L. J. Robin - http://sljrobin.com
 *        Created: 2015-04-30 15:28:41
 *       Modified: 2015-07-07 16:50:24
 *
 * =======================================================================================
 */

#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

#include "dtlnk.h"

int rosn_boot_dtlnk_findhdrt(pcap_t *handle)
{
    int dlhdrt = 0;     /* Link-Layer Header Type */

    dlhdrt = pcap_datalink(handle);

    if (dlhdrt < 0) {
        printf("[ERROR]: Could not find Link-Layer Header Type: %s\n", pcap_geterr(handle));
        exit(1);
    }

    return dlhdrt;
}
