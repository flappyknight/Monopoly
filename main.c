#include "main.h"

#define PLAYER_COUNT 4

int main() {
    srand(time(0));

    Map map;
    initMap(&map);

    Player *players;
    initializePlayer(&players, PLAYER_COUNT);

    int round =0;
    Player *winner;

    while(true){
        for (int p=0; p<PLAYER_COUNT;p++){
            Player *current_player = players+p;
            if(current_player->stagnant)
                continue;

            int steps = getStep();
            stepPlayer(current_player, steps);
            interactive(current_player, &map);

        }
    if (settlement(players, winner))
        break;
    round++;
    }
    freeMap(&map);
}

void initMap(Map *map){
    MapIndex *items = (MapIndex *) malloc(MAPITEM_COUNT * sizeof(MapIndex));
    Asset *assets = (Asset *) malloc(TOTAL_ASSET_NUM * sizeof(Asset));
    FILE *index_resource = fopen(MAP_FILE,"rb");
    FILE *asset_resource = fopen(ASSET_FILE,"rb");
    fread(items, sizeof(MapIndex), MAPITEM_COUNT, index_resource);
    fread(items, sizeof(Asset), TOTAL_ASSET_NUM, asset_resource);
    map->map_indexes=items;
    map->assets = assets;
}

int getStep(){
    return rand() % (MAX_STEP - MIN_STEP + 1) + MIN_STEP;
}

bool consider(Player * player, Asset * asset){
    if(player->money > asset->price){
        if( (rand() % 100 ) >=((int) player->purchase_probability*100)){
            return false;
        }
        return true;
    }
    return false;
}

void buyAsset(Player *player, Asset *asset){
    updateMoney(player, -asset->price);
    asset->owner_id = player->id;
    addItem(player->asset_list, asset->id);
}

void interactive(Player *player, Map * map){
    MapIndex *current_pos =  (map->map_indexes + player->position);
    if(current_pos->type==ASSET){
        Asset *current_asset = (map->assets)+(current_pos->id);
        if (current_asset->owner_id==-1){
//            考虑购买资产
            if (consider(player, current_asset)){
                buyAsset(player, current_asset);
            }
        }
        else{
//            计算过路费，并且当前玩家向所属玩家付费
        }
    }
    else if (current_pos->type==OPPO){

    }
    else if (current_pos->type==DEST){

    }
    else if (current_pos->type==START){

    }
    else if (current_pos->type==JAIL){

    }
    else if (current_pos->type==PARK){

    }
    else if (current_pos->type==TAX){

    }

}

