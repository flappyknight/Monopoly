#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "player.h"

#define MAPITEM_COUNT 100
#define MIN_STEP 1
#define MAX_STEP 12

#define START_POS 0

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


