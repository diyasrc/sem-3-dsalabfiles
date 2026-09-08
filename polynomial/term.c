#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "term.h"
#include <math.h>

term_t setTerm(char* string){
    term_t Term;
    char* i = string;
    double number = atoi(i);
    Term.coefficient = number;

    while(*i != '^'){
        i++;
    }
    i++;
    number = 0;
    number = atoi(i);
    if(number < 0){
        Term.exponent = -2;
        printf("Error, Invalid Term.");
    }
    Term.exponent = number;
    return Term;
}

void displayTerm(term_t term){
    if (term.exponent != 0)
        printf(" %.2fx^%.2f", term.coefficient, term.exponent);
    else
        printf(" %.2f", term.coefficient);
}

double compareTerm(term_t term1, term_t term2){
    return (term1.exponent - term2.exponent);
}

double evaluateTerm(term_t t, int x){
    double number = 0;
    number = (t.exponent == 0)? 1 : pow(x, t.exponent);
    number = t.coefficient * number;
    return number;
}

term_t integrate_term(term_t trm){
    term_t itrm;
    itrm.exponent = trm.exponent + 1;
    itrm.coefficient = trm.coefficient/itrm.exponent;
    return itrm;
}

/* CODES FROM EL:
term_t differentiate(term_t trm){
    term_t dtrm;
    if(trm.exponent == 0){
        dtrm.coefficient =0;
        dtrm.exponent = 0;
        return dtrm;
    }
    dtrm.coefficient = trm.exponent*trm.coefficient;
    dtrm.exponent = trm.exponent -1;
    return dtrm;
}
*/
