#ifndef MAP_ITEM_H
#define MAP_ITEM_H

enum E_MAP_ITEM {
    E_EMPTY = '0', 
    E_HEAD = '1', 
    E_BODY = '2',
    E_TAIL = '3', 
    E_CONDUCTOR = '4',

    /*auxiliary labels*/
    /*E_BLOCKED: means that neighborhood contains more than 2 heads */
     E_BLOCKED = '5', 
     /*E_TEMP_CONDUCTOR: will be set to E_HEAD in the end of iteration */
     E_TEMP_CONDUCTOR = '6'}; 

typedef enum E_MAP_ITEM E_MAP_ITEM;


#endif