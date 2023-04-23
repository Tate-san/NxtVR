#ifndef __LOGGING_H__
#define __LOGGING_H__

#include <stdio.h>

#define _STRINGIFY(a) #a
#define STR(x) _STRINGIFY(x)

#define LOG(prefix, fmt, ...) \
    fputs(prefix, stderr); \
    fprintf(stderr, fmt "\n", ##__VA_ARGS__)


#define LOGI(msg, ...) \
    LOG("INFO: ", msg, ##__VA_ARGS__)

#define LOGW(msg, ...) \
    LOG("WARN: ", msg, ##__VA_ARGS__)

#define LOGE(msg, ...) \
    LOG("ERROR: ", msg, ##__VA_ARGS__)

#ifdef DEBUG
#define LOGD(msg, ...) \
    LOG("DEBUG: ", msg, ##__VA_ARGS__)
#else
#define LOGD(...)
#endif

#endif // __LOGGING_H__