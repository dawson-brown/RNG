#include <argp.h>

const char *argp_program_version = "argex 1.0";

const char *argp_program_bug_address = "<bug-gnu-utils@gnu.org>";

/*
   Description of non-option arguments
*/
static char args_doc[] = "n -- number of bytes\nd -- the display base";

/*
  Program documentation.
*/
static char doc[] = "Random number generator using /dev/urandom";

/*
   the argp structure--for use in main.
*/

static struct argp_option options[];

static error_t parse_opt (int key, char *arg, struct argp_state *state);

static struct argp argp = {options, parse_opt, args_doc, doc};

struct arguments arguments;