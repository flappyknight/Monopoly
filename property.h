#include <stdlib.h>

#define TOTAL_ASSET_NUM 100


typedef enum {land, factory, station} AssetTYPE;

typedef  struct {
    AssetTYPE type;
    int id;
    char * name;
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

    int mortgage_value;
    bool is_mortgage;
    char * description;
} Asset;

void initAsset(Asset * asset);

void addAsset(int owner_id, Asset *asset);

void popAsset(Asset * asset);

int mortgage(Asset *asset);

int rent(Asset *asset);




