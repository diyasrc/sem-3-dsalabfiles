#ifndef CLIST_H
#define CLIST_H 
struct node 
{
	int key_;
	struct node *next_;
};
typedef struct node node_t;

struct clist 
{
	node_t* current_; 
};
typedef struct clist clist_t;

#define K 2

void init(clist_t *ptr_clist);
void add(clist_t *ptr_clist, int key);
void disp(clist_t *ptr_list);

// implement the following
void deinit(clist_t *ptr_list);  
int delete(clist_t *ptr_clist);
void find_kth(clist_t* ptr_list, int k);
#endif
