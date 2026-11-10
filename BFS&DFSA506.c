#include <stdio.h>
#define MAX 20
int adj[MAX][MAX];
int visited[MAX];
int n; /* number of vertices */
void bfs(int start) {
 int queue[MAX], front = 0, rear = 0;
 int visitedLocal[MAX] = {0};
 visitedLocal[start] = 1;
 queue[rear++] = start;
 printf("BFS traversal: ");
 while (front < rear) {
 int current = queue[front++];
 printf("%d ", current);
 for (int i = 0; i < n; i++) {
 if (adj[current][i] == 1 && !visitedLocal[i]) {
 visitedLocal[i] = 1;
 queue[rear++] = i;
 }
 }
 }
 printf("\n");
}
void dfsUtil(int vertex) {
 visited[vertex] = 1;
 printf("%d ", vertex);
 for (int i = 0; i < n; i++) {
 if (adj[vertex][i] == 1 && !visited[i])
 dfsUtil(i);
 }
}
void dfs(int start) {
 for (int i = 0; i < n; i++)
 visited[i] = 0;
 printf("DFS traversal: ");
 dfsUtil(start);
 printf("\n");
}
int main() {
 int edges, u, v, start;
 printf("Enter number of vertices: ");
 scanf("%d", &n);
 printf("Enter number of edges: ");
 scanf("%d", &edges);
 printf("Enter edges (u v), vertices numbered 0 to %d:\n", n - 1);
 for (int i = 0; i < edges; i++) {
 scanf("%d %d", &u, &v);
 adj[u][v] = 1;
 adj[v][u] = 1; /* undirected graph */
}
printf("Enter starting vertex: ");
 scanf("%d", &start);
 bfs(start);
 dfs(start);
 return 0;
}
sample input:Enter number of vertices: 5
Enter number of edges: 6
Enter edges (u v), vertices numbered 0 to 4:
0 1
0 2
1 3
1 4
2 3
3 4
Enter starting vertex: 0
sample output:BFS traversal: 0 1 2 3 4
DFS traversal: 0 1 3 2 4