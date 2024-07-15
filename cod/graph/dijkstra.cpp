int n;
vector<vector<pair<int, int> > > adj;
void addEdge(int u, int v, int w) {
  adj[u].emplace_back(v, w);
  adj[v].emplace_back(u, w);
}
vi visited;
vi dijkstra(int x) {
  vi distance(adj.size(), INT_MAX);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<> > q;
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
  for (int i = 0; i < n; i++) cout << i << " \t\t-->\t\t" << dist[i] << endl;
}
