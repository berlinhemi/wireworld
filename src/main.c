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

    const char* file_name;
    int steps;
    double timeout;
    int random_toggle;
    
    if (set_params(arguments, &file_name, &steps, &timeout, &random_toggle) != 0)
    {
        printf("%s\n", "Error while cmd arguments parsing");
        return -1;
    }

    char** map = NULL;
    int height = 0;
    int width = 0;

    
    if(read_map( &map, &height,  &width, file_name) != -1)
    {
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
                custom_sleep(timeout);
                clear_console();
                i++;
            }
            
            clear_map(&map, height, width);
        }
    }
    else
    {
        printf("%s\n", "Error in map reading");
        return -1;
    }
    return 0;
}

