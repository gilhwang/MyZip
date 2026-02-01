#include <stdio.h>
#include "mzip/args.h"
#include "mzip/print.h"
#include <string.h>
#include <stdlib.h>

struct arguments arguments;

/* Main function */
int main(int argc, char* argv[])
{
    /* Parse command line arguments */
    arguments.verbose = 0;
    argp_parse(&argp, argc, argv, 0, 0, &arguments);
    vprintf("Command line options:\n --Target file: %s\n --Verbose: %d\n",
           arguments.args[0],
           arguments.verbose);

    /* Read input file/directory */
    const char* inputFilename = arguments.args[0];
    size_t outputFileLen = strlen(inputFilename) + strlen(".") + strlen(MZIP_EXTENSION) + 1;
    char* outputFilename = malloc(sizeof(char) * outputFileLen);
    if (outputFilename == NULL) {
        fprintf(stderr, "Failed to allocate memory for output filename");
        return 1;
    }
    snprintf(outputFilename, outputFileLen, "%s.%s", inputFilename, MZIP_EXTENSION);
    vprintf("Compressing to file: %s\n", outputFilename);

    FILE *inputFile_p = fopen(arguments.args[0], "rb");
    if (inputFile_p == NULL) {
        perror("Failed to open input file");
        return 1;
    }
    FILE *outputFile_p = fopen(outputFilename, "wb");
    if (outputFile_p == NULL) {
        perror("Failed to open output file");
        return 1;
    }

    DEBUG_PRINTF("Reached end of program\n");

    return 0;
}