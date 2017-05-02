#ifndef __log_h__
#define __log_h__

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

#define debug(M, ...) fprintf(stderr, "%s[DEBUG] %10s:%10d:%20s():\nMessage: " M "\n\n%s", KCYN, __FILE__, __LINE__, __func__, ##__VA_ARGS__, KNRM)

#endif

#define clean_errno() (errno == 0 ? "" : strerror(errno))

#define log_err(M, ...) fprintf(stderr, "%s[ERROR] %10s:%10d:%20s(): %s \nMessage: " M "\n\n%s", KRED, __FILE__, __LINE__, __func__, clean_errno(), ##__VA_ARGS__, KNRM)
#define log_warn(M, ...) fprintf(stderr, "%s[WARN ] %10s:%10d:%20s(): %s \nMessage: " M "\n\n%s", KYEL, __FILE__, __LINE__, __func__, clean_errno(), ##__VA_ARGS__, KNRM)
#define log_info(M, ...) fprintf(stderr, "%s[INFO ] %10s:%10d:%20s()\nMessage: " M "\n\n%s", KNRM, __FILE__, __LINE__, __func__, ##__VA_ARGS__, KNRM)

#define check(A, M, ...) if(!(A)) { log_err(M, ##__VA_ARGS__); errno = 0; goto error; }
#define sentinel(M, ...) { log_err(M, ##__VA_ARGS__); errno = 0; goto error; }
#define check_mem(A) check((A), "Out of memory.")
#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); errno = 0; goto error; }

#endif