
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// returns the number of elements in the list
int size(node* head) {
  // C programming feature that keeps count of value from previous function calls
  static int count = 0;

  if (head == NULL) return count;
  count++;
  return size(head->next);
}

int isEmpty(node* position) {
  if(position == NULL) return 1;
  // NULL is a constant address defined in the stdlib.h,
  // meaning it doesn't point to anything

  return 0;
}

// Decision questions given a pointer
int isFirst(node* list, node* position) {
  if (position == list) return 1;
  return 0;
}

int isLast(node* list, node* position) {

  if (position->next == NULL) return 1;
  return 0;
}

// Functions to return pointers to specific queries
node* first(node* list) {
  return list;
}

node* last(node* list) {
  if (list == NULL) return list;

  while(list->next != NULL) {
    list = list->next;
  }

  return list;
}

node* before(node* list, node* position) {
  if (list == NULL || isFirst(list, position)) return NULL;

  while (list->next != position) {
    list = list->next;
  }
  return list;
}

node* after(node* list, node* position) {
  if (list == NULL || isLast(list, position)) return NULL;

  while (list != position) {
    list = list->next;
  }
  return list->next;
}

// Update methods

void replaceElement(node* position, int value) {
  if (position != NULL) position->value = value;
  return;
}

void swapElement(node* pos1, node* pos2) {
  if ((pos1 == NULL) || (pos2 == NULL)) return;

  int val = pos1->value;
  pos1->value = pos2->value;
  pos2->value = val1;

  return;
}

node* insertBefore(node *list, node* position, int newval) {
  node* newnode;

  newnode = (node*)malloc(sizeof(node));
  newnode->value = newval;

  while (list->next != postion) {
    list = list->next;
  }

  list->next = newnode;
  newnode->next = position;

  return newnode;
}
