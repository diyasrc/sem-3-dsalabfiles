#pragma once

#include "Date.h"

typedef struct{
    Date date;
    char* details;
}Event;

void displayEvent(Event * evnt);
void setEvent(Event* evnt, char* detail, Date * dt);

