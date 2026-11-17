#pragma once
#define SIZE 3
typedef struct node_t {

    int key_;
    struct node_t *prevd_;
    struct node_t *nextd_;
} node_t;

typedef struct{
	node_t *head_;
	node_t *tail_;
	int size_;
}dll_t;

void init_dll(dll_t *ptr_dll);
void deinit_dll(dll_t *ptr_dll);
void insert_begin(dll_t *ptr_dll, node_t *node);
void disp_forward(dll_t *ptr_dll);
void delete_end(dll_t *ptr_dll);
node_t* search_dll(dll_t *ptr_dll, node_t key);
void move_to_front(dll_t* ptr, node_t* node_k);

