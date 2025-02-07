#include "property.h"

int rent(Asset *asset){
    return asset->hotel_num*asset->hotel_rent + asset->house_rent * asset->house_num;
}

