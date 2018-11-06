#include "urandom_parser.h"

const char *argp_program_version = "argex 1.0";

const char *argp_program_bug_address = "<bug-gnu-utils@gnu.org>";

enum parser_opts {
    //num options
    bytes = 'n',
    byte_group = 0x101,
    base = 'd',
    base_group = 0x111

};

struct argp_option options[] =
{
  {"bytes", bytes, "number of bytes", 0, "The number of random bytes to return", byte_group},
  {"decimal", base, 0, 0, "Display the random bytes in decimal", base_group},
  {0}
};

error_t parse_opt (int key, char *arg, struct argp_state *state)
{
  struct arguments *arguments = state->input;
    switch (key)
        {
        case bytes:
            if (arguments->bytes == NULL)
                arguments->bytes = arg;
            else
                argp_usage (state);

            break;
        case base:
            arguments->base = 1;
            break;
        case ARGP_KEY_END:
            if (state->arg_num < 1)
            {
                argp_usage (state);
            }
            break;
        default:
            return ARGP_ERR_UNKNOWN;
        }
    if (state->next == state->argc){
        if (arguments->bytes == NULL)
            argp_usage (state);
        else
            return ARGP_KEY_SUCCESS;
    }
    return 0;
}