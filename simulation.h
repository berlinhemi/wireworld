#ifndef MOVEMENTS_H
#define MOVEMENTS_H

#include "position.h"

/*void move_player(char** map, char** coloring, int height, int width, 
                Position* player_pos, Position* box_pos, char direction);
*/


int do_itration(char** map,  int height, int width);
void get_linked_conductors(Position **conductors, int *count, char** map,  int height, int width );

/*int is_game_over(char** map, int height, int width, Position box_pos);*/

#endif