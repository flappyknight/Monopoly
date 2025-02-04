#include "player.h"

void stepPlayer(Player *player, int steps){
    player->position+=steps;
}

void initializePlayer(Player ** players, int n){
    Player * items = (Player *) malloc(MAX_PLAYERS*sizeof(Player));
    for(int i=0; i<MAX_PLAYERS; i++){
        items[i].asset_list;

    }

}