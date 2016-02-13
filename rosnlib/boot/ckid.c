/*
 * =======================================================================================
 *
 *       Filename: ckid.c
 *    Description: Check the ID of the user
 *       Compiler: gcc
 *         Author: Simon L. J. Robin | https://sljrobin.org
 *        Created: 2015-04-30 15:53:01
 *       Modified: 2016-02-13 13:36:36
 *
 * =======================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "../utils/clrprnt.h"
#include "ckid.h"


/** 
 * rosn_boot_ckid_hasrights()
 * 
 * Check the users rights
 */
void rosn_boot_ckid_hasrights(void)
{
    uid_t uid = 0;      /* User IDentifier */
    uid_t euid = 0;     /* Effective User IDentifier */

    /* Printers */
    rosn_clrset ptstep_error;
    rosn_clrset ptstep_inprogress;
    rosn_clrset ptstep_info;
    rosn_clrset ptstep_valid;

    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptstep_error), ROSN_CLR_RED), ROSN_ATTR_NONE);         /* Step error */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptstep_inprogress), ROSN_CLR_WHITE), ROSN_ATTR_NONE);  /* Step in progress */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptstep_info), ROSN_CLR_BLUE), ROSN_ATTR_NONE);         /* Step info */
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptstep_valid), ROSN_CLR_GREEN), ROSN_ATTR_NONE);       /* Step valid */

    uid = getuid();     /* Getting the UID */
    euid = geteuid();   /* Getting the EUID */

    cprintf(&ptstep_inprogress, "Getting UID and EUID: ");
    cprintf(&ptstep_info, "UID: %i", uid);
    cprintf(&ptstep_inprogress, ", ");
    cprintf(&ptstep_info, "EUID: %i",euid);
    cprintf(&ptstep_valid, "\t\t\t[DONE]\n");

    if (uid != 0 || uid != euid) {
        cprintf(&ptstep_error, "[ERROR]: Need to have root privileges to execute the sniffer!\n");
        exit(1);
    } 
}
