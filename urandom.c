#include <stdio.h>
#include <stdlib.h>
#include "urandom_parser.h"

struct arguments
{                   
  char *bytes;            /* -n flag the number of random bytes */
  int base;            /* -d flag the number base to diplay */       
};

static struct argp_option options[] =
{
  {"bytes", 'n', "number of bytes", 0, "The number of random bytes to return"},
  {"decimal", 'd', 0, 0, "Display the random bytes in decimal"},
  {0}
};

static error_t parse_opt (int key, char *arg, struct argp_state *state)
{
  struct arguments *arguments = state->input;
    switch (key)
        {
        case 'n':
            if (arguments->bytes == NULL)
                arguments->bytes = arg;
            else
                argp_usage (state);

            break;
        case 'd':
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


int main(int argc, char **argv){
    
    struct arguments arguments;
    arguments.bytes = NULL;
    arguments.base = 0;
    argp_parse (&argp, argc, argv, 0, 0, &arguments);

    int length = atoi(arguments.bytes);
    int display = arguments.base;

    unsigned char *key = (unsigned char *) malloc(sizeof(unsigned char)*length);
    FILE* random = fopen("/dev/urandom", "r");
    fread(key, sizeof(unsigned char)*length, 1, random);
    fclose(random);
    
    if (display){
        for (int i=0; i<length; i++){
            printf("%.2d", (unsigned char)key[i]);
        }
    } else {
        for (int i=0; i<length; i++){
            printf("%.2x", (unsigned char)key[i]);
        }
    }

    printf("\n");
    return 0;
}