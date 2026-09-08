#include <stdio.h>
#include <stdlib.h>
#include "Date.h"

int main(void){
    int month, day, year;
    printf("Enter Date: ");
    scanf("%02d",&day);
    printf("Enter month: ");
    scanf("%02d", &month);
    printf("Enter Year: ");
    scanf("%04d", &year);

    Date* today = malloc(sizeof(Date));

    setDate(day, month, year, today);

    displayDate(today);
    free(today);
    return 0;

}
