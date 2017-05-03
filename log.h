#ifndef __log_h__
#define __log_h__

#define C_DEBUG  "\x1B[36m" // Cyan
#define C_ERROR  "\x1B[31m" // Red
#define C_WARN  "\x1B[33m" // Yellow
#define C_RESET  "\x1B[0m" // Info, Default

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

#ifdef NDEBUG

#define debug(M, ...)

#else

#define debug(M, ...) fprintf(stderr, "%s[DEBUG] %10s:%10d:%20s():\nMessage: " M "\n\n%s", C_DEBUG, __FILE__, __LINE__, __func__, ##__VA_ARGS__, C_RESET)

#endif

#define clean_errno() (errno == 0 ? "" : strerror(errno))

#define log_err(M, ...) fprintf(stderr, "%s[ERROR] %10s:%10d:%20s(): %s \nMessage: " M "\n\n%s", C_ERROR, __FILE__, __LINE__, __func__, clean_errno(), ##__VA_ARGS__, C_RESET)
#define log_warn(M, ...) fprintf(stderr, "%s[WARN ] %10s:%10d:%20s(): %s \nMessage: " M "\n\n%s", C_WARN, __FILE__, __LINE__, __func__, clean_errno(), ##__VA_ARGS__, C_RESET)
#define log_info(M, ...) fprintf(stderr, "%s[INFO ] %10s:%10d:%20s()\nMessage: " M "\n\n%s", C_RESET, __FILE__, __LINE__, __func__, ##__VA_ARGS__, C_RESET)

#define check(A, M, ...) if(!(A)) { log_err(M, ##__VA_ARGS__); errno = 0; goto error; }
#define sentinel(M, ...) { log_err(M, ##__VA_ARGS__); errno = 0; goto error; }
#define check_mem(A) check((A), "Out of memory.")
#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); errno = 0; goto error; }

#endif