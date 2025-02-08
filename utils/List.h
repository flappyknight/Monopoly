#include <stdlib.h>
#include <stdbool.h>


typedef struct Node{
    int num;
    struct Node*next;
}
Node;

typedef struct
{
    Node *head;
    Node *tail;
    int count;
    /* data */
}List;

List *initList(void);

void addItem(List *list, int num);

void *getItem(List *list, int n);

void emptyList(List * list);

void delItem(List *list, int num);

bool isEmpty(List *list);

void insertItem(List *list, int position, int num);

void freeList(List *list);

// void popItem();
