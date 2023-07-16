
#include "item_type.h"
#include "map.h"
#include "simulation.h"
#include "stdio.h"



void get_linked_conductors(Position head_pos, 
                        Position *conductors, int *count,
                        char** map,  int height, int width )
{
    
    int deviations[] = {0, -1, 1};
    int dev_length = sizeof(deviations)/sizeof(int);
    int i ;
    int j ;
    *count = 0;
   
    for(i = 0; i < dev_length; i++)
    {
        for(j = 0; j < dev_length; j++)
        {
            /*not interesting when both deviations equal 0*/
            if( !(i == 0 && j == 0) )
            {
                int height_mod = head_pos.height + deviations[i];
                int width_mod = head_pos.width + deviations[j];
                if( height_mod  >= 0  && height_mod < height 
                    && width_mod  >= 0  && width_mod < width)
                {
                    if(map[height_mod][width_mod] == E_CONDUCTOR 
                        || map[height_mod][width_mod] == E_TEMP_CONDUCTOR)
                    {
                        Position conductor = {height_mod, width_mod};
                        conductors[*count] = conductor;
                        (*count)++;
                    }
                }
            }
           
        }
    }
}


int get_linked_heads_count(Position conductor_pos,  char** map,  int height, int width)
{
    int result = 0;
    int deviations[] = {0, -1, 1};
    int dev_length = sizeof(deviations)/sizeof(int);
    int i ;
    int j ;
   
    for(i = 0; i < dev_length; i++)
    {
        for(j = 0; j < dev_length; j++)
        {
            /*not interesting when both deviations equal 0*/
            if( !(i == 0 && j == 0) )
            {
                int height_mod = conductor_pos.height + deviations[i];
                int width_mod = conductor_pos.width + deviations[j];
                if( height_mod  >= 0  && height_mod < height 
                    && width_mod  >= 0  && width_mod < width)
                {
                    if(map[height_mod][width_mod] == E_HEAD)
                    {
                        result++;  
                    }
                }
            }          
        }
    }
    return result;

}

void process_neihgborhood(Position conductor, char** map,  int height, int width )
{
    int deviations[] = {0, -1, 1};
    int dev_length = sizeof(deviations)/sizeof(int);
    int i ;
    int j ;

   
    for(i = 0; i < dev_length; i++)
    {
        for(j = 0; j < dev_length; j++)
        {
            /*not interesting when both deviations equal 0*/
            if( !(i == 0 && j == 0) )
            {
                int height_mod = conductor.height + deviations[i];
                int width_mod = conductor.width + deviations[j];
                if( height_mod  >= 0  && height_mod < height 
                    && width_mod  >= 0  && width_mod < width)
                {
                    if(map[height_mod][width_mod] == E_HEAD)
                    {
                        map[conductor.height][conductor.width] = E_TEMP_CONDUCTOR;
                    }
                }
            }
           
        }
    }
}

void remove_special_labels( char** map,  int height, int width)
{
    int i = 0;
    int j = 0;
    //loop over all items
    for (i = 0; i < height; i++) 
    {
        for (j = 0; j < width; j++) 
        {
            if(map[i][j] == E_BLOCKED)
            {
                map[i][j] = E_CONDUCTOR;
            }
            else if (map[i][j] == E_TEMP_CONDUCTOR)
            {
                map[i][j] = E_HEAD;
            }
        }
    }
}



void do_iteration(char** map, int height, int width) 
{
    const int max_head_count = 2;
    int i = 0;
    int j = 0;
    //loop over all items
    for (i = 0; i < height; i++) 
    {
        for (j = 0; j < width; j++) 
        {
            switch(map[i][j]) 
            {
            case E_TAIL:               /* red(tail) */
                map[i][j] = E_CONDUCTOR;
                break;
            case E_BODY:               /* green(body) */
                map[i][j] = E_TAIL;
                break;
            case E_HEAD:               /* blue(head) */
                {
                    Position head_pos = {i, j};
                    const int max_neighbors = 8;
                    Position conductors[max_neighbors];
                    int conductors_count = 0;
                    /*save nearest to current head conductors to array*/
                    get_linked_conductors(head_pos, conductors, &conductors_count, map, height, width );
                    int k;
                    /*process nearest conductors*/
                    for (k = 0; k < conductors_count; k++)
                    {
                        /*if(map[conductors[k].height][conductors[k].width] != E_BLOCKED)*/
                        if(get_item(map, conductors[k]) != E_BLOCKED)
                        {
                            
                            int head_count = get_linked_heads_count(conductors[k], map, height, width);
                            if (head_count <= max_head_count)
                            {
                                /*OK, count of nearest heads is not greater max_head_count*/
                                put_item(map, conductors[k], E_TEMP_CONDUCTOR);
                                /*map[conductors[k].height][conductors[k].width] = E_TEMP_CONDUCTOR;*/
                                /*process_neihgborhood(conductors[k], map, height, width );*/
                            }
                            else
                            {
                                /*set special mark so as not to process these elements later in loop*/
                                put_item(map, conductors[k], E_BLOCKED);
                                /*map[conductors[k].height][conductors[k].width] = E_BLOCKED;*/
                            }
                            
                        }
                        
                    }
                    put_item(map, head_pos, E_BODY);
                    /*map[head_pos.height][head_pos.width] = E_BODY;*/ 
                    
                    break;
                }
             
            
            default:
                break;
            }
        }
    }
    remove_special_labels(map, height, width);
}