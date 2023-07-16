#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "color.h"
#include "map.h"


int main()
{
    
    char** map = NULL;
    int height = 0;
    int width = 0;

    const char* file_name = "map.txt";
 

    read_map( &map, &height,  &width, file_name);

    if(map != NULL )
    {
       
       
        Position player_pos;       
        Position box_pos;

        print_map(map, height, width);	

      
        clear_map(&map, height, width);
    }
        
    return 0;
}