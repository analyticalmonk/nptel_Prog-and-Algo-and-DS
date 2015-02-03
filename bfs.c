// C program written by da-ta-vinci to show the use of Breadth First Search.
// The program inputs a graph in the form of an adjacency list, and a set of
// nodes. It then proceeds to print the path from the start node to target node,
// if it exists.
// ~~~~~The program is compiled using the c99 standard~~~~~

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int neighbours[5];
} node;

int main () {
  int edges[5] = {0}, store_q[5] = {0}, parent[5] = {-1}, visited[5] = {0};
  int parent_c, count = 0, start, target, q_start = 0, q_curr = 0, q_len = 0, current_edge, neighbour;
  node graph[5];
  // In each iteration, user will first enter the number of edges associated
  // with the node in question followed by the neighbour vertices themselves.
  for (int i = 0; i < 5; i++) {
    scanf ("%d", &edges[i]);
    while (count < edges[i]) {
      scanf("%d", &graph[i].neighbours[count]);
      count++;
    }
    count = 0;
  }

  // _______For debugging purpose_______
  // printf("\n");
  // for (int i = 0; i <5; i++) {
  //   for (int j = 0; j < edges[i]; j++) {
  //     printf ("%d ", graph[i].neighbours[j]);
  //   }
  //   printf ("\n");
  // }

  // Input the start and target node respectively
  scanf("%d %d", &start, &target);

  store_q[q_start] = start;
  q_len++;
  q_curr++;
  // At this point, we have the adjacency list along with the queue currently
  // holding the value of start node.

  while (q_len > 0) {
    current_edge = store_q[q_start];
    q_len--; q_start++;
    for (int i = 0; i < edges[current_edge]; i++) {
      neighbour = graph[current_edge].neighbours[i];
      if (visited[neighbour] == 0) {
        visited[neighbour] = 1;
        store_q[q_curr] = neighbour; q_len++; q_curr++;
        parent[neighbour] = current_edge;
      }
    }
  }

  // _______For debugging/testing purpose_______
  // printf ("\nVisited\n");
  // for (int i = 0; i < 5; i++) {
  //   if (i == start) continue;
  //   printf ("%d %d\n", i, visited[i]);
  // }

  if (visited[target] == 0) {
    printf("\nTarget not reachable from start node!\n");
  }
  else if (visited[target] == 1){
    int parent_c = target;
    printf ("%d <- ", parent_c);
    parent_c = parent[parent_c];
    while (2 > 1) {
      if (parent_c == start) {
        printf ("%d\n", parent_c);
        break;
      }
      printf ("%d <- ", parent_c);
      parent_c = parent[parent_c];
    }
  }

  return 0;
}
