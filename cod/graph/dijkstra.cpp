#include <bits/stdc++.h>
#include "debug.hpp"
using namespace std;
#define vi vector<int>
#define OO 1e8
#define pii pair<int, int>
int n;
vector<vector<pair<int, int> > > adj;
void addEdge(int u, int v, int w) {
  adj[u].emplace_back(v, w);
  adj[v].emplace_back(u, w);
}
vi visited;
vi dijkstra(int x) {
  vi distance(adj.size(), OO);
  priority_queue<pii, vector<pii>, greater<> > q;
  q.emplace(0, x);
  distance[x] = 0;
  q.emplace(0, x);
  while (!q.empty()) {
    int a = q.top().second;

    q.pop();
    if (visited[a]) continue;
    visited[a] = true;
    for (auto u : adj[a]) {
      int b = u.first, w = u.second;
      if (distance[a] + w < distance[b]) {
        distance[b] = distance[a] + w;
        q.emplace(distance[b], b);
        debug(distance);
      }
    }
  }
  return distance;
}
void printSolution(vi dist) {
  cout << "Vertex \t Distance from Source" << endl;
  for (int i = 0; i < n; i++) cout << i << " \t\t-->\t\t" << dist[i] << endl;
}
int main() {
  n = 14;
  adj.resize(n);
  visited.resize(n);

  addEdge(0, 1, 4);
  addEdge(0, 7, 8);
  addEdge(1, 2, 8);
  addEdge(1, 7, 11);
  addEdge(2, 3, 7);
  printSolution(dijkstra(0));
  return 0;
}
