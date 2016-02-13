/*
 * =======================================================================================
 *
 *       Filename: rosn.c
 *    Description: Main file
 *       Compiler: gcc
 *         Author: Simon L. J. Robin | https://sljrobin.org
 *        Created: 2015-04-30 08:32:04
 *       Modified: 2016-02-13 13:32:56
 *
 * =======================================================================================
 */

#include <stdio.h>

#include "rosnlib/boot/args.h"
#include "rosnlib/boot/header.h"


/** 
 * main()
 * 
 * Main function
 *      argc: count of total command line arguments 
 *      argv: array of character string of each command line argument
 * Return 0
 */
int main(int argc, char *argv[])
{
    /* Show header */
    rosn_boot_header_show();

    /* Manage arguments */
    rosn_boot_args_manage(argc, argv);

    return 0;
}
