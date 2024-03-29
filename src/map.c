#include "map.h"
#include "item_type.h"

int read_map(char*** map, int* lines, int* columns, const char* file_name)
{
    FILE* file = fopen(file_name, "r");
    if (file == NULL) 
    {
        printf("No such file:%s\n", file_name);
        return -1;
    }

    int ret = fscanf(file, "%d%d", lines, columns);

    if(ret != 2)
    {
        printf("Error while reading lines and colums count\n");
        return -1;
    }
    int height = *lines;
    int width = *columns;

    if(height < 1 || width < 1)
    {
        printf("Invalid height or width value\n");
        return -1;
    }

   
    *map = (char**) malloc(sizeof(char*) * height);
    int i;
    int j;
    for(i = 0; i < height; i++)
    {
        (*map)[i] = (char*)malloc(sizeof(char) * width);  
        memset((*map)[i], ' ', sizeof(char) * width);/*fill byte-by-byte*/ 
    }

    int digit = 0;
    char item = 0;
    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            ret = fscanf(file, "%d",  &digit); 
            if (ret == 1)
            {   
                /*convert int (digit) to char and put it to map*/
                item = digit + '0';
                (*map)[i][j] = item;
            }     
            else 
            {
                printf("Error while reading file:invalid format.\n");
                return -1;
            }         
        }
    }
    fclose(file);  
    return 0;
 }


void clear_map(char*** map, int height, int width)
{
    int i;
    for(i = 0; i < height; i++)
    {
        free((*map)[i]);
        (*map)[i] = NULL;
    }
    free(*map);
    *map = NULL;
}

 void print_map(char** map, int rows, int cols) {                       
    int i;
    int j;    
    printf("\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
                       
            if (map[i][j] == E_HEAD)
                set_background("blue") ;            
            else if (map[i][j] == E_BODY)
                set_background("green") ; 
            else if (map[i][j] == E_TAIL)
                set_background("red") ;  
            else if (map[i][j] == E_CONDUCTOR)
                set_background("yellow") ;  

            printf("%s", "  ");
            set_background("reset") ;         
        }
        printf("\n");                            
    }
    printf("\n");   
}


enum E_MAP_ITEM get_item(char** map, Position pos)
{
    return map[pos.height][pos.width];
}

void put_item(char** map, Position pos, E_MAP_ITEM item_id)
{
    map[pos.height][pos.width] = item_id;
}
