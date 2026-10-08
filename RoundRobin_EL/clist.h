#pragma once
#include "job.h"

typedef struct node_t{
    job_t data;
    struct node_t* next;
}node_t;

node_t* InitialiseCLL(node_t* head, job_t val);
node_t* InsertNode(node_t* head, job_t val);
node_t* DelNode(node_t* head);
void displayListF(node_t* head);
void displayListB(node_t* head, node_t* ptr);
