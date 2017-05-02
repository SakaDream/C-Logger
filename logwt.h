#ifndef __logwt_h__
#define __logwt_h__

#define KMAG  "\x1B[35m" // Time
#define KCYN  "\x1B[36m" // Debug
#define KRED  "\x1B[31m" // Error
#define KYEL  "\x1B[33m" // Warning
#define KNRM  "\x1B[0m" // Info, Default

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

#ifdef NDEBUG

#define debug(M, ...)

#else

#define debug(M, ...) time_printf("%s[DEBUG] %10s:%10d:%20s():\nMessage: " M "\n\n%s", KCYN, __FILE__, __LINE__, __func__, ##__VA_ARGS__, KNRM)

#endif

#define clean_errno() (errno == 0 ? "" : strerror(errno))

#define log_err(M, ...) time_printf("%s[ERROR] %10s:%10d:%20s(): %s\nMessage: " M "\n\n%s", KRED, __FILE__, __LINE__, __func__, clean_errno(), ##__VA_ARGS__, KNRM)
#define log_warn(M, ...) time_printf("%s[WARN ] %10s:%10d:%20s(): %s\nMessage: " M "\n\n%s", KYEL, __FILE__, __LINE__, __func__, clean_errno(), ##__VA_ARGS__, KNRM)
#define log_info(M, ...) time_printf("%s[INFO ] %10s:%10d:%20s()\nMessage: " M "\n\n%s", KNRM, __FILE__, __LINE__, __func__, clean_errno(), ##__VA_ARGS__, KNRM)

#define check(A, M, ...) if(!(A)) { log_err(M, ##__VA_ARGS__); errno = 0; goto error; }
#define sentinel(M, ...) { log_err(M, ##__VA_ARGS__); errno = 0; goto error; }
#define check_mem(A) check((A), "Out of memory.")
#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); errno = 0; goto error; }

void time_printf(const char *M, ... )
{
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    fprintf (stderr, "%s[%d-%d-%d_%d:%d:%d] ", KMAG, timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900,  timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

    va_list args;
    va_start(args, M);
    vfprintf(stderr, M, args);
    va_end(args);
}

#endif