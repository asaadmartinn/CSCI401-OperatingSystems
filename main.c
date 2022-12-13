#include <stdio.h>
#include "list.h"
#include <stdbool.h>

int main() 
{
  printf("Write your Tests for your linked list implementation\n");
  

  list_t *mylist;
  
  mylist = (list_t*)list_alloc();
  list_print(mylist);

  list_add_to_front(mylist,7);
  list_add_to_front(mylist,8);
  list_add_to_front(mylist,9);
  list_add_to_front(mylist,10);
  printf("After add to front: \n");
  list_print(mylist);

  list_add_to_back(mylist,11);
  list_add_to_back(mylist,12);
  list_add_to_back(mylist,13);
  printf("After add to back: \n");
  list_print(mylist);

  printf("Length of list: %d\n",list_length(mylist));
  printf("Testing list_is_in for value 11: %d\n\n", list_is_in(mylist,11));

  list_remove_from_back(mylist);
  list_remove_from_back(mylist);
  printf("After remove from back: \n");
  list_print(mylist);

  list_remove_from_front(mylist);
  printf("After remove from front: \n");
  list_print(mylist);

  printf("Length of list: %d\n\n",list_length(mylist));

  list_add_at_index(mylist,12,2);
  printf("After adding 12 at index 2: \n");
  list_print(mylist);

  list_add_at_index(mylist,3,1);
  printf("After adding 3 at index 1: \n");
  list_print(mylist);

  printf("\nTesting get elem at index 0: %d\n",list_get_elem_at(mylist,0));
  printf("Testing get elem at index 1: %d\n",list_get_elem_at(mylist,1));
  printf("Testing get elem at index 3: %d\n\n",list_get_elem_at(mylist,3));


  printf("Testing list get index of value 8: %d\n", list_get_index_of(mylist,8));
  printf("Testing list get index of value 7: %d\n", list_get_index_of(mylist,7));
  printf("Testing list get index of value 9: %d\n\n", list_get_index_of(mylist,9));


  list_remove_at_index(mylist,0);
  printf("After remove at index 0: \n");
  list_print(mylist);

  list_remove_at_index(mylist,3);
  printf("After remove at index 3: \n");
  list_print(mylist);

  list_remove_at_index(mylist,1);
  printf("After remove at index 1: \n");
  list_print(mylist);

  


 
}