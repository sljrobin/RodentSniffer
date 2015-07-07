/*
 * =======================================================================================
 *
 *       Filename: devs.h
 *    Description:
 *       Compiler: gcc
 *         Author: Simon L. J. Robin - http://sljrobin.com
 *        Created: 2015-04-30 10:38:33
 *       Modified: 2015-07-07 13:32:12
 *
 * =======================================================================================
 */

#ifndef _ROSNLIB_DEVS_H_
#define _ROSNLIB_DEVS_H_

#define ROSN_MAX_DEVNAME 50
#define ROSN_MAX_DEVICES 100

void rosn_boot_devs_list(void); /* Find and printing all the available devices */

#endif
