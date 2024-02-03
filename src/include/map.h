#ifndef MAP_H
#define MAP_H

#include "position.h"
#include "item_type.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"




int read_map(char*** map, int* height, int* width, const char* file_name);    
void print_map(char** map, int height, int width);        
void clear_map(char*** map, int height, int width);


E_MAP_ITEM get_item(char** field, Position pos); 
void put_item(char** map, Position pos,  E_MAP_ITEM item_id);


#endif