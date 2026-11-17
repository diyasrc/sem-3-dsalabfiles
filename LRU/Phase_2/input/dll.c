#include <stdio.h>
#include <stdlib.h>
#include "dll.h"


void init_dll(dll_t *ptr_dll)
{
	ptr_dll->head_ = ptr_dll->tail_ = NULL;
	ptr_dll->size_ = 0;
}

void deinit_dll(dll_t *ptr_dll)
{
	node_t* pres = ptr_dll->head_;
	while(pres != NULL)
	{
		node_t* temp = pres;
		pres = pres->nextd_;
		free(temp);
	}
	ptr_dll->head_ = ptr_dll->tail_ = NULL;
}

/* Insert at the beginning */
void insert_begin(dll_t *ptr_dll, node_t *node)
{
	node->prevd_ = NULL;
	node->nextd_ = ptr_dll->head_;

	if (ptr_dll->head_ == NULL)
		ptr_dll->tail_ = node;          /* list was empty */
		else
			ptr_dll->head_->prevd_ = node;

	ptr_dll->head_ = node;
	ptr_dll->size_++;
}



/* Display from left to right */
void disp_forward(dll_t *ptr_dll)
{
    node_t *temp = ptr_dll->head_;
    printf("Forward: ");
    while (temp != ptr_dll->tail_) {
        printf("%d ", temp->key_);
        temp = temp->nextd_;
    }
    printf("%d ", temp->key_);
    printf("\n");
}

/* Delete from end */
void delete_end(dll_t *ptr_dll)
{
    node_t *temp = ptr_dll->tail_;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
	ptr_dll->tail_ = temp->prevd_;
	if(ptr_dll->tail_ == NULL)
		ptr_dll->head_ = NULL;
 	else
		ptr_dll->tail_->nextd_ = NULL;
	free(temp);
	ptr_dll->size_--;
}

node_t* search_dll(dll_t *ptr_dll, node_t key)
{
	node_t *temp = ptr_dll->head_;
    while (temp != NULL && temp->key_ != key.key_)
	{
         temp = temp->nextd_;
    }
    return temp;
}

void move_to_front(dll_t* ptr, node_t* node_k){
	node_t* temp = ptr->head_;
	while(temp -> nextd_-> key_ != node_k->key_){
		temp = temp->nextd_;
	}
	temp->nextd_ = temp->nextd_->nextd_;
	node_k->nextd_ = ptr->head_;
	if (temp->nextd_ == NULL){
		ptr->tail_ = temp;
	}
	else{
		temp->nextd_->prevd_ = temp;
	}
	ptr->head_ = node_k;
}




