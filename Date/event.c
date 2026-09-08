#include <stdio.h>
#include <stdlib.h>
#include "event.h"


void setEvent(Event* evnt, char* detail, Date * dt){
    evnt -> details = detail;
    evnt -> date = *dt;
}

void displayEvent(Event* evnt){
    printf("Event Details = %s\n", evnt -> details);
    printf("Event date = ");
    Date* dt = &(evnt -> date);
    displayDate(dt);
    printf("\n");
}
