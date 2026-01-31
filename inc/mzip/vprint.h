#pragma once
#include <mzip/args.h>
#include <stdio.h>

extern struct arguments arguments;

#define vprint(...) if (arguments.verbose) { printf(__VA_ARGS__); }