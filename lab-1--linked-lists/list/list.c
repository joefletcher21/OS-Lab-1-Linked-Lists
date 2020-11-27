// list/list.c
// 
// Implementation for linked list.
//
// Joseph Fletcher
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t *list_alloc() {
  list_t *list = (list_t*) malloc(sizeof(list_t));
  list->head = NULL;
  return list;
}

void list_print(list_t *l) {
  node_t *curr_node;
  curr_node = l->head;
  
  if (curr_node == NULL){
    printf("list is empty\n");
  }
  
  while (curr_node != NULL){
    printf("%d -> ", curr_node->value);
    curr_node = curr_node->next;
  }
}

//keeps track of how long linked list is by counting nodes
int list_length(list_t *l) {
  node_t* curr_node = l->head;
  int count = 0;
  while (curr_node != NULL) {
    count++;
    curr_node = curr_node->next;
  }
  return count;
};

/* the user should be able to allocate and free 
 * all the memory required for this linked list library.*/
void list_free(list_t *l) {
  free(l);
};

void list_add_to_back(list_t *l, elem value){  
  node_t *curr_node;
  node_t *new_node = (node_t*)malloc(sizeof(node_t));
  
  new_node->value = value;
  new_node->next = NULL;
  
  if(l->head == NULL){
    l->head = new_node;
  }
  else{
    curr_node = l->head;
    while(curr_node->next != NULL){
      curr_node = curr_node->next;
    }
    curr_node->next = new_node;
  }
}

void list_add_to_front(list_t *l, elem value){
  node_t *curr_node;
  node_t *new_node = (node_t*)malloc(sizeof(node_t));
  
  new_node->value = value;
  new_node->next = NULL;
  
  if(l->head == NULL){
    l->head = new_node;
  }
  
  else{
    node_t *curr_node = l->head;
    new_node->next= l->head;
    l->head = new_node;
  }
}

// Adds a node at specified index. Does nothing if index out of bounds.
void list_add_at_index(list_t *l, elem value, int index) {
 
  //node_t *current_node;
  node_t *new_node = (node_t*)malloc(sizeof(node_t));
  node_t *prev_node = (node_t*)malloc(sizeof(node_t));
  node_t *curr_node = l->head;
  
  new_node->value = value;
  new_node->next = NULL;
 
  if (index < 0) {
    printf("Invalid Index\n");
  }
 
  if (index == 0) {
    new_node->next = l->head->next;
    l->head = new_node;
  }
 
  int i = 0;
 
  if(index > 0) {
    while(i + 1 < index) {
      curr_node = curr_node->next;
      if (curr_node->next == NULL) {
        break;
      }
      i++;
    }
   new_node->next = curr_node->next;
   curr_node->next = new_node;
  }
};

elem list_remove_from_back(list_t *l){
  node_t* curr_node = l->head;
  
  if(l->head != NULL) {
    int i = 0;
    while(i < list_length(l)-2) {
      curr_node = curr_node->next;
      i++;
    }
    int value = curr_node->next->value;
    free(curr_node->next);
    curr_node->next = NULL;
    return value;
  } 
};

elem list_remove_from_front(list_t *l) {
  if (l->head != NULL) {
    node_t* curr_node = l->head;
    int value = curr_node->value;
    l->head = l->head->next;
    free(curr_node);
    return value;
  }
};

elem list_remove_at_index(list_t *l, int index) { 
  //iterate through the list
  int i = 0;
  
  //create a counter for the specified element
  //must be one less than the specified element (like in add to index)
  elem value = (elem) -1;
  
  //Check to see if list is empty
  if(l->head == NULL){
    return value;
  }
  //If the index = 0, then use list_remove_from_front function
  if (index == 0){
    return list_remove_from_front(l);
  }
  if (index > 0){
    //point to the head of the list
    node_t *curr_node = l->head;
    //keep track of the temp and current node
    node_t *temp_node = curr_node;
    
    //Make sure that the current node isn't at the end of the list
    while(curr_node != NULL){
      //Check to see if the index is at the same position as the counter
      if(i == index){
        value = curr_node->value; 
        temp_node->next = curr_node->next;
        free(curr_node);
        break;
      }
      else {
         temp_node = curr_node;
         curr_node = curr_node->next;
         i++;
      }
    }
  }
  return value;
};

/* Checks to see if the given intent exists in the list. DONE*/
bool list_is_in(list_t *l, elem value){
  node_t* curr_node = l->head;
  while (curr_node != NULL) {
    if (curr_node->value == value){
      printf("%d is in the list \n", value);
      return true;
    }
    curr_node = curr_node->next;
  }
  printf("%d is not in the list \n", value);
  return false;
};

/* Returns the intent at the given index. DONE*/
elem list_get_elem_at(list_t *l, int index) { 
  int i = 0;
  elem value = (elem) -1;
  node_t *curr_node = l->head;
  
  while (curr_node != NULL){
    if (i == index){
      value = curr_node->value;
      printf("The number is %d.", value);
      return value;
    }
    curr_node = curr_node->next;
    i++;
  }
}

/* Returns the index at which the given intent appears. DONE*/
int list_get_index_of(list_t *l, elem value) {
  int i = 0;
  node_t* curr_node = l->head;
  while (curr_node != NULL) {
    if (curr_node->value == value){
      printf("The number is at index %d.", i);
      return i;
    }
    curr_node = curr_node->next;
    i++;
  }
};
