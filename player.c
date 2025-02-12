#include "player.h"

void initializePlayer(Player ** players, int n){
    Player * items = (Player *) malloc(n*sizeof(Player));
    for(int i=0; i<n; i++){
        items[i].asset_list=initList();
        items[i].id = i;
        items[i].money = INITIAL_MONEY;
        items[i].name = NAMES[i];
        items[i].position = INITIAL_POSITION;
        items[i].stagnant = INITIAL_STAGNANT;
        items[i].purchase_probability = INITIAL_PURCHASE_PROBABILITY;
    }
    *players = items;
}

void updateMoney(Player *player, int money){
    player->money+= money;
}


void showInfo(Player *player){

}