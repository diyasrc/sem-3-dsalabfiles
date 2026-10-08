#include "clist.h"
#include <stdlib.h>
#include <stdio.h>
#include "job.h"

#define TIMESLICE 2

node_t* initScheduler(const char *inputfilename);
void completeJob(node_t* current_job);
node_t* removeJob(node_t* current_job);
node_t* keepJob(node_t* current_job);


int main(void){
    node_t* current_job = initScheduler("input.txt");
    printf("Job List Initialised.\n\n");

    while(current_job!=NULL){
        completeJob(current_job);
        dispJob(current_job->data);
        if (current_job->data.timeAllotted >= current_job->data.completionTime){
            current_job = removeJob(current_job);
            printf("Action: removed.\n");
        }
        else{
            current_job = keepJob(current_job);
            printf("Action: kept.\n");
        }
        printf("\n");
    }
    return 0;
}

node_t* initScheduler(const char *inputfilename){
    FILE* fobj = fopen(inputfilename, "r");
    if(fobj == NULL){
        printf("Error Opening file.\n");
        exit(1);
    }
    job_t job;
    int i = 0;
    node_t* head;
    while(fscanf(fobj, "%s %d", job.jobName, &(job.completionTime)) == 2){
        job.jobID = i;
        job.timeAllotted = 0;
        if(i==0){
                head = InitialiseCLL(head, job);
        }
        else{
            head = InsertNode(head, job);
        }
        i++;
    }
    return head;
}

void completeJob(node_t* current_job){
    current_job->data.timeAllotted += TIMESLICE;
}

node_t* removeJob(node_t* current_job){
    return DelNode(current_job);
}

node_t* keepJob(node_t* current_job){
    return current_job->next;
}
