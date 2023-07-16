#ifndef MAP_H
#define MAP_H

#include "position.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"




void read_map(char*** map, int* height, int* width, const char* file_name);            
void clear_map(char*** map, int height, int width);

/*int get_item_position( char** map, int height, int width,  char item_id, Position* pos);*/

/* char get_item_from_field(char** field, Position pos); */

/*void put_item_on_map(char** map, Position pos, char item_id);*/
void print_map(char** map, int height, int width);

#endif