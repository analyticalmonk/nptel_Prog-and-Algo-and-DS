// Number Triples
//
// (IARCS OPC Archive, K Narayan Kumar, CMI)
//
// In this problem you will be given a sequence of triples of positive integers. For example:
//
//  1  2   5
//  5  2   6
//  1  3   8
//  8  1  11
//  1  1   6
// 10  1   6
// 11  3   6
// 10  4   8
// 10  1  11
// Given a pair of numbers A and B, a chain connecting A and B is a sequence of triples
//
// A0 W0 A1,   A1 W1 A2,   A2 W2 A3,   ... Ak-2 Wk-2 Ak-1,   Ak-1 Wk-1 Ak
//
// such that
//
// A0 = A
// Ak = B
// For each i, 0 ≤ i < k, either the triple Ai Wi Ai+1 or the triple Ai+1 Wi Ai is in the given set of triples.
// The value of such a chain is the sum of the Wis in the chain. For example, here is a chain connecting 1 and 11 using the triples listed above:
//
// 1  1  6,  6  3  11
// The value of this chain is 1+3 = 4.
//
// Here is another chain connecting 1 and 11.
//
// 1  1  6,  6  1  10,  10  1  11
// The value of this chain is 1+1+1 = 3. You can verify that among all chains connecting 1 and 11 this is the one with least value.
//
// Sometimes there may be no chains connecting the given pair of numbers. For example, there is no chain connecting 1 and 2.
//
// You will be given a sequence of triples and a pair of numbers. Your task is to find the value of the least value chain connecting the two numbers.
//
// Solution hint
//
// Construct a graph from the triples and use Dijkstra's algorithm for single-source shortest paths.
//
// Full solution
//
// .
// Input format
//
// The first line of the input has three numbers M, A and B. M is the number of triples. The next M lines (lines 2,3,...,M+1) describe the triples. Line i+1 contains the three positive integers Xi, Yi and Zi that make up the ith triple. Your task is to find the value of the least value chain connecting A and B.
//
// Output format
//
// If there is at least one chain connecting A and B the first line of the output must consist of a single word YES. In that case the second line must contain a single integer value indicating the value of the least valued chain connecting A and B. If there are no chains connecting A and B the output should contain a single line with the word NO on it.
//
// Test Data:
//
// You may assume that 1 ≤ Xi, Yi, Zi ≤ 2000 and M ≤ 4000000.

#include <stdio.h>

int main() {
  // Pseduo Code
  // - Take initial line of input.
  // - For each subsequent line containing a chain, update edge in the adjacency matrix.
  // - Repeat the above step till entire graph gets created.
  // - Use dijkstra's algo and find the required value.

  int M, A, B, i, j, v1, v2, len_graph, curr_vertex;
  long int weight_sum = 0, weight, min_dist;
  scanf ("%d %d %d", &M, &A, &B);
  int visited[1001];
  long int adj_matrix[1001][1001] = {0};
  // For counting number of vertices //
  int max = -1;
  ////////////////////////////////////
  for (i = 0; i < M; i++) {
    scanf ("%d %ld %d", &v1, &weight, &v2);
    adj_matrix[v1 - 1][v2 - 1] = weight;
    adj_matrix[v2 - 1][v1 - 1] = weight;
    weight_sum += weight;
    // printf("%ld %ld\n", adj_matrix[v1][v2], adj_matrix[v2][v1]);
    visited[v1 - 1] = visited[v2 - 1] = 0;
    if (max < v1) max = v1;
    if (max < v2) max = v2;
  }
  len_graph = max;
  // printf("Graph length: %d\n", len_graph);
  // printf("Sum of weights: %ld\n", weight_sum);

  long int distance[1001];

  for (i = 0; i < len_graph; i ++) {
    // printf("visited[%d]: %d\n", i, visited[i]);
    distance[i] = weight_sum + 1;
    // printf("distance[%d]: %ld\n", i, distance[i]);
  }

  distance[A - 1] = 0;
  for (i = 0; i < len_graph; i++) {
    // Find the unvisited edge at minimum distance and mark it as visited
    min_dist = weight_sum;
    for (j = 0; j < len_graph; j++) {
      if (visited[j] == 0 && distance[j] < min_dist) {
        min_dist = distance[j];
        curr_vertex = j;
      }
    }
    // printf("current vertex:%d\n", curr_vertex);
    visited[curr_vertex] = 1;

    // Visit each vertex adjacent to the selected edge and update distance as
    // per Dijkstra's algorithm
    for (j = 0; j < len_graph; j ++) {
      if (j == curr_vertex) {continue;}
      if (adj_matrix[curr_vertex][j] != 0 && distance[j] > distance[curr_vertex] + adj_matrix[curr_vertex][j]) {
        distance[j] = distance[curr_vertex] + adj_matrix[curr_vertex][j];
      }
    }
  }

  for (i = 0; i < len_graph; i ++) {
    // printf("visited[%d]: %d\n", i, visited[i]);
    // printf("distance[%d]: %ld\n", i, distance[i]);
  }

  if (visited[B - 1] == 1) {
    printf("YES\n");
    printf("%ld", distance[B - 1]);
  }
  else {
    printf("NO\n");
  }

  return 0;
}
