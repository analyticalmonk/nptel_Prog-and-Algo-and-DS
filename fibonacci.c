// Program to print the fibonacci sequence upto a specified length

#include <stdio.h>

// Function prototype
long int fibonacci(int);

int main(){
  int length;
  scanf("%d", &length);
  for (int i = 0; i < length; i++){
    printf("%ld ", fibonacci(i));
  }
  printf("\n");
  return 0;
}

long int fibonacci(int place) {
  // Terminating conditions
  if(place == 1 | place == 0) {
    return (long int)1;
  }
  long int a, b, current;
  a = fibonacci(place - 1);
  b = fibonacci(place - 2);
  current = a + b;
  return current;
}
