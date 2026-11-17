#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "dll.h"

typedef struct{
    hash_table_t hasht;
    dll_t dll;
}page_table;

typedef struct page{
    int key_;
    hash_node* hashcomp;
    node_t* dllcomp;
}page;

void init_pt(page_table* ptr);
page* init_page(char* details, int key);
int access(page_table* ptr, page* page);
void insert(page_table* ptr, char* details, int key);
void on_insert(page_table* ptr, page* page);
void on_access(page_table* ptr, page* page);
void display_page_table(page_table* ptr);
void deinit_pt(page_table* ptr);
