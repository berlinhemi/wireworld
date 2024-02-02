#include <argp.h>

const char *argp_program_version = "wireworld 1.0";
static char doc[] = "Wireworld: cellular automaton first proposed by Brian Silverman";
const char *argp_program_bug_address = "<e-mail address>";
static char args_doc[] = "MAP_FILE";

static struct argp_option options[] = {
    {"steps", 's', "COUNT", 0, "Count of steps in automation"},
    {"timeout", 't', "SEC", 0, "Interval between steps (seconds)"},
    {"random", 'r', 0, 0, "Put head in random place"},
    {0}
};

struct arguments{
    char* args[1];
    int steps;
    int timeout;
    int  random;
};

static error_t parse_opt(int key, char *arg, struct argp_state *state){

    struct arguments *arguments = state->input;
    switch(key){

        case 's':
            arguments->steps = atoi(arg);
            break;
        case 't':
            arguments->timeout = atoi(arg);
            break;
        case 'r':
            arguments->random = 1;
            break;

        case ARGP_KEY_ARG:
            if(state->arg_num >= 1)
            {
                printf("Too many arguments.\n");
                argp_usage(state);
            }
               
            arguments->args[state->arg_num] = arg;
            break;

        case ARGP_KEY_END:
            if(state->arg_num < 1)
            {
                printf("Not enough arguments.\n");
                argp_usage(state);
            }
                
            break;

        default:
            return ARGP_ERR_UNKNOWN;
    }

    return 0;
}     

static struct argp argp = {options, parse_opt, args_doc, doc};
