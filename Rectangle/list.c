#include <stdio.h>
#include "list.h"
#include "rect.h"
#include <stdlib.h>


void display_list(NODE* head){
    NODE* tmp = head;
    while(tmp!= NULL){
        printf("Area = %d\n", area(tmp->data));
        tmp= tmp->next;
    }
}

NODE* insert_node(NODE* head, NODE* node){
    NODE* tmp = head;
    //node is lesser than head
    if(isSmaller(node->data, tmp->data)){
        node->next = head;
        head = node;
        return head;
    }
    // node is more than tmp, iterates until the position BEFORE tmp becomes MORE than node.
    while((tmp->next!=NULL) && isSmaller(tmp->next->data, node->data)){
        tmp = tmp->next;
    }
    if (tmp->next!= NULL){
        NODE* nxt = tmp->next;
        tmp->next = node;
        node->next = nxt;
    }
    //singular node
    else{
        tmp->next = node;
        node->next = NULL;
    }
    return head;
}

void freedom(NODE* head){
    NODE* del = head;
    head = head->next;
    free(del);
}
