Lab 1 :
List:
Given to students : 
Implementation of an ordered list of integer
Problem statement :
Create an ordered list of sites of a layout based on the area.

step 1:
create a rectangle :

To make the problem simple, each site is considered a rectangle
with length and breadth.
- create a structure called rect with fields lenght and breadth.
- develop functions to set and display the rectangle
- develop function to find the area
- test this.
you will create :
rect.h 
rect.c
client_rect.c 
The client_rect.c will read the dimension from a key board.


step 2 :
create the list of rectangles :

Modify the given ordered list program.

picked from session1 of day1 of FDP.

replace key_ in node_t structure by struct representing rectangle.
modify the display function to call display of rectangle to 
	display the rectangle 
modify the insert function 
	given length and breadth by the client - 
	create a rectangle - 
	set the length and breadth
	Replace comparison of keys by a function on rectangle structure	
		which returns true if the first rect is smaller than the second
	So, in rectangle structure, implement the function to compare 
		rectangles based on area .
		
client program will read dimensions of # of rectangles and insert 
	them to the list of rectangles. These dimensions may not be unique.
	
So, you will have 5 files.
a) rect.h 
b) rect.c 
c) list.h 
d) list.c 
e) client.c 


// additional problem :
1. Given the value of a unit of area, find the value of the total 
layout having # of sites 
2. Given the list, find the site with the highest length 
3. Given the list, find the site with the least breadth
