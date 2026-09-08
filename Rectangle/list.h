#pragma once

#include "rect.h"

typedef struct NODE{
    rect data;
    struct NODE* next;
}NODE;

void display_list(NODE* head);
NODE* insert_node(NODE* head, NODE* node);
void freedom(NODE* head);
