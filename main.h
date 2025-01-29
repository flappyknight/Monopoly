#include <stdio.h>

typedef struct 
{
    /* data */
    char *type;
    int id;
    int position;
} Map;


void initMap(Map *maps);
