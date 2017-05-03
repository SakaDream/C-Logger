#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include "time_printf.h"

#define C_TIME  "\x1B[35m" // Magenta

void time_printf(const char *M, ... )
{
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    fprintf (stderr, "%s[%d-%d-%d_%d:%d:%d] ", C_TIME, timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900,  timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

    va_list args;
    va_start(args, M);
    vfprintf(stderr, M, args);
    va_end(args);
}