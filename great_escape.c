// C program written by da-ta-vinci as a part of the assignment-2 "The Great Escape"
// for the NPTEL MOOC "Design and Analysis of Algorithms".
//
// In this problem, our hero has to save his wife/mother/child/dog/... held captive
// by the nasty villain on the top floor of a tall building in the centre of
// Bombay/Bangkok/Kuala Lumpur/.... Our hero is on top of a (different) building.
// In order to make the action "interesting" the director has decided that the hero
// can only jump between buildings that are "close" to each other. The director
// decides which pairs of buildings are close enough and which are not.
//
// Given the list of buildings, the identity of the building where the hero begins
// his search, the identity of the building where the captive (wife/mother/child/dog...)
// is held, and the set of pairs of buildings that the hero can jump across, your
// aim is determine whether it is possible for the hero to reach the captive.
// And, if he can reach the captive he would like to do so with minimum number of jumps.
//
// ~~~~~The program is compiled using the c99 standard~~~~~

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int neighbours[101];
} node;

int main () {
  int i, level, num_buildings, num_pairs, b_one, b_two, edge_count[3501] = {0};
  scanf ("%d %d", &num_buildings, &num_pairs);
  int store_q[3501] = {0}, levels[3501] = {-1}, parent[3501] = {-1}, visited[3501] = {0};
  int parent_c, start, target, q_start = 0, q_curr = 0, q_len = 0, current_edge, neighbour;
  node graph[3501];
  // In each iteration, user will enter a pair of 'close' building. Those
  // buildings' associated values in the adjacency list will then be updated.
  for (i = 0; i < num_pairs; i++) {
    scanf ("%d %d", &b_one, &b_two);
    graph[b_one].neighbours[edge_count[b_one]] = b_two;
    graph[b_two].neighbours[edge_count[b_two]] = b_one;
    edge_count[b_two]++; edge_count[b_one]++;
  }

  // _______For debugging purpose_______
  // printf("\n");
  // for (i = 0; i <5; i++) {
  //   for (int j = 0; j < edges[i]; j++) {
  //     printf ("%d ", graph[i].neighbours[j]);
  //   }
  //   printf ("\n");
  // }

  // Input the start and target building respectively
  scanf("%d %d", &start, &target);

  store_q[q_start] = start; // q_start is where the current first element of the
                            // queue resides
  // levels[start]++;
  q_len++; // Stores the current queue length
  q_curr++; // Stores the position to insert at in queue

  // At this point, we have the adjacency list along with the queue currently
  // holding the value of start node.

  // The loop will run till the queue gets empty
  while (q_len > 0) {
    current_edge = store_q[q_start];
    q_len--; q_start++;
    for (i = 0; i < edge_count[current_edge]; i++) {
      neighbour = graph[current_edge].neighbours[i];
      if (visited[neighbour] == 0) {
        visited[neighbour] = 1;
        // parent[neighbour] = current_edge;
        levels[neighbour] = levels[current_edge] + 1;
        store_q[q_curr] = neighbour; q_len++; q_curr++;
      }
      if (neighbour == target) break;
    }
    if (neighbour == target) break;
  }

  // _______For debugging/testing purpose_______
  // printf ("\nVisited\n");
  // for (i = 0; i < 5; i++) {
  //   if (i == start) continue;
  //   printf ("%d %d\n", i, visited[i]);
  // }

  if (visited[target] == 0) {
    printf("0");
  }
  else if (visited[target] == 1){
    printf ("%d", levels[target]);

    // ____Code to print the path from start to target, if its exists____
    // int parent_c = target;
    // printf ("%d <- ", parent_c);
    // parent_c = parent[parent_c];
    // while (2 > 1) {
    //   if (parent_c == start) {
    //     printf ("%d\n", parent_c);
    //     break;
    //   }
    //   printf ("%d <- ", parent_c);
    //   parent_c = parent[parent_c];
    // }
  }

  return 0;
}
