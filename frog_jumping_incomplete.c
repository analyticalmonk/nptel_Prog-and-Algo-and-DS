#include <stdio.h>
#include <stdlib.h>

int main() {
  int m, n, i, j, jump_val, q_tail, q_current, current_vertex;
  int* vertices[2];
  int* levels; int* q;
  scanf("%d %d", &m, &n);;
  vertices = malloc(sizeof(int) * (m * n));
  levels = malloc(sizeof(int) * (m*n));
  q = malloc(sizeof(int) * (m*n));

  // R values //
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      // Assign inital levels value
      levels[(i*m)+j] = -1;

      scanf("%d", &jump_val);
      // To avoid making invalid jumps
      if ((j + jump_val) >= n) {
        vertices[(i*m)+j][0] = -1;
        continue;
      }
      // Add the edge corresponding to (i, j) -> (i, j+jump_val) //
      else {
        vertices[(i*m)+j][0] = j + jump_val;
      }
    }
  }

  // D values //
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &jump_val);
      // To avoid making invalid jumps
      if ((i + jump_val) >= m) {
        vertices[(i*m)+j][1] = -1;
        continue;
      }
      // Add the edge corresponding to (i, j) -> (i+jump_val, j) //
      else {
        vertices[(i*m)+j][1] = i + jump_val;
      }
    }
  }

  // Run BFS on the vertices array/list //
  q[0] = 0; // Appended the first vertice to the queue
  levels[0] = 0;
  q_tail = 1; q_current = 0;

  while ((q_tail - q_current) > 0) {
    current_vertex = *(q + q_current);
    if (levels[current_vertex] != -1) {
      i = 2;
      while (i--) {
        if (vertices[current_vertex][i] == -1) continue;
        q[q_tail] = vertices[current_vertex][i];
        q_tail++;
      }
    }
    q_current++;
  }

  printf("%d\n", levels[m*n]);

  free(vertices);
  free(levels);
  return 0;
}
