Lab 1:
play with an array of events.

Students have already developed 
1. date.h 
2. date.c 

3. event.h 
4. event.c 

We can provide these from our FDP if required.

Step 1:

Read events from a file.
Each line of the file has date(dd mm yy) and detail(string with no space).
Create an array of events.
Assume an upper limit on # of events.

a) write a function to read all the events.
Assume that there is enough space in the array to hold 
all the events. Return the number of events read. 
int read_all(FILE *fp, event_t e[], int n);

b) write a function to display all the events. 
void disp_all(event_t e[], int n);

These functions in turn call the functions of event_t and date_t.


-----------------------

step 2:
Write functions to 
a) find the latest event chronologically
This is similar to finding the biggest number in an array 

b) find the number of events in a given month

----------------------

additional problem (not for assessment)
c) remove an event(s) on  given the date.
   



