#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long int pascal (int, int);

int main() {
  int rows, number_of_cases, row_index, num_index, flag = 0;
  char* n; char* d;
  char* copy;
  long int sum = 0;
  scanf ("%d", &rows);
  scanf ("%d", &number_of_cases);
  // Debug -> because YOLO
  // printf("YOLO!\n");
  for (int i = 0; i < number_of_cases; i++){
    // printf("Start\n");
    char transaction[100];
    sum = 0, flag = 0;
    // printf("YOLO!\n");
    scanf(" %[^\n]s", transaction);
    // printf("transaction accepted:%s\n", transaction);
    // printf("YOLO!\n");
    n = strtok (transaction, " ");\
    // printf("strtok initialized\n");
    // printf("Size of the input is %d\n", strlen(n));
    d = (char*)malloc(strlen(n) + 1);
    // printf("Allocated memory to d\n");
    strcpy(d,(const char*)n);
    // printf("Copied string from n to d\n");
    // Debugging -> same shit, different code
    // printf("%s\n", d);
    // printf("YOLO!\n");
    // printf("row index is %s\n", d);
    row_index = atoi(d);
    // printf("row index(integer) is %d\n", row_index);
    // scanf("%d\n", &row_index);
    if (row_index > rows) {
      printf ("%d ", -1);
      continue;
    }
    // printf("YOLO!\n");
    // printf("Inner loop begins...\n");
    while (n != NULL) {
      free(d);
      n = strtok (NULL, " ");
      if (n == NULL) break;
      // printf("Inner strtok worked, n is %s\n", n);
      d = (char*)malloc(strlen(n) + 1);
      strcpy(d,(const char*)n);
      // printf("New token is %s\n", d);
      // printf("YOLO!\n");
      num_index = atoi(d);
      if (num_index > row_index) {
        printf ("%d ", -1);
        flag = 1;
        break;
      }
      sum += pascal (row_index, num_index);
      // printf("%ld\n", sum);
    }

    if (flag == 1) {
      continue;
    }
    // printf("YOLO!\n");
    // while ((return_val = scanf("%d", &num_index)) && return_val != (int)"\n") {
      // if (num_index > row_index + 1) {
      //   flag = 1;
      //   continue;
      // }
    //   sum += pascal(row_index, num_index);
    // }
    printf ("%ld ", sum);
  }
  return 0;
}

long int pascal (int row, int num){
  if (row == 0 | num == 0| num == row) {
    return (long int)1;
  }
  return pascal(row - 1, num - 1) + pascal(row - 1, num);
}
