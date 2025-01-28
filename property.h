#include <stdlib.h>


enum PROPER_TYPE{land, house, hotel, factory, station};

typedef  struct {
    int type;
    char * name;
    char * description;
    void * sub_proper;
} Property;

