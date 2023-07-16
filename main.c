#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "color.h"
#include "map.h"
#include "newSleep.h"
#include "simulation.h"

int main(int argc, char* argv[])
{
    if(argc < 5)
    {
        printf("%s", "Not enough arguments.\n");
        printf("%s", "Usage: ./wireworld <file_name> <steps_amount> <sleep_length_secs> <random_toggle>\n");
        printf("%s", "Example : ./wireworld XOR_NOT.txt 1000 0.5 0\n");
        return 1;
    }
    
    char** map = NULL;
    int height = 0;
    int width = 0;

    const char* file_name = argv[1];
    int steps = atoi(argv[2]);
    double sleep_secs = atof(argv[3]);
    int random_toggle = atoi(argv[4]);

    read_map( &map, &height,  &width, file_name);

    if(map != NULL )
    {
        int i = 0;
        while(i < steps)
        {
            print_map(map, height, width);	
            do_iteration(map, height,width);
            newSleep(sleep_secs);
            system("clear");
            i++;
        }
        
        clear_map(&map, height, width);
    }
        
    return 0;
}