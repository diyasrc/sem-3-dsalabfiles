#include <stdio.h>
#include "lru.h"

int main()
{
	page_table* pt = malloc(sizeof(page_table));
	init_pt(pt);
	printf("initialised\n");

	insert(pt, "A", 1);
	insert(pt, "B", 2);
	printf("Original: ");
	display_page_table(pt);
	printf("\n");

	//Space is there, inserted to front
	insert(pt, "C", 3);
	printf("Space is there, inserted to front: ");
	display_page_table(pt);
	printf("\n");

	//No space, removed last (A,1), and inserted to front
	insert(pt, "D", 4);
	printf("No space, removed last, and inserted to front: ");
	display_page_table(pt);
	printf("\n");

	//creating page (B,2)
	page* B = init_page("B", 2);
	//Accessed last(B,2), moved to front, also access returns key of element from hash table, if exists, if doesn't returns -1
	int loc = access(pt, B);
	printf("Once accessed, moved to front; key of accessed = %d\n", loc);
	display_page_table(pt);
	printf("\n");

	//Attempt at accessing element that does not exist
	page* E = init_page("E", 5);
	loc = access(pt, E);
	printf("key = %d\n", loc);
	display_page_table(pt);
	printf("\n");

	deinit_pt(pt);
	free(pt);
	return 0;
}
