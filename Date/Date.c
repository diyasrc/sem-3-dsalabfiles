#include <stdio.h>
#include "Date.h"

void setDate(int dt, int mnth, int yr, Date * today){
    today->date = dt;
    today->month = mnth;
    today->year = yr;

}

void displayDate(Date* day){
    printf("%d/%d/%d\n", day->date, day->month, day->year);
}
