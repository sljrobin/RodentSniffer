/*
 * =======================================================================================
 *
 *       Filename: args.c
 *    Description: Management of the command line arguments
 *       Compiler: gcc
 *         Author: Simon L. J. Robin - http://sljrobin.com
 *        Created: 2015-04-30 10:40:12
 *       Modified: 2015-07-08 09:19:43
 *
 * =======================================================================================
 */

#include <ctype.h>
#include <pcap.h>
#include <stdlib.h>
#include <unistd.h>

#include "../process/sniff.h"
#include "../utils/clrprnt.h"
#include "../utils/help.h"
#include "ckid.h"
#include "devs.h"


/** 
 * rosn_boot_args_manage()
 * 
 * Manage the program arguments
 *      argcnt: count of total command line arguments 
 *      argvctr: array of character string of each command line argument
 * Return 0
 */
int rosn_boot_args_manage(int argcnt, char *argvctr[])
{
    char *argvle_f = NULL;                  /* Value for the `-f` option */
    char *argvle_s = NULL;                  /* Value for the `-s` option */
    const int argmin = 1;                   /* Minimum of arguments */
    extern char *optarg;                    /* Text of the following argv-element */
    extern int optind;                      /* Index of the next element to be processed */
    int argflg_p = ROSN_PROMISCUOUS_OFF;    /* Flag for the `-p` option */
    int idx = 0;                            /* Index for arguments after the command-line options */
    int opt = 0;                            /* A parser for the command-line arguments */

    /* Printer */
    rosn_clrset ptarg_error;

    rosn_utils_clrprnt_setattr(rosn_utils_clrprnt_setfg(rosn_utils_clrprnt_init(&ptarg_error), ROSN_CLR_RED), ROSN_ATTR_NONE);

    while ((opt = getopt(argcnt, argvctr, "f:hlps:")) != -1) {
        switch (opt) {
            /* Filter */
            case 'f':
                argvle_f = optarg;
                break;
            /* Help */
            case 'h':
                rosn_utils_help_full();
                exit(0);
            /* List devices */
            case 'l':
                rosn_boot_ckid_hasrights();
                rosn_boot_devs_list();
                exit(0);
            /* Promiscuous */
            case 'p':
                argflg_p = ROSN_PROMISCUOUS_ON;
                break;
            /* Sniff */
            case 's':
                argvle_s = optarg;
                rosn_boot_ckid_hasrights();
                rosn_process_sniff_loop(argvle_s, argvle_f, argflg_p);
                break;
            /* Error cases */
            case '?':
                /* '-s' without a device */
                if (optopt == 's')
                    cprintf(&ptarg_error, "[ERROR]: The option '-%c' requires a device. Usage: %s -%c <device>\n", optopt, argvctr[0], optopt);
                /* Unknown option */
                else if (isprint(optopt))
                    cprintf(&ptarg_error, "[ERROR]: The option '-%c' is unknown. Type \"%s -h\" for printing help.\n", optopt, argvctr[0]);
                /* Miscellaneous */
                else
                    cprintf(&ptarg_error, "[ERROR]: The option '-\\x%x' is an unknown option character. Type \"%s -h\" for printing help.\n", optopt, argvctr[0]);
                return 1;
            /* Default */
            default:
                abort();
        }
    }
   
    /* Check there is at least 1 argument */
    if ((optind + argmin) > argcnt) {
        cprintf(&ptarg_error, "[ERROR]: Need at least %d argument. Type \"%s -h\" for printing help.\n", argmin, argvctr[0]);
        exit(1);
    }

    /* Arguments after the command-line options */
    if (idx < argcnt)
        for (idx = optind; idx < argcnt; idx++)
            cprintf(&ptarg_error, "[ERROR]: Non-option argument; %s\n", argvctr[idx]);
    else
        cprintf(&ptarg_error, "[ERROR]: No arguments left to process.\n");

    return 0;
}
