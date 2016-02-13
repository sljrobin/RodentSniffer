/*
 * =======================================================================================
 *
 *       Filename: devs.h
 *    Description: Handle of the devices
 *       Compiler: gcc
 *         Author: Simon L. J. Robin | https://sljrobin.org
 *        Created: 2015-04-30 10:38:33
 *       Modified: 2016-02-13 13:36:21
 *
 * =======================================================================================
 */

#ifndef _ROSNLIB_DEVS_H_
#define _ROSNLIB_DEVS_H_

#define ROSN_MAX_DEVNAME 50
#define ROSN_MAX_DEVICES 100

void rosn_boot_devs_list(void);     /* Find and print all the available devices */

#endif
