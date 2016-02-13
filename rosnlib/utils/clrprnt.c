/*
 * =======================================================================================
 *
 *       Filename: clrprnt.c
 *    Description: Color formatting
 *       Compiler: gcc
 *         Author: Simon L. J. Robin | https://sljrobin.org
 *        Created: 2015-04-24 09:16:37
 *       Modified: 2016-02-13 13:43:12
 *
 * =======================================================================================
 */

#include <stdarg.h>
#include <stdio.h>

#include "clrprnt.h"


/** 
 * rosn_utils_clrprnt_init()
 * 
 * Initialize the Color Setter
 *      clrset: the Color Setter
 * Return the Color Setter
 */
rosn_clrset *rosn_utils_clrprnt_init(rosn_clrset *clrset)
{
    clrset->attr = -1;
    clrset->bg = -1;
    clrset->fg = -1;

    return clrset;
}


/** 
 * rosn_utils_clrprnt_setattr()
 * 
 * Set the Attribute to the Color Setter
 *      clrset: the Color Setter
 *      attr: the Attribute
 * Return the Color Setter
 */
rosn_clrset *rosn_utils_clrprnt_setattr(rosn_clrset *clrset, int attr)
{
    clrset->attr = attr;

    return clrset;
}


/** 
 * rosn_utils_clrprnt_setbg()
 * 
 * Set the Attribute to the Color Setter
 *      clrset: the Color Setter
 *      bg: the Background
 * Return the Color Setter
 */
rosn_clrset *rosn_utils_clrprnt_setbg(rosn_clrset *clrset, int bg)
{
    clrset->bg = bg;

    return clrset;
}


/** 
 * rosn_utils_clrprnt_setfg()
 * 
 * Set the Attribute to the Color Setter
 *      clrset: the Color Setter
 *      fg: the Foreground
 * Return the Color Setter
 */
rosn_clrset *rosn_utils_clrprnt_setfg(rosn_clrset *clrset, int fg)
{
    clrset->fg = fg;

    return clrset;
}


/** 
 * rosn_utils_clrprnt_cprint_init()
 * 
 * Initialize the colored printf()
 *      clrset: the Color Setter
 */
void rosn_utils_clrprnt_cprint_init(rosn_clrset *clrset)
{
    if (clrset->bg != -1)
        printf("%c[%d;%d;%dm", 27, clrset->attr, (30 + clrset->fg), (40 + clrset->bg));
    else
        printf("%c[%d;%dm", 27, clrset->attr, (30 + clrset->fg));
}


/** 
 * rosn_utils_clrprnt_cprint_reset()
 * 
 * Reset the colored printf()
 */
void rosn_utils_clrprnt_cprint_reset(void)
{
    printf("%c[%dm", 27, 0);
}


/** 
 * cprintf()
 * 
 * The colored printf()
 *      clrset: the Color Setter
 *      fmt: the assigned format
 */
void cprintf(rosn_clrset *clrset, char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    rosn_utils_clrprnt_cprint_init(clrset);
    vprintf(fmt, args);
    rosn_utils_clrprnt_cprint_reset();
    va_end(args);
}
