#include <stdlib.h>

#include "../include/defs.h"
#include "../include/input.h"
#include "../include/lex.h"
#include "../include/parser.h"
#include "../include/gen.h"
#include "../include/vm.h"
#include "../include/asm.h"
#include "../include/func.h"

#define MIN_ARGS 2
#define SOURCE_ARG 1

int main(int argc, char **argv)
{
    if (argc < MIN_ARGS) {
        fatal_error("No file provided! Usage: compiler <source>");
    }

    open_file(argv[SOURCE_ARG]);

    byte *code = compile(parse(lex()));

    close_file();

    printf("Generated ASM:\n");
    print_asm(code);

    printf("Execution result:\n");
    run(code);

    return EXIT_SUCCESS;
}