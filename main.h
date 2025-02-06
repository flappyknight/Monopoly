#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "player.h"
#include "property.h"

#define MAP_FILE "map.src"

#define MAPITEM_COUNT 100
#define MIN_STEP 1
#define MAX_STEP 12

typedef enum {ASSET, OPPO, DEST, START, JAIL, PARK, TAX} MapType;

typedef struct 
{
    /* data */
    MapType type;
    int id;
    int position;
} MapIndex;

typedef struct {
    MapIndex *map_indexes;
    Asset *assets;
} Map;


void initMap(Map *map);

int getStep();

void interactive(Player *player, Map * map);

bool judge(Player *players);

bool settlement(Player *players, Player *winner);


