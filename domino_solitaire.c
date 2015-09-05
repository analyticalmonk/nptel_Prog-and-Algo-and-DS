#include <stdio.h>

long int diff_max(long int, long int);

long int domino_array[2][10000];

int main () {
  int N, i, j;
  long int result, result_prev, temp;
  scanf ("%d", &N);
  for (i = 0; i < 2; i++) {
    for (j = 0; j < N; j++) {
      scanf ("%ld", &domino_array[i][j]);
      // printf("dom[%d][%d]: %d\n", i, j, domino_array[i][j]);
    }
  }

  for (i = 0; i < N; i++) {
    if (i == 0) {
      result = diff_max(domino_array[0][0], domino_array[1][0]);
      result_prev = result;
    }
    else if (i == 1) {
      if (result + diff_max(domino_array[0][1], domino_array[1][1]) <
          (diff_max(domino_array[0][0], domino_array[0][1]) +
           diff_max(domino_array[1][0], domino_array[1][1]))) {
            result = (diff_max(domino_array[0][0], domino_array[0][1]) +
                      diff_max(domino_array[1][0], domino_array[1][1]));
          }
      else {
        result += diff_max(domino_array[0][1], domino_array[1][1]);
      }
    }
    else {
      if (result + diff_max(domino_array[0][i], domino_array[1][i]) <
         (result_prev + diff_max(domino_array[0][i - 1], domino_array[0][i]) +
                         diff_max(domino_array[1][i - 1], domino_array[1][i]))) {
            // printf("Iteration (switch) %d: %d %d\n", i, result_prev, result);
            temp = result_prev;
            result_prev = result;
            result = (temp + diff_max(domino_array[0][i - 1], domino_array[0][i]) +
                             diff_max(domino_array[1][i - 1], domino_array[1][i]));
      }
      else {
        // printf("Iteration %d: %d %d\n", i, domino_array[0][2], domino_array[1][i]);
        result_prev = result;
        result += diff_max(domino_array[0][i], domino_array[1][i]);
      }
    }
  }
  printf("%ld\n", result);
  // for (i = 0; i < 2; i++) {
  //   for (j = 0; j < N; j++) {
  //     printf("dom[%d][%d]: %d\n", i, j, domino_array[i][j]);
  //   }
  // }

  return 0;
}

long int diff_max(long int a, long int b) {
  long int difference;
  if (a >= b) {
    difference = a - b;
    return difference;
  }
  else {
    difference = b - a;
    return difference;
  }
}
