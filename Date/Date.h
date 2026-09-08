#ifndef DATA_H
#define DATA_H

typedef struct{
    int date;
    int month;
    int year;
}Date;

void setDate(int dt, int mnth, int yr, Date * today);
void displayDate(Date* day);

#endif

