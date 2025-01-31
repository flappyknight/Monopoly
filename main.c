#include "main.h"

#define PLAYER_COUNT 4

int main() {
    srand(time(0));

    MapItem map[MAPITEM_COUNT];
    initMap(map);

    Player players[PLAYER_COUNT];
    initializePlayer(players, PLAYER_COUNT);

    int round =0;
    Player *winner;

    while(true){
        for (int p=0; p<PLAYER_COUNT;p++){
            Player *current_player = players+p;
            if(current_player->stagnant)
                continue;

            int steps = getStep();
            stepPlayer(current_player, steps);
            interactive(current_player, map);

        }
    if (settlement(players, winner))
        break;
    round++;
    }
}

void initMap(MapItem *map){
    MapItem *items = (MapItem *) malloc(MAPITEM_COUNT*sizeof(MapItem)); 
}

int getStep(){
    return rand() % (MAX_STEP - MIN_STEP + 1) + MIN_STEP;
}


