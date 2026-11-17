#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

void init_hash_table(hash_table_t *ptr_hash_table)
{
	for(int i = 0; i < TABLESIZE; ++i)
	{
		ptr_hash_table->head_[i] = NULL;
	}
	
}

void deinit_hash_table(hash_table_t *ptr_hash_table)
{
	hash_node* pres;
	for(int index = 0; index < TABLESIZE; ++index)
	{
		hash_node* temp = ptr_hash_table->head_[index];
		while(temp)
		{
			pres = temp;
			temp = temp->next_;
			free(pres);
		}
	}
	for(int i = 0; i < TABLESIZE; ++i)
	{
		ptr_hash_table->head_[i] = NULL;
	}
}

hash_node* make_node(int key, char word[])
{
	hash_node* temp = (hash_node*)malloc(sizeof(hash_node));
	temp->key_ = key;
	strcpy(temp->word_, word);
	temp->next_ = NULL;
	return temp;
}

void insert_word(hash_table_t *ptr_hash_table, hash_node* node)
{
	int index = node->key_ % TABLESIZE;
	
	node->next_ = ptr_hash_table->head_[index];
	ptr_hash_table->head_[index] = node;

}

void delete_key(hash_table_t *ptr_hash_table, int key)
{
	int index = key % TABLESIZE;
	hash_node* pres = ptr_hash_table->head_[index];
	hash_node* prev = NULL;
	while(pres != NULL && pres->key_ != key)
	{
		prev = pres;
		pres = pres->next_;
	}
	if(pres != NULL)
	{
		printf("Deleting %s\n", pres->word_);
		if(prev == NULL)
		{
			ptr_hash_table->head_[index] = pres->next_;
		}
		else 
		{
			prev->next_ = pres->next_;
		}
		free(pres);
	}
	else 
	{
		printf("key not found to delete\n");
	}
}

void disp_hash_table(hash_table_t *ptr_hash_table)
{
	for(int index = 0; index < TABLESIZE; ++index)
	{
		hash_node* temp = ptr_hash_table->head_[index];
		if(temp)
		{
			printf("index : %d\n",  index);
		}
		while(temp)
		{
			printf("key : %d word : %s\n", temp->key_, temp->word_);
			temp = temp->next_;
		}
		
	}
}

int search(hash_table_t *ptr_hash_table, int key)
{
	int index = key % TABLESIZE;
	hash_node* temp = ptr_hash_table->head_[index];
	while(temp != NULL && temp->key_ != key)
	{
		temp = temp->next_;
	}
	return (temp == NULL) ? -1 : index;
}
