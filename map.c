#include "map.h"
#include "item_type.h"

void read_map(char*** map, int* lines, int* columns, const char* file_name)

 {
    
    FILE* file = fopen(file_name, "r");
    if (file == NULL) 
    {
        printf("no such file:%s", file_name);
        return;
    }

    int ret = fscanf(file, "%d%d", lines, columns);
    int height = *lines;
    int width = *columns;

    if(ret != 2)
    {
        printf("error while reading lines and colums count");
        return;
    }
   
    *map = (char**) malloc(sizeof(char*) * height);
    int i;
    int j;
    for(i = 0; i < height; i++)
    {
        (*map)[i] = (char*)malloc(sizeof(char) * width);  
        memset((*map)[i], ' ', sizeof(char) * width);/*fill byte-by-byte*/ 
    }

    int x = 0;
    int y = 0;
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
                printf("error while reading file:invalid format.");
            }         
        }
    }
    fclose(file);
    
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
    /*for (i = 0; i <= cols + 1; i++) 
    {
         printf("%c", '*');
    }
    printf("\n");
    */

    for (i = 0; i < rows; i++) {
        /*printf("%c", '*');*/
        for (j = 0; j < cols; j++) {
           /* if (map[i][j] == '0')           
                set_background("red");    
            */              
            if (map[i][j] == E_HEAD)
                set_background("blue") ;            
            else if (map[i][j] == E_BODY)
                set_background("green") ; 
            else if (map[i][j] == E_TAIL)
                set_background("red") ;  
            else if (map[i][j] == E_CONDUCTOR)
                set_background("yellow") ;  
          
            /*printf("%c ", map[i][j]);*/
             printf("%s", "  ");
            set_background("reset") ;         
        }
       /*printf("*\n"); */    
        printf("\n");                            
    }
    /*
    for (i = 0; i <= cols + 1; i++) 
    {
         printf("%c", '*');
    }
    */
    printf("\n");   
}


