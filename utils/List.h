#include <stdlib.h>>


typedef struct{
    int num;
    Node *next;
}
Node;

typedef struct
{
    Node *head;
    Node *tail;
    int count;
    /* data */
}List;

List initList(void);

void addItem(List list, int num);

void delItem(List list, int num);

void insertItem(List list, int num);

void freeList(List list);

// void popItem();
