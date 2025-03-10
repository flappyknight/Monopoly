#include "List.h"

List *initList(void){
    List *list = (List *)malloc(sizeof(List));
    list->count=0;
    list->head=NULL;
    list->tail=list->head;
    return list;
}

void addItem(List *list, int num){
    Node *node = (Node *) malloc(sizeof(Node));
    node->num = num;
    node->next = NULL;
    if (list->tail==NULL){
        list->head=node;
        list->tail=node;
    }
    else{
        Node *tmp = list->tail;
        list->tail=node;
        tmp->next=node;
    }

    list->count++;

};

bool isEmpty(List *list){
    if(list->tail==NULL)
        return true;
    else
        return false;
};


void delItem(List *list, int num){
    if(isEmpty(list))
        return ;
    Node *node = list->head;
    if(node->num==num){
        if(list->head==list->tail){
            list->head=NULL;
            list->tail=NULL;
        }
        else{
            list->head=node->next;
        }
        free(node);
    }
    while(node->next!=NULL){
        if(node->next->num==num){
            Node *next_node = node->next->next;
            free(node->next);
            node->next = next_node;
            break;
        }
        node=node->next;
    }
};

void *getItem(List *list, int n){
    Node *next_node;
    next_node =list->head;
    for (int i=0;i<n; i++){
        next_node = next_node->next;
    }
    return &(next_node->num);
}

void traverseList(List *list, operaFunc func, void *param, void *result){
    Node *next_node;
    next_node =list->head;
    for(int i=0; i<list->count; i++){
        func(&(next_node->num), param, result);
        if(result != NULL)
            return;
        next_node = next_node->next;
    }
}
// void insertItem(List *list, int position, int num);

void emptyList(List * list){
    Node *node = list->head;
    Node *next_node;
    while(node!=NULL){
        next_node = node->next;
        free(node);
        node = next_node;
    }
};


void freeList(List *list){
    emptyList(list);
    free(list);

};