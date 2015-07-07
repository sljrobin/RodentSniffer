/*
 * =======================================================================================
 *
 *       Filename: clrprnt.c
 *    Description:
 *       Compiler: gcc
 *         Author: Simon L. J. Robin - http://sljrobin.com
 *        Created: 2015-04-24 09:16:37
 *       Modified: 2015-04-24 12:37:58
 *
 * =======================================================================================
 */

#include <stdarg.h>
#include <stdio.h>
#include "clrprnt.h"


/* Initialize the Color Setter */
rosn_clrset *rosn_utils_clrprnt_init(rosn_clrset *clrset)
{
    clrset->attr = -1;
    clrset->bg = -1;
    clrset->fg = -1;

    return clrset;
}


/* Set the Attribute to the Color Setter */
rosn_clrset *rosn_utils_clrprnt_setattr(rosn_clrset *clrset, int attr)
{
    clrset->attr = attr;

    return clrset;
}


/* Set the Background to the Color Setter */
rosn_clrset *rosn_utils_clrprnt_setbg(rosn_clrset *clrset, int bg)
{
    clrset->bg = bg;

    return clrset;
}


/* Set the Foreground to the Color Setter */
rosn_clrset *rosn_utils_clrprnt_setfg(rosn_clrset *clrset, int fg)
{
    clrset->fg = fg;

    return clrset;
}


/* Initialize the colored printf() */
void rosn_utils_clrprnt_cprint_init(rosn_clrset *clrset)
{
    if (clrset->bg != -1)
        printf("%c[%d;%d;%dm", 27, clrset->attr, (30 + clrset->fg), (40 + clrset->bg));
    else
        printf("%c[%d;%dm", 27, clrset->attr, (30 + clrset->fg));
}


/* Reset the colored printf() */
void rosn_utils_clrprnt_cprint_reset(void)
{
    printf("%c[%dm", 27, 0);

//    return 0;
}


/* The colored printf() */
void cprintf(rosn_clrset *clrset, char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    rosn_utils_clrprnt_cprint_init(clrset);
    vprintf(fmt, args);
    rosn_utils_clrprnt_cprint_reset();
    va_end(args);

//    return 0;
}
