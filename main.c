#include "main.h"

#define PLAYER_COUNT 4

int main() {
    srand(time(0));

    Map map;
    initMap(&map);

    Player *players;
    initializePlayer(&players, PLAYER_COUNT);

    int round =0;

    while(true){
        for (int p=0; p<PLAYER_COUNT;p++){
            Player *current_player = players+p;
            passJail(players);
            if(current_player->stagnant)
                continue;
            // 考虑是否赎回抵押的资产
            redeemParam redeem_param ={.player=current_player, .map=&map};
            traverseList(players->asset_list, redeemAsset, &redeem_param, NULL);
            int steps = getStep();
            stepPlayer(current_player);
            interactive(current_player, &map);

        }
    if (settlement(players))
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

void stepPlayer(Player *player){
    int steps = getStep();
    player->position+=steps;
    player->position %= MAPITEM_COUNT;
    if((player->position<steps) && player->position!=0){
        updateMoney(player, BONUS);
    }
}

bool consider(Player * player){
    if( (rand() % 100 ) >=((int) player->purchase_probability*100)){
        return false;
    }
    return true;
}

void buyAsset(Player *player, Asset *asset){
    if(player->money < asset->price){
        printf("Not enough Money to buy this Land\n");
        return;
    }
    updateMoney(player, -asset->price);
    asset->owner_id = player->id;
    addItem(player->asset_list, asset->id);
}


void upgradeAsset(Player *player, Asset *asset){
    if(asset->house_num<3){
        if (player->money<asset->house_cost){
            printf("Not enough Money to add a house\n");
            return;
        }
        updateMoney(player, -asset->house_cost);
        asset->house_num+=1;
    }
    else if(asset->hotel_num<3){
        if (player->money<asset->hotel_cost){
            printf("Not enough Money to add a hotel\n");
            return;
        }
        updateMoney(player, -asset->hotel_cost);
        asset->hotel_num+=1;
    }
    else{
        printf("Failed to upgrade this land, This land is full of constructions\n");
        return;
    }
}

void redeemAsset(void *item, void * param, void ** _){
    int *asset_id = (int *)item;
    redeemParam *redeem_param;
    redeem_param = (redeemParam *) param;
    Asset *asset = (redeem_param->map->assets) + *asset_id;
    int mortgage_money = mortgage(asset);
    if(consider(redeem_param->player) && (redeem_param->player->money>(int )(asset->price*MORTGAGE_RATIO))){
        updateMoney(redeem_param->player, -mortgage_money);
        asset->is_mortgage = 0;
    }
}

void mortgageAsset(void *item, void * param, void ** result){
    int *asset_id = (int *)item;
    mortgageParam *mortgage_param;
    mortgage_param = (mortgageParam *) param;
    Asset *asset = (mortgage_param->map->assets) + *asset_id;
    int mortgage_money = mortgage(asset);
    updateMoney(mortgage_param->player, mortgage_money);
    if(mortgage_param->player->money>mortgage_param->rents){
        *result = asset_id;
    }
}


void payRent(Player*p1, Player*p2, int rent){
    updateMoney(p1, -rent);
    updateMoney(p2, rent);
}

bool judge(Player *player){
    if(player->money<0){
        player->stagnant=-1;
        return false;
    }
    else{
        return true;
    }
}

void sendToJail(Player *player){
    player->stagnant = 1;
}

void passJail(Player *player){
    for(int i=0;i<MAX_PLAYERS;i++){
        if(player[i].stagnant>0){
            player[i].stagnant -=1;
        }
    }
}

void opportunity(Player *player){

}

void destiny(Player *player){

}

void payTax(Player *player){
    if (!isEmpty(player->asset_list))
        updateMoney(player, -TAX);
}

bool settlement(Player *players){
    int alive_players = 4;
    for(int i=0;i<MAX_PLAYERS;i++){
        if(players[i].stagnant==-1){
            alive_players -=1;
        }
        else{
            showInfo(players+i);
        }
    }
    if(alive_players==1)
        return true;
    else
        return false;
}

void interactive(Player *player, Map * map){
    MapIndex *current_pos =  (map->map_indexes + player->position);
    if(current_pos->type==ASSET){
        Asset *current_asset = (map->assets)+(current_pos->id);
        if(!current_asset->is_mortgage){ //如果没有被抵押
            if (current_asset->owner_id==-1){
//            考虑购买资产
                if (consider(player)){
                    buyAsset(player, current_asset);
                }
            }
            else if(current_asset->owner_id==player->id){
//           考虑是否添置房屋或旅馆
                if (consider(player)){
                    upgradeAsset(player, current_asset);
                }
            }
            else{
//            计算过路费，并且当前玩家向所属玩家付费
                Player *owner =  player+(current_asset->owner_id - player->id);
//            如果付不起过路费
                int rents = rent(current_asset);
                if(player->money < rents){
                //抵押资产
                    mortgageParam mortgage_param = {.player=player,.map=map, .rents=rents};
                    int * flag = NULL;
                    traverseList(player->asset_list, mortgageAsset, &mortgage_param, flag);
                }
                payRent(player, owner, rent(current_asset));
                judge(player);
            }
        };

    }
    else if (current_pos->type==OPPO){
        opportunity(player);

    }
    else if (current_pos->type==DEST){
        destiny(player);
    }
    else if (current_pos->type==JAIL){
        sendToJail(player);
    }
    else if (current_pos->type==PARK){
        //do nothing
    }
    else if (current_pos->type==TAX){
        payTax(player);
    }

}

