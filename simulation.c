
#include "simulation.h"
#include "stdio.h"


void get_linked_conductors(Position head, 
                        Position **conductors, int *count,
                        char** map,  int height, int width )
{
    int deviations[] = {-1, 0, 1};
    int i ;
    int j ;
    int linked_ = 0;
    int new_weight = 0;
    for(i = 0; i < sizeof(deviations)/sizeof(int); i++)
    {
        int height_mod = head.height + deviations[i];
        if(height_mod  >= 0  && height_mod < height)
        {
            
        }
    }
}


int do_iteration(char** map, int height, int width) 
{
    int i = 0;
    int j = 0;
    for (i = 0; i < height; i++) 
    {
        for (j = 0; j < width; j++) 
        {
            switch(map[i][j]) 
            {
            case '3':               /* red(tail) */
                map[i][j] = '4';
                break;
            case '2':               /* green(body) */
                map[i][j] = '3';
                break;
            case '1':               /* blue(head) */
                Position *conductors = NULL;
                get_linked_conductors()
                for c in conductors:
                    process_conductor_neihgbors()
                break;
             
            
            default:
                break;
            }
        }
    }
    remove_commets();
}