// Array implementation and associated methods of the stack data structure

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

Stack* createStack(int capacity) {
  Stack* s = (Stack*)malloc(sizeof(Stack));
  s->capacity = capacity;
  s->top = -1;
  s->array = (int*)malloc(sizeof(int)*capacity);

  return s;
}

// Decision questions

int isEmpty(Stack* s) {
  return s->top == -1;
}

int isFull(Stack* s) {
  return s->top == s->capacity - 1;
}

int peek(Stack* s) {
  if(!isEmpty(s)) {
    return s->array[s->top];
  }
  else {
    printf("Error: stack is empty!");
    return INT_MIN;
  }
}

// Update methods

void push(Stack* s, int val) {
  if (!isFull(s)) {
    s->array[++s->top] = val;
  }
  else
    printf("Stack overflow!\n");
}

int pop(Stack* s) {
  if (!isEmpty(s)) {
    return s->array[s->top--];
  }
  else
    printf("Error: stack is empty!");
    return INT_MIN;
}
