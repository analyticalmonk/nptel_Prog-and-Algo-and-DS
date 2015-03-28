
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stackInterface.h"

int isOperator(char c) {
  return c == '*' || c == '/' || c == '+' || c == '-' || c == '^';
  // an operator can be any of the above characters
}

int precedence(char c) {
  switch(c){
    case '+':
    case '-': return 1;
    case '*':
    case '/': return 2;
    case '^': return 3;

    default: return -1; // For handling the '('
  }
}

char* infixToPostfix(char exp[], int size) {
    int i = 0, k = 0;
    Stack* opStack = createStack(size);
    char* output = (char*)malloc(sizeof(char) * (size + 1));
    // Traversing the expression
    while (i < size) {
      // If the expression is an open bracket '(', push it onto the stack
      if (exp[i] == '(') {
        push(opStack, exp[i++]);
      }

      // If the expression is an operator then...
      else if(isOperator(exp[i])) {
        // Pop until an operator of lower precedence appears on the stack
        while (!isEmpty(opStack) || precedence(exp[i]) <= precedence(peek(opStack))) {
          output[k++] = peek(opStack);
          pop(opStack);
        }

        push(opStack, exp[i]);
      }

      // If expression is ')', keep popping until we get '('
      else if(exp[i] == ')') {
        while(!isEmpty(opStack) && peek(opStack) != '(') {
          output[k++] = peek(opStack);
          pop(opStack);
        }

        pop(opStack); // Pop off the '(' symbol from the stack
      }

      else
        output[k++] = exp[i]; // If its just the operand, write to output

      i++;
    }

    while (!isEmpty(opStack)){
      output[k++] = peek(opStack);
      pop(opStack);
    }
    output[k] = '\0';
    return output;
}

int main() {
  char exp[50] = "1+2*(3/4)^5-6*(7+8)-9";
  char* output = infixToPostfix(exp, strlen(exp));
  printf("Postfix of \n%s is \n%s", exp, output);
  return 0;
}
