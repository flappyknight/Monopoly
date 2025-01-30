#pragma once
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

#define MAX_MAPITEM 100
#define MIN_STEP 1
#define MAX_STEP 12

typedef struct 
{
    /* data */
    char *type;
    int id;
    int position;
} MapItem;


void initMap(MapItem *map);

int getStep();

void interactive(Player *player, MapItem * map);

bool judge(Player *players);

bool settlement(Player *players, Player *winner);


