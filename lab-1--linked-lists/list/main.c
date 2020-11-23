#include <stdio.h>

#include "list.h"

int main() {
  printf("Tests for linked list implementation\n");
  list_t *myList = list_alloc();
  
  list_print(myList);
  printf("\n");
  
  list_add_to_back(myList, 6);
  list_print(myList);//  6
  printf("\n");
  
  list_add_to_back(myList, 7);
  list_print(myList);//  6 -> 7
  printf("\n");
  
  list_add_to_back(myList, 8); 
  list_print(myList);//  6 -> 7 -> 8
  printf("\n");
  
  list_add_to_back(myList, 15);
  list_print(myList); // 6 -> 7 -> 8 -> 15
  printf("\n");
  
  list_add_to_front(myList, 5);
  list_print(myList);// 5 ->  6 -> 7 -> 8 -> 15
  printf("\n");
  
  list_add_to_front(myList, 1);
  list_print(myList);// 1 -> 5 ->  6 -> 7 -> 8 -> 15
  printf("\n");
  
  list_remove_from_back(myList);
  list_print(myList);// 1 -> 5 ->  6 -> 7 -> 8
  printf("\n");
  
  list_remove_from_front(myList);
  list_print(myList); //5 ->  6 -> 7 -> 8
  printf("\n");
  
  list_add_at_index(myList, 9, 3);
  list_print(myList);
  printf("\n");
  
  list_remove_at_index(myList, 2);
  list_print(myList);
  printf("\n");
  
  list_is_in(myList, 3);
  list_is_in(myList, 6);
  list_get_elem_at(myList, 3);
  printf("\n");
  list_get_index_of(myList, 6);
  printf("\n");
  
  return 0;
}
