#pragma once

typedef struct{
    int length;
    int breadth;
}rect;


void setRect(rect *r, int length, int breadth);
void displayRect(rect r);
int area(rect r);
unsigned int isSmaller(rect a, rect b);
