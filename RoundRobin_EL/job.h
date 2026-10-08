#pragma once

typedef struct{
    int jobID;
    char jobName[50];
    int completionTime;
    int timeAllotted;
}job_t;


job_t JobInit(int ID, char name[50], int completionTime, int timealloted);
void dispJob(job_t job);
