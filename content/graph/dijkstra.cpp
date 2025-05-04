/**
 * Author: Ramez Medhat
 * Description: Find shortest path from node 1 to all nodes.
 * Time: V = 1e5, E = 1e6.
 */
int n, m; cin >> n >> m;
vector<vector<pii>> adj(n + 1);

for (int i = 0; i < m; i++) {
  int a, b, c; cin >> a >> b >> c;
  adj[a].push_back({ b, c });
}

vi vis(n + 1), dis(n + 1);
priority_queue<pii, vector<pii>, greater<pii>> pq; // {cost, node}
pq.push({ 0, 1 });

while (!pq.empty()) {
  auto [parentCost, u] = pq.top(); pq.pop();
  if (vis[u]) continue;
  vis[u] = 1; dis[u] = parentCost;

  for (auto [v, childCost] : adj[u]) {
    if (!vis[v]) {
      pq.push({ parentCost + childCost, v });
    }
  }
}

for (int i = 1; i <= n; i++) {
  cout << dis[i] << " ";
}
