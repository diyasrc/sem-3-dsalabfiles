#include <stdio.h>
#include <stdlib.h>
#include "clist.h"

#define N 1

int main(void){

    int key = 1;
    clist_t* head = malloc(sizeof(clist_t));
    init(head);
    while(key < N+1){
        add(head, key);
        key++;
    }

    disp(head);
    //Debugging : printf("Current: %d Removed: %d\n",  head->current_->key_, head->current_->next_->key_);

    deinit(head);

    return 0;
}
