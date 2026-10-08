#include "job.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

job_t JobInit(int ID, char* name, int completionTime, int timealloted){
    job_t* job = malloc(sizeof(job_t));
    job->jobID = ID;
    strcpy(job->jobName, name);
    job->completionTime =completionTime;
    job->timeAllotted = timealloted;
    return *job;
}

void dispJob(job_t job){
    printf("Job ID: %d\nJob Name: %s\nCompletionTime: %d\ntimeAlloted: %d\n", job.jobID, job.jobName, job.completionTime, job.timeAllotted);
}
