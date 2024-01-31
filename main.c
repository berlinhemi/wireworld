#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <argp.h>

#include "color.h"
#include "map.h"
#include "utils.h"
#include "simulation.h"

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

void show_help()
{
        printf("%s", "Not enough arguments.\n");
        printf("%s", "Usage: ./wireworld <file_name> <steps_amount> <sleep_length_secs> <random_toggle>\n");
        printf("%s", "Example 1: ./wireworld small.map 1000 0.5 0\n");
        printf("%s", "Example 2: ./wireworld small.map 10 2 1\n");

}


int main(int argc, char* argv[])
{

    struct arguments arguments;

    arguments.steps = 10;
    arguments.timeout = 1;
    arguments.random = 0;

    argp_parse(&argp, argc, argv, 0, 0, &arguments);
    
    char** map = NULL;
    int height = 0;
    int width = 0;

    const char* file_name = arguments.args[0];
    int steps = arguments.steps;
    double sleep_secs = arguments.timeout;
    int random_toggle = arguments.random;

    read_map( &map, &height,  &width, file_name);

    if(map != NULL )
    {
        int i = 0;
        while(i < steps)
        {
            if(random_toggle == 1)
            {
                if(i != 0 && i % 10 == 0)
                {
                    put_random_head(map, height,width);
                }
                
            }
            print_map(map, height, width);	
            do_iteration(map, height,width);
            sleep(sleep_secs);
            system("clear");
            i++;
        }
        
        clear_map(&map, height, width);
    }
        
    return 0;
}

