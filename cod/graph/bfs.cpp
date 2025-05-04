vector<vi> adj;
vi vis(n + 1, 0), p(n + 1, -1); 

void bfs(int start) {
    queue<int> q; q.push(start);
    p[start] = -1; 

    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << endl;
        vis[u] = 1;
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
                p[v] = g;
                cout << v << endl;
            }
        }
    }
}
