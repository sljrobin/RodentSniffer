/*
 * =======================================================================================
 *
 *       Filename: rosn.c
 *    Description:
 *       Compiler: gcc
 *         Author: Simon L. J. Robin - http://sljrobin.com
 *        Created: 2015-04-30 08:32:04
 *       Modified: 2015-07-07 15:15:24
 *
 * =======================================================================================
 */

#include <stdio.h>

#include "rosnlib/boot/args.h"
#include "rosnlib/boot/header.h"


/* Main function */
int main(int argc, char *argv[])
{
    /* Show header */
    rosn_boot_header_show();
    /* Manage arguments */
    rosn_boot_args_manage(argc, argv);

    return 0;
}
