#include "clist.h"
#include <stdlib.h>
#include <stdio.h>


node_t* InitialiseCLL(node_t* head, job_t val){
    head = malloc(sizeof(node_t));
    head -> data = val;
    head->next = head;
    return head;
}

node_t* InsertNode(node_t* head, job_t val){
    node_t* ptr = head;
    node_t* NewNode = malloc(sizeof(node_t));
    NewNode->data = val;
    NewNode->next = head;
    while(ptr-> next != head){
        ptr = ptr->next;
    }
    ptr -> next = NewNode;
    head = NewNode;
    return head;
}

node_t* DelNode(node_t* head){
    if(head->next == head){
        free(head);
        head = NULL;
        return NULL;
    }
    node_t* ptr = head;
    while(ptr->next!= head){
        ptr = ptr->next;
    }
    ptr->next = head->next;
    free(head);
    return ptr->next;
}

void displayListF(node_t* head){
    node_t* ptr = head;
    while(ptr->next != head){
        dispJob(ptr->data);
        ptr = ptr->next;
    }
    dispJob(ptr->data);
}

void displayListB(node_t* head, node_t* ptr){
    if(ptr->next == head){
        dispJob(ptr->data);
        return;
    }
    else{
        displayListB(head, ptr->next);
        dispJob(ptr->data);
    }
}
