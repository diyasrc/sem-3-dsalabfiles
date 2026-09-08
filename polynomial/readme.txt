Find the definite integrate a given polynomial.

step 1 :
In term.h and term.c, change the coefficient to double

step 2 :
Add this function in term.h and term.c
void integrate_term(term_t* ptr_term, term_t* ptr_integrated_term);

step 3 :
Write a function in poly.h and poly.c to integrate the polynomial
change the eval function to return a double.

step 4 :
In the client.c
create one more polynomial to hold the result of integration
call a function of polynomial to integrate and give a polynomial
	without the constant of integration
evaluate this polynomial at upper limit and at lower limit and 
	find the difference.
that is the result.

// Errors I faced: undefined reference to `pow' --> solution: -lm flag while compiling
