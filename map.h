#ifndef MAP_H
#define MAP_H

#include "position.h"
#include "item_type.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"




void read_map(char*** map, int* height, int* width, const char* file_name);            
void clear_map(char*** map, int height, int width);

/*int get_item_position( char** map, int height, int width,  char item_id, Position* pos);*/

E_MAP_ITEM get_item(char** field, Position pos); 
void put_item(char** map, Position pos,  E_MAP_ITEM item_id);
void print_map(char** map, int height, int width);

#endif