#include <stdlib.h>
#include <stdbool.h>
#include "./utils/List.h"


#define INITIAL_MONEY 20000
#define INITIAL_POSITION 0
#define INITIAL_STAGNANT false
#define INITIAL_PURCHASE_PROBABILITY 0.5
#define INITIAL_PROPERTY NULL
#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 15

const char NAMES[MAX_PLAYERS][MAX_NAME_LENGTH] = {"Jack", "Tom", "Lisa", "John"};

typedef struct {
    int id;
    char *name;
    bool stagnant;
    double money;
    int position;
    List asset_list;

    float purchase_probability;

} Player;

Player *initializePlayer(int n);

void updateMoney(Player *player, double money);

void addProperty(Player *player, void *property);

void removeProperty(Player *player, void *property);

void stepPlayer(Player *player, int steps);

void movePlayer(Player *player, int place);

void blockPlayer(Player *player);

void enablePlayer(Player *player);





