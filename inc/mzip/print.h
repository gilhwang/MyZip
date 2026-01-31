#pragma once
#include <mzip/args.h>
#include <stdio.h>

extern struct arguments arguments;

#define vprintf(...) if (arguments.verbose) { printf(__VA_ARGS__); }

#ifdef DEBUG
    #define DEBUG_PRINTF(fmt, ...) fprintf(stderr, "[DEBUG] %s:%d:%s(): " fmt, \
        __RELATIVE_FILE__, __LINE__, __func__, ##__VA_ARGS__)
#else
    #define DEBUG_PRINTF(fmt, ...)
#endif