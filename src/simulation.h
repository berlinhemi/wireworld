#ifndef MOVEMENTS_H
#define MOVEMENTS_H

#include "position.h"


/*implement next iteration of sumalation*/
void do_iteration(char** map,  int height, int width);

/*fill array (conductors) of linked with head conductors*/
void get_linked_conductors(Position head, 
                        Position* conductors, int *count, 
                        char** map,  int height, int width );
                       
/*get count of heads, linked with conductor on conductor_pos*/
int get_linked_heads_count(Position conductor_pos,  char** map,  int height, int width);

/*remove or modify auxiliary labels (see item_type.h)*/
void remove_auxiliary_labels( char** map,  int height, int width);

int get_conductors_count(char** map,  int height, int width);
/*get all conductors positions to array*/
void get_all_conductors(Position** conductors, int* conductors_count, char** map,  int height, int width);

/*put electron head to random conductor*/
void put_random_head( char** map,  int height, int width);


#endif