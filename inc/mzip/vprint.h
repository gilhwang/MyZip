#pragma once
#include <mzip/args.h>
#include <stdio.h>

extern struct arguments arguments;

#define vprintf(...) if (arguments.verbose) { printf(__VA_ARGS__); }