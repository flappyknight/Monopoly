#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "player.h"
#include "property.h"

#define MAP_FILE "map.src"

#define BONUS 2000
#define MAPITEM_COUNT 100
#define MIN_STEP 1
#define MAX_STEP 12
#define LAND_TAX 800

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

typedef struct {
    Player * player;
    Map * map;
} redeemParam;

typedef struct {
    Player * player;
    Map * map;
    int rents;
} mortgageParam;

void freeMap(Map *map);

void initMap(Map *map);

void payRent(Player*p1, Player*p2, int rent);

int getStep();

void stepPlayer(Player *player);

bool consider(Player * player);

void interactive(Player *player, Map * map);

void buyAsset(Player *player, Asset *asset);

void upgradeAsset(Player *player, Asset *asset);

void redeemAsset(void *asset_id, void * param, void ** _);

void opportunity(Player *player);

void sendToJail(Player *player);

void passJail(Player *player);

void destiny(Player *player);

void payTax(Player *player);



bool judge(Player *player);

bool settlement(Player *players);


