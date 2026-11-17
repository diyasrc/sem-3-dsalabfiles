implement least recently used algorithm:
Let the keys(could be page details - we will use strings) be stored 
in a doubly linked list of a particular size.
When key is accessed, move it to the front of the list.
when key is to be inserted, insert in the front if there is space.
Otherwise drop from the rear and then insert from the front.

To access the key faster, use a hash.
Given the key, the hash table will give us the location in the doubly 
linked list where the key occurs.

a)
On DLL,
implement moving the node to the front
inserting if not there in the front. if the size exceeded, remove the last
element 

b) 
provide a hash table which will give the location of the key if it exists 
in the DLL.
