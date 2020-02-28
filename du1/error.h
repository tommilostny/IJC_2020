/*
 *
 *
 */

#ifndef ERROR_H
#define ERROR_H

void warning_msg(const char *fmt, ...);

void error_exit(const char *fmt, ...);

#include "error.c"

#endif