#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> bfs(vector<vector<int>> &adj) {
  int V = adj.size();
  vector<bool> visited(V, false);
  vector<int> result;

  queue<int> q;

  int src = 0;
  visited[src] = true;
  q.push(src);

  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    result.push_back(curr);

    for (int x : adj[curr]) {
      if (!visited[x]) {
        visited[x] = true;
        q.push(x);
      }
    }
  }

  return result;
}

void addEdge(vector<vector<int>> &adj, int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int main() {
  int V = 5;
  vector<vector<int>> adj(V);

  addEdge(adj, 1, 2);
  addEdge(adj, 1, 0);
  addEdge(adj, 2, 0);
  addEdge(adj, 2, 3);
  addEdge(adj, 2, 4);

  vector<int> ans = bfs(adj);

  cout << "BFS Traversal: ";
  for (int x : ans) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
/*
BFS Traversal: 0 1 2 3 4
*/
