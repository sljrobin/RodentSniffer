/*
 * =======================================================================================
 *
 *       Filename: header.c
 *    Description: Header printing
 *       Compiler: gcc
 *         Author: Simon L. J. Robin | https://sljrobin.org
 *        Created: 2015-04-30 10:40:12
 *       Modified: 2016-02-13 13:36:04
 *
 * =======================================================================================
 */

#include "../utils/clrprnt.h"


/** 
 * rosn_boot_header_show()
 * 
 * Show the header
 */
void rosn_boot_header_show(void)
{
    rosn_clrset pttitle;    /* Printer */
    
    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&pttitle), ROSN_CLR_WHITE), ROSN_ATTR_NONE);    /* Title */

    cprintf(&pttitle, "  ___         _         _   ___      _  __  __         \n");
    cprintf(&pttitle, " | _ \\___  __| |___ _ _| |_/ __|_ _ (_)/ _|/ _|___ _ _ \n");
    cprintf(&pttitle, " |   / _ \\/ _` / -_) ' \\  _\\__ \\ ' \\| |  _|  _/ -_) '_|\n");
    cprintf(&pttitle, " |_|_\\___/\\__,_\\___|_||_\\__|___/_||_|_|_| |_| \\___|_|  \n\n");
    cprintf(&pttitle, " Developed by Simon L. J. Robin\n");
    cprintf(&pttitle, "--------------------------------------------------------\n");
}
