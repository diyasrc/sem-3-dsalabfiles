#include "lru.h"

static node_t* create_node(int key){
    node_t *temp;
    temp = (node_t*)malloc(sizeof(node_t));

    // one of the possible ways of handling an exceptional case
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->key_ = key;
    temp->prevd_ = NULL;
    temp->nextd_ = NULL;
    return temp;
}


void init_pt(page_table* ptr){
    init_dll(&(ptr->dll));
    init_hash_table(&(ptr->hasht));
}
page* init_page(char* details, int key){
    page* ptr = malloc(sizeof(page));
    ptr -> key_ = key;
    ptr -> dllcomp = create_node(key);
    ptr -> hashcomp = make_node(key, details);
    return ptr;
}

//dlu func:
void on_access(page_table* ptr, page* page){
    node_t* key = search_dll(&(ptr->dll), *(page->dllcomp));
    move_to_front(&(ptr->dll), key);
}

//dlu func:
void on_insert(page_table* ptr, page* page){
    if(ptr->dll.size_ == SIZE){
        delete_end(&(ptr->dll));
        insert_begin(&(ptr -> dll), page->dllcomp);
        delete_key(&(ptr->hasht), page->key_);
    }
    else{
        insert_begin(&(ptr -> dll), page->dllcomp);
    }
}

//hash func:
void insert(page_table* ptr, char* details, int key){
    page * NewP = init_page(details, key);
    insert_word(&(ptr->hasht), NewP->hashcomp);
    on_insert(ptr, NewP);
}
//hash func:
int access(page_table* ptr, page* page){
    int loc = search(&(ptr -> hasht), page->key_);
    if(loc == -1){
        printf("notfound\n");
    }
    else{
        on_access(ptr, page);
    }
    return loc;
}

void display_page_table(page_table* ptr){
    disp_forward(&(ptr->dll));
    disp_hash_table(&(ptr->hasht));
}

void deinit_pt(page_table* ptr){
    deinit_dll(&(ptr->dll));
    deinit_hash_table(&(ptr->hasht));
}
