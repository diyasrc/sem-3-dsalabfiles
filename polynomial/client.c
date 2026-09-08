#include <stdio.h>
#include <stdlib.h>
#include "term.h"
#include "poly.h"

int main(void){
    char* eqn_s= "5x^4 + 3x^2 + -7x^1 + 10x^0";

    //CREATION:
    list_t* head = malloc(sizeof(list_t));
    head->next = NULL;
    head->term = setTerm(eqn_s);
    char* p;
    p = eqn_s;
    term_t term;
    while(*p != '\0'){
        if (*p == '+'){
            p++;
            term = setTerm(p);
            head = insert(head, term);
        }
        p++;
    }

    //INTEGRATION:
    printf("Integrated: ");
    list_t* integ = integrate(head);
    displayList(integ);

    //EVALUATION:
    double res = eval(integ, 2, 1);
    printf("Result after evaluation: %.2f \n", res);


    destroyList(head);
    destroyList(integ);

    return 0;
}
