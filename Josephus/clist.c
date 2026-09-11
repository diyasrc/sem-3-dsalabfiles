#include <stdio.h> 
#include <stdlib.h>
#include "clist.h" 

void init(clist_t *ptr_clist)
{
	ptr_clist->current_ = NULL;
}

void add(clist_t *ptr_clist, int key)
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	temp->key_ = key;
	if(temp == NULL)
	{
		printf("full\n"); exit(1);
	}
	if(ptr_clist->current_ == NULL)
	{
		ptr_clist->current_ = temp;
		temp->next_ = temp;
	}
	else 
	{
		temp->next_ = ptr_clist->current_->next_;
		ptr_clist->current_->next_ = temp;
	}
	ptr_clist->current_ = ptr_clist->current_->next_;
} 


void disp(clist_t *ptr_clist)
{
	node_t* pres = ptr_clist->current_;
	if(pres != NULL)
	{
		do 
		{
			pres = pres->next_;
			printf("%d ", pres->key_);
		} 	while(pres != ptr_clist->current_);
	}
	printf("\n");
	
}

// TODO : delete all the nodes
void deinit(clist_t *ptr_clist)
{
	int k = K;
	while(ptr_clist->current_->next_ != ptr_clist->current_){
		find_kth(ptr_clist, k);
		printf("Current: %d Removed: %d\n",  ptr_clist->current_->key_, delete(ptr_clist));

		disp(ptr_clist);
	}
	printf("Survivor: %d\n", ptr_clist->current_->key_);
}

// TODO : add this function : list is rotated k-1 times, kth element must be deleted. also, this implies kth element is 'prev' and k+1th element is 'next' (for wrap-around). also, now, the current pointer shd point to the 'next' element.

int delete(clist_t *ptr_clist)
{
	node_t* prev = ptr_clist->current_;
	node_t* temp = prev->next_;
	prev->next_ = temp->next_;
	int val = temp->key_;
	free(temp);
	ptr_clist -> current_ = prev;
	return val;
}

// TODO : move k-1 times
void find_kth(clist_t* ptr_list, int k)
{
	node_t* ptr = ptr_list->current_;
	int i = 1;
	while(i != k-1){
		ptr = ptr -> next_;
		i++;
	}
	ptr_list -> current_ = ptr -> next_;
	return;
}
