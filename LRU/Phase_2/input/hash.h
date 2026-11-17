#pragma once
#define WORDSIZE 100
#define TABLESIZE 19
typedef struct hash_node
{
   int key_;
   char word_[WORDSIZE];
   struct hash_node *next_;
}hash_node;

typedef struct hash_table_t
{
  struct hash_node *head_[TABLESIZE];
  
}hash_table_t;

void init_hash_table(hash_table_t *ptr_hash);
void deinit_hash_table(hash_table_t *ptr_hash);
void insert_word(hash_table_t *ptr_hash_table, hash_node* node);
void delete_key(hash_table_t *ptr_hash, int key);
void disp_hash_table(hash_table_t *ptr_hash);
int search(hash_table_t *ptr_hash, int key);
hash_node* make_node(int key, char word[]);
