// stackInterface.h created with all the function prototypes

#include "stack.h"

// Create the stack
Stack* createStack(int); //Creates the array version of the stack

// Decision questions
int isEmpty(Stack*); //Check if the stack is empty
int isFull(Stack*); //Check if the stack is full
int peek(Stack*); //Return the topmost element of the stack without removing it

// Update methods
void push(Stack*, int); //Push the given element onto the top the stack
int pop(Stack*); //Remove the topmost element from the stack
