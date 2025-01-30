#include "main.h"

#define PLAYER_COUNT 4

int main() {

    MapItem map[MAX_MAPITEM];
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
