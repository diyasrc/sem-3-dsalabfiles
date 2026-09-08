#pragma once

typedef struct{
    double coefficient;
    double exponent;
}term_t;

term_t setTerm(char* string);
void displayTerm(term_t term);
double compareTerm(term_t term1, term_t term2);
double evaluateTerm(term_t t, int x);
term_t integrate_term(term_t trm);

/* CODES FROM EL:
term_t differentiate(term_t trm);
*/
