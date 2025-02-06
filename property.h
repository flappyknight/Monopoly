#include <stdlib.h>

#define ASSET_FILE "asset.src"

#define TOTAL_ASSET_NUM 100


typedef enum {land, factory, station} AssetTYPE;

typedef  struct {
    AssetTYPE type;
    int id;
    char name[10];
    int position;
    int owner_id;

    int price;
    int house_cost;
    int hotel_cost;

    int rent;
    int house_rent;
    int hotel_rent;

    int house_num;
    int hotel_num;

    int is_mortgage;
    char description[100];
} Asset;

void initAsset(Asset * assets);

void addAsset(int owner_id, Asset *asset);

void popAsset(Asset * asset);

int mortgage(Asset *asset);

int rent(Asset *asset);




