#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "argparcer.h"
#include "color.h"
#include "map.h"
#include "simulation.h"
#include "utils.h"


// void show_help()
// {
//         printf("%s", "Not enough arguments.\n");
//         printf("%s", "Usage: ./wireworld <file_name> <steps_amount> <sleep_length_secs> <random_toggle>\n");
//         printf("%s", "Example 1: ./wireworld small.map 1000 0.5 0\n");
//         printf("%s", "Example 2: ./wireworld small.map 10 2 1\n");

// }


int main(int argc, char* argv[])
{

    struct arguments arguments;

    /*
        Default values
    */
    arguments.steps = 10;
    arguments.timeout = 1;
    arguments.random = 0;

    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    const char* file_name = arguments.args[0];
    int steps = arguments.steps;
    double sleep_secs = arguments.timeout;
    int random_toggle = arguments.random;
    
    char** map = NULL;
    int height = 0;
    int width = 0;

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
            clear_console();
            i++;
        }
        
        clear_map(&map, height, width);
    }
        
    return 0;
}

