#include <stdio.h>
#include <mzip/args.h>
#include <mzip/vprint.h>

struct arguments arguments;

/* Main function */
int main(int argc, char* argv[])
{
    /* Parse command line arguments */
    arguments.verbose = 0;
    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    vprint("Target: %s\nVerbose: %s\n",
           arguments.args[0],
           arguments.verbose ? "yes" : "no");

    return 0;
}