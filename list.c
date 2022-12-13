//worked with amira
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#include "list.h"

list_t *list_alloc() {
  list_t* list = (list_t*)malloc(sizeof(list_t));
  list->head = NULL;
  return list;
}

node_t *node_alloc(elem value) {
  node_t* new_node = (node_t*)malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

void list_free(list_t *l) {
  free(l);
  list_alloc();
}
void node_free(node_t *n) {
  free(n);
}

void list_print(list_t *l){
  node_t *current = l->head;
  list_t *list;
  if (list == NULL){
    printf("no list.");
  }
  else if (current == NULL){
    printf("nothing to print.");
  }
  while(current != NULL){
    printf("%d ", current->value);
    current = current->next;
  }
  printf("\n");
}

elem list_length(list_t *l){
  node_t *current = l->head;
  elem count = 1;
  if (current == NULL){
    printf("no items in list, length 0.\n");
    return count;
  }
  while(current->next){
    count++;
    current = current->next;
 }
    printf("%d items in list.\n", count);
  return count;
}


void list_add_to_back(list_t *l, elem value){
  node_t *current = l->head;
  if (l->head == NULL){
    list_add_to_front(l, value);
  }
  else{
    while(current->next != NULL){
      current = current->next;
    }
    node_t *new_node = node_alloc(value);
    current->next = new_node;
    new_node->next = NULL;
  }
}

void list_add_to_front(list_t *l, elem val){
  node_t *new_node = node_alloc(val);
  new_node->next = l->head;
  l->head = new_node;
}


void list_add_at_index(list_t *l, elem value, elem index){
  node_t *new_node = node_alloc(value);
  node_t *temp = node_alloc(value);
  node_t *current;
  elem i;

  if(index ==0 && l->head != NULL){
    new_node->value = value;
    new_node->next = l->head;
    l->head = new_node;
    return;
  }
  else if(l->head == NULL){
    new_node->value = value;
    new_node->next = NULL;
    l->head = new_node;
    return;
  }
  else{
    i = 0;
    new_node->value = value;

    temp = l->head,current = l->head->next;
    while(i != index - 1 && current != NULL){
      i++;
      temp = current;
      current= current->next;
    }
    temp->next = new_node;
    new_node->next = current;
    return;
  }
}


elem list_remove_from_back(list_t *l){ //FINISH
  node_t *current = l->head;
  node_t *del;
  if (l->head == NULL){
    //printf("list is empty");
    return -1;
  }
  else if (l->head->next == NULL){
    list_remove_from_front(l);
  }
  else{
    while(current->next != NULL){
      del = current;
      current = current->next;
    }
    del->next = NULL;
    return current->value;
    free(current);
    
  }
}

elem list_remove_from_front(list_t *l){
  node_t *current = l->head;
  if (l->head == NULL){
    //printf("list is empty");
    return -1;
  }
  else{
  l->head = (l->head)->next;
  return current->value;
  free(current);
  }
}

elem list_remove_at_index(list_t *l, elem index){
  node_t* current = l->head;
  elem i;
  if((l->head) == NULL){
    printf("list empty.\n");
    return -1;
  }
  else if (index == 0) {
      l->head = (l->head)->next;
      current->next = NULL;
      return current->value;
      free(current);
      
  }
  else {
      for (i = 0; i < index - 1; i++) {
          current = current->next;
          if(current->next == NULL){
          //printf("%d index is not in the list\n", index);
          return -1;
        }
      }
      node_t* del = current->next;
      current->next = current->next->next;
      del->next = NULL;
      return current->value;
      free(del);
  }
}


bool list_is_in(list_t *l, elem value){
  node_t *current = l->head;
  while (current != NULL){
    if (current->value == value){
      printf("%d found in the list.\n", value);
      return true;
    }
    current = current->next;
  }
  printf("%d not found in the list.\n", value);
  return false;
}

elem list_get_elem_at(list_t *l, elem index){
  node_t* current = l->head;
  elem i = 0;

  if((l->head) == NULL || (index) <= -1){
    printf("index does not exist.\n");
    return -1;
  }
  else if (index == 0) {
    printf("%d index is %d \n", current->value, i);
    return current->value;
  }
  else {
      for (i = 0; i < index - 1; i++) {
        current = current->next;
        if(current->next == NULL){
          printf("%d index is not in the list\n", index);
          return -1;
        }
      }
      printf("%d index is %d \n", (current->next)->value, index);
      return (current->next)->value;
  }
}
elem list_get_index_of(list_t *l, elem value){
  node_t *current = l->head;
  elem count = 1;

  if((l->head) == NULL){
    printf("list empty.\n");
    return -1;
  }
  else if((l->head)->value == value){
    printf("%d index is %d \n", value, count - 1);
    return count - 1;
 }
  while(current->next && current->next->value != value){
    count++;
    current = current->next;
 }
  if(current->next){
    printf("%d index is %d \n", value, count);
    return count;
 }
  else{
    printf("%d not found in the list.\n", value);
    return -1;
 }
}

