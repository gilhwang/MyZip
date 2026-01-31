#pragma once
#include <argp.h>
#include <stdint.h>
#include <mzip/constant.h>

#define EXPECTED_TARGET_FILE 1

const char *argp_program_version = "mzip 1.0";
const char *argp_program_bug_address = "<gilhwangdev@gmail.com>";
char doc[] = "MyZip -- a custom file compressor";
char args_doc[] = "TARGET_FILE";

struct argp_option options[] = {
    {"verbose", 'v', 0, 0, "More verbose output", 0},
    {0}
};

struct arguments {
    char *args[1];
    uint8_t verbose;
};

error_t parse_opt(int key, char* arg, struct argp_state* state)
{
    struct arguments* arguments = state->input;

    switch (key) {
        case 'v':
            arguments->verbose = TRUE;
        case ARGP_KEY_ARG:
            if (state->arg_num >= EXPECTED_TARGET_FILE) {
                fprintf(stderr, "Too many arguments\n");
                argp_usage(state);
            }
            arguments->args[state->arg_num] = arg;
            break;
        case ARGP_KEY_END:
            if (state->arg_num < EXPECTED_TARGET_FILE) {
                fprintf(stderr, "Too few arguments\n");
                argp_usage(state);
            }
            break;
        default:
            return ARGP_ERR_UNKNOWN;
    }

    return 0;
}

struct argp argp = {options, parse_opt, args_doc, doc};