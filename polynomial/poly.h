#pragma once

#include "term.h"

typedef struct list_t{
    term_t term;
    struct list_t* next;
}list_t;

list_t* insert(list_t* head, term_t);
void displayList(list_t* head);
list_t* integrate(list_t* head);
double eval(list_t* head, double upL, double lowL);
void destroyList(list_t* head);


/* Codes from EL:
list_t* d_dx(list_t* head);
list_t* copy_lt(list_t* head);
double evaluate(list_t* head, double x);
*/
