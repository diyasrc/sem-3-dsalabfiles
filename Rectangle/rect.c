#include <stdio.h>
#include "rect.h"

void setRect(rect *r, int length, int breadth){
    r->length = length;
    r->breadth = breadth;
}
void displayRect(rect r){
    printf("length = %d\nbreadth = %d\n", r.length, r.breadth);
}
int area(rect r){
    return (r.length)*(r.breadth);
}

unsigned int isSmaller(rect a, rect b){
    if (area(a) <= area(b))
    {
        return 1;
    }
    else return 0;
}
