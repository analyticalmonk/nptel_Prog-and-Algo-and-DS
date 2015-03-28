// Stack data type for implementation in stack-array.c

typedef struct stack {
  int top; //For storing the index of the topmost stack element
  int capacity;
  int* array;
} Stack;
