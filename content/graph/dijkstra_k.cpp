// Find the k shortest routes from 1 to n
int n, m, k; cin >> n >> m >> k;
vector<vector<pii>> adj(n + 1);

for (int i = 0; i < m; i++) {
    int a, b, c; cin >> a >> b >> c;
    adj[a].push_back({ b, c });
}

vector<vi> dis(n + 1);
priority_queue<pii, vector<pii>, greater<pii>> pq; // {cost, node}
pq.push({ 0, 1 });

while (!pq.empty()) {
    auto [parentCost, u] = pq.top(); pq.pop();
    if (dis[u].size() >= k) continue;
    dis[u].push_back(parentCost);

    for (auto [v, childCost] : adj[u]) {
        pq.push({ parentCost + childCost, v });
    }
}

cout << dis[n] << "\n";
