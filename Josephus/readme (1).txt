Josephus problem:
step 1:
This appears differently in the literature.
The problem is :
 a number of people(say n) are standing in a circle waiting to be executed. 
 Counting begins at a specified point in the circle and 
 proceeds around the circle in a specified direction. 
 After a specified number of people(say k) are skipped, 
 the next person is executed. The procedure is repeated 
 with the remaining people, starting with the next person, 
 going in the same direction and skipping the same number of people, 
 until only one person remains, and is freed.
 
 Implement the solution for this problem using a circular list.
 
Josephus algorithm:
 step 1:
 a) use the circular list provided (clist.h clist.c).
    add a function to remove the node after the current node 
 b) write a function to locate kth node for removal 
    Remove the node using the earlier function 
 c) Write a client program which reads a number n. Creates a circular 
    list of nodes having numbers from 1 to n. 
    Read a number k. Repeatedly ask circular list to remove kth element 
	n - 1 times.
 d) display the list having one element.
 
 TODO:
 modify the three functions:
 1. void deinit(clist_t *ptr_clist) --> using the joesphus algorithm as described above, perform find_kth and() delete() functions.
 2. int delete(clist_t *ptr_clist) --> deletes the 'current' node of clist, and performs wrap-around.
 3. void find_kth(clist_t* ptr_list, int k) --> moves (rotates the list k times)
 

step 2 :
In each node, apart from the number store a name.
So you will input n names.
On removal, you will display the name each time.
At the end, you will give the name of the survivor 

