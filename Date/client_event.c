#include <stdio.h>
#include <stdlib.h>
#include "event.h"

int main(void){
    int dt, yr, mnth;
    char detail[50];
    printf("Enter Event Detail: ");
    scanf("%s", detail);
    printf("Enter Date: ");
    scanf("%d %d %d", &dt, &mnth, &yr);

    Date* date = malloc(sizeof(Date));
    setDate(dt, mnth, yr, date);

    Event* event = malloc(sizeof(Event));
    setEvent(event, detail, date);

    displayEvent(event);

    free(date);
    free(event);
    return 0;
}
