/*
 * =======================================================================================
 *
 *       Filename: clrprnt.h
 *    Description: Color formatting
 *       Compiler: gcc
 *         Author: Simon L. J. Robin - http://sljrobin.com
 *        Created: 2015-04-24 09:15:28
 *       Modified: 2015-07-08 11:25:53
 *
 * =======================================================================================
 */

#ifndef _ROSNLIB_CLRPRNT_H_
#define _ROSNLIB_CLRPRNT_H_

#define ROSN_ATTR_BLINK 5       /* Attribute: Blink     */
#define ROSN_ATTR_BOLD 1        /* Attribute: Bold      */
#define ROSN_ATTR_DIM 2         /* Attribute: Dim       */
#define ROSN_ATTR_NONE 0        /* Attribute: None      */
#define ROSN_ATTR_REVERSE 7     /* Attribute: Reverse   */
#define ROSN_ATTR_UNDERLINE 4   /* Attribute: Underline */

#define ROSN_CLR_BLACK 0        /* Color: Black   */
#define ROSN_CLR_BLUE 4         /* Color: Blue    */
#define ROSN_CLR_CYAN 6         /* Color: Cyan    */
#define ROSN_CLR_GREEN 2        /* Color: Green   */
#define ROSN_CLR_MAGENTA 5      /* Color: Magenta */
#define ROSN_CLR_RED 1          /* Color: Red     */
#define ROSN_CLR_WHITE 7        /* Color: White   */
#define ROSN_CLR_YELLOW 3       /* Color: Yellow  */
 

typedef struct rosn_clrset rosn_clrset; /* clrset     */
struct rosn_clrset {
    int attr;                           /* Attribute  */
    int bg;                             /* Background */
    int fg;                             /* Foreground */
};

rosn_clrset *rosn_utils_clrprnt_init(rosn_clrset *clrset);              /* Initialize the Color Setter */
rosn_clrset *rosn_utils_clrprnt_setattr(rosn_clrset *clrset, int attr); /* Set the Attribute to the Color Setter */
rosn_clrset *rosn_utils_clrprnt_setbg(rosn_clrset *clrset, int bg);     /* Set the Background to the Color Setter */
rosn_clrset *rosn_utils_clrprnt_setfg(rosn_clrset *clrset, int fg);     /* Set the Foreground to the Color Setter */
void rosn_clrprnt_cprint_init(rosn_clrset *clrset);                     /* Initialize the colored printf() */
void rosn_clrprnt_cprint_reset(void);                                   /* Reset the colored printf() */
void cprintf(rosn_clrset *clrset, char *fmt, ...);                      /* The colored printf() */

#endif
