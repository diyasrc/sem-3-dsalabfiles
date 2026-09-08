#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "rect.h"


int main(void){
    // 1. Step 1:
    printf("Problem statement 1:\n");
    rect r;
    setRect(&r, 10, 5);
    printf("Area = %d\n\n", area(r));

    // 2. Step2:
    printf("Problem statement 2: \n");
    int n;
    printf("Enter number of rectangles: ");
    scanf("%d", &n);
    if(n<=0){
        printf("terminated\n");
        return 1;
    }

    int i = 1;
    int l,b;
    printf("Enter length and bread of rectangle %d: ", i);
    scanf("%d %d", &l, &b);
    NODE* head = malloc(sizeof(NODE));
    if(head==NULL){
        printf("Error\n");
        return -1;
    }
    head->data.length = l;
    head->data.breadth = b;
    head->next = NULL;
    i++;
    while(i<=n){
        printf("Enter length and bread of rectangle %d: ", i);
        scanf("%d %d", &l, &b);
        NODE* node= malloc(sizeof(NODE));
        if(node==NULL){
            printf("Error\n");
            return -1;
        }
        node->data.length = l;
        node->data.breadth = b;
        head = insert_node(head, node);
        i++;
    }

    display_list(head);
    freedom(head);
    return 0;
}
