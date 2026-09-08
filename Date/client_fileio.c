#include <stdio.h>
#include <stdlib.h>
#include "Date.h"
#include "event.h"


#define MAX 20

void disp_all(Event e[], int n);
int read_all(FILE *fp, Event e[], int n);
Event latest_event(Event e[], int count);
int num_of_events(Event e[], int n, int max);

int main(void){

    Event events[MAX];

    FILE* fp = fopen("Data3.txt", "r");
    int tcount = read_all(fp, events, MAX);
    Event latest = latest_event(events, tcount);

    disp_all(events, tcount);
    printf("\n\nLatest Event : \n");
    displayEvent(&latest);

    int mn;
    printf("Enter month number:");
    scanf("%02d", &mn);
    int num = num_of_events(events, mn, tcount);
    printf("Number of Events in month=%d\n", num);
    fclose(fp);

    return 0;
}

int read_all(FILE *fp, Event e[], int n){
    char detail[50];
    int date, mnth, year;
    int i=0;
    while(fscanf(fp, "%d %d %d %49s", &date, &mnth, &year, detail)==4){

        setDate(date, mnth, year, &e[i].date);
        setEvent(&e[i], detail, &e[i].date);
        i++;
        if(i>=MAX){
            printf("Too many entries\n");
            break;
        }
    }
    return i;
}

void disp_all(Event e[], int n){
    int i = 0;
    for(i = 0; i<n; i++){
        displayEvent(&e[i]);
    }
}

Event latest_event(Event e[], int count){
    Event latest = e[0];
    for(int i = 1; i < count; i++){
        if (latest.date.year < e[i].date.year){
            latest = e[i];
        }
        else if (latest.date.year == e[i].date.year){
            if(latest.date.month < e[i].date.month){
                latest = e[i];
            }
            else if (latest.date.month == e[i].date.month){
                if (latest.date.date < e[i].date.date){
                    latest = e[i];
                }

            }
        }
    }
    return latest;
}

int num_of_events(Event e[], int n, int max){
    int a = 0;
    for (int i = 0; i<max; i++){
        if(e[i].date.month == n) a++;
    }
    return a;
}
