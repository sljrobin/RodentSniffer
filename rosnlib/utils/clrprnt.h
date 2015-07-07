/*
 * =======================================================================================
 *
 *       Filename: clrprnt.h
 *    Description:
 *       Compiler: gcc
 *         Author: Simon L. J. Robin - http://sljrobin.com
 *        Created: 2015-04-24 09:15:28
 *       Modified: 2015-05-07 16:24:40
 *
 * =======================================================================================
 */

#ifndef _ROSNLIB_CLRPRNT_H_
#define _ROSNLIB_CLRPRNT_H_

#define ROSN_ATTR_BLINK 5
#define ROSN_ATTR_BOLD 1
#define ROSN_ATTR_DIM 2
#define ROSN_ATTR_NONE 0
#define ROSN_ATTR_REVERSE 7
#define ROSN_ATTR_UNDERLINE 4

#define ROSN_CLR_BLACK 0
#define ROSN_CLR_BLUE 4
#define ROSN_CLR_CYAN 6
#define ROSN_CLR_GREEN 2
#define ROSN_CLR_MAGENTA 5
#define ROSN_CLR_RED 1
#define ROSN_CLR_WHITE 7
#define ROSN_CLR_YELLOW 3
 

typedef struct rosn_clrset rosn_clrset;
struct rosn_clrset {
    int attr;           /* Attribute  */
    int bg;             /* Background */
    int fg;             /* Foreground */
};

rosn_clrset *rosn_utils_clrprnt_init(rosn_clrset *clrset); /* Initialize the Color Setter */
rosn_clrset *rosn_utils_clrprnt_setattr(rosn_clrset *clrset, int attr); /* Set the Attribute to the Color Setter */
rosn_clrset *rosn_utils_clrprnt_setbg(rosn_clrset *clrset, int bg); /* Set the Background to the Color Setter */
rosn_clrset *rosn_utils_clrprnt_setfg(rosn_clrset *clrset, int fg); /* Set the Foreground to the Color Setter */
void rosn_clrprnt_cprint_init(rosn_clrset *clrset); /* Initialize the colored printf() */
void rosn_clrprnt_cprint_reset(void); /* Reset the colored printf() */
void cprintf(rosn_clrset *clrset, char *fmt, ...); /* The colored printf() */

#endif
