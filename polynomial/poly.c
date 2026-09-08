#include <stdlib.h>
#include <stdio.h>
#include "term.h"
#include "poly.h"

list_t* insert(list_t* head, term_t term){
    list_t* NewTerm = malloc(sizeof(list_t));
    NewTerm->term = term;
    NewTerm->next = NULL;
    list_t* ptr = head;

    if (compareTerm(ptr->term, term) < 0){
        NewTerm->next = head;
        return NewTerm;
    }
    while((ptr -> next != NULL) && (compareTerm(ptr->next->term, term) > 0)){
        ptr = ptr->next;
    }
    list_t* nxt = ptr->next;
    ptr->next = NewTerm;
    NewTerm -> next = nxt;

    return head;
}

void displayList(list_t* head){
    list_t* ptr = head;
    while(ptr!=NULL){
        printf(" +");
        displayTerm(ptr->term);
        ptr = ptr->next;
    }
    printf("\n");
}

double evaluate(list_t* head, double x){
    list_t* ptr = head;
    double num = 0;
    while(ptr != NULL){

        num += evaluateTerm(ptr->term, x);
        //printf("+%d ", evaluateTerm(ptr->term, x));
        ptr = ptr->next;
    }
    //printf("\n");
    return num;
}

list_t* integrate(list_t* head){

    list_t* ptr = head;
    list_t* ip = malloc(sizeof(list_t));
    ip->next = NULL;
    ip->term = integrate_term(ptr->term);
    ptr = ptr->next;
    term_t t;

    while(ptr!=NULL){
        t = integrate_term(ptr->term);
        if(t.coefficient==0){
            break;
        }
        ip = insert(ip, t);
        ptr = ptr->next;
    }

    return ip;
}

double eval(list_t* head, double upL, double lowL){
    double result = evaluate(head, upL) - evaluate(head, lowL);
    return result;
}

void destroyList(list_t* head){
    list_t* tmp;
    while(head!=NULL){
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

/* CODES FROM EL:

list_t* copy_lt(list_t* head){

    list_t* ptr = head;
    list_t* cp = malloc(sizeof(list_t));
    cp->next = NULL;
    cp->term = ptr->term;
    ptr = ptr->next;

    while(ptr!=NULL){
        cp = insert(cp, ptr->term);
        ptr = ptr->next;
    }

    return cp;
}

list_t* d_dx(list_t* head){

    list_t* ptr = head;
    list_t* dp = malloc(sizeof(list_t));
    dp->next = NULL;
    dp->term = differentiate(ptr->term);
    ptr = ptr->next;
    term_t t;

    while(ptr!=NULL){
        t = differentiate(ptr->term);
        if(t.coefficient==0){
            break;
        }
        dp = insert(dp, t);
        ptr = ptr->next;
    }

    return dp;
}
*/
