#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

Player * initializePlayer(int n) {
    Player * player = (Player *) malloc(sizeof(Player));
    for (int i=0; i<n;i++){
        player->id = i;
        player->name = (char *) malloc(20);
    }
    return player;
}


int main() {
    printf("Hello, World!\n");
    return 0;
}
