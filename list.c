// list/list.c
// 
// Implementation for linked list.
//
// <Pradeep Lamichhane>

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#include "list.h"

list_p *list_alloc() { 
  list_p *p;
  p =(list_p*)malloc(sizeof(list_p)); 
  p->head = NULL;
  return p;
}
void list_free(list_p *l) {
  if (!l){
    return;
  }
  node_p *curr = l->head;
  while (curr){
    node_p *temp = curr;
    curr = curr->next;
    free(temp);
  }
}

void list_print(list_p *l) {
  node_p *curr = l->head;
  while (curr != NULL){
    printf("%d\n",curr->value);
    curr = curr->next;
  }
}
int list_length(list_p *l) {
  int count_num = 1;
  node_p *curr = l->head;
  while (curr != NULL){
    count_num += 1;
    curr = curr->next;
  } 
  return count_num-1; 
}

void list_add_to_back(list_p *l, elem value) {
  if (l->head){
    node_p *curr = l->head;
    while (curr->next){
      curr = curr->next;
    }
    node_p* new_node;
    new_node = (node_p *) malloc(sizeof(node_p));
    new_node->value = value;
    curr->next = new_node;
    new_node->next = NULL;
  } else {
    list_add_to_front(l,value);
  }
}
void list_add_to_front(list_p *l, elem value) {
  node_p* new_node;
  new_node = (node_p *) malloc(sizeof(node_p));
  new_node->value = value;
  if(l->head){
    new_node->next = l->head;
    l->head = new_node;
  } else {
    new_node->next = NULL;
    l->head = new_node;
  }
}
void list_add_at_index(list_p *l, elem value, int index) {
  if (index == 0 || l->head == NULL){
    list_add_to_front(l,value);
  }
  int count = 0;
  node_p *curr = l->head;
  while (curr){
    if (count == index-1){
      node_p* new_node;
      new_node = (node_p*)malloc(sizeof(node_p));
      new_node->value = value;
      new_node->next = curr->next;
      curr->next = new_node;
    }
    count += 1;
    curr = curr->next;
  }
}

elem list_remove_from_back(list_p *l) {
  int removedVal;
  node_p *curr = l->head;
  if (curr == NULL){
    return -1;
  }
  while (curr->next->next != NULL) {
      curr = curr->next;
  }
  removedVal = curr->next->value;
  free(curr->next);
  curr->next = NULL;
  return removedVal;
}
elem list_remove_from_front(list_p *l) { 
  elem removedVal = -1;
  node_p *curr = l->head;
  if (curr == NULL){
    return removedVal;
  }
  l->head = curr->next;
  removedVal = curr->value;
  free(curr);
  return removedVal;
}
elem list_remove_at_index(list_p *l, int index) {
  int removedVal = -1;
  node_p *temp =NULL;
  if (index==0){
    list_remove_from_front(l);
  }
  int count = 0;
  node_p *curr = l->head;
  while (curr){
    if (count == index-1){
      removedVal = curr->next->value;
      free(curr->next);
      curr->next = curr->next->next;
      return removedVal;
    }
    count += 1;
    curr = curr->next;
  };
}

bool list_is_in(list_p *l, elem value) { 
  node_p *curr = l->head;
  while (curr != NULL){
    if (curr->value == value){
      return true;
    }
    curr = curr->next;
  } 
  return false; 
}
elem list_get_elem_at(list_p *l, int index) { 
  int count = 0;
  node_p *curr = l->head;
  while (curr != NULL){
    if (count == index){
      return curr->value;
    }
    count += 1;
    curr = curr->next;
  } 
  return -1;
}
int list_get_index_of(list_p *l, elem value) {
  int count = 0;
  node_p *curr = l->head;
  while(curr != NULL){
    if (curr->value == value){
      return count;
    }
    count += 1;
    curr = curr->next;
  }
  return -1; 
}