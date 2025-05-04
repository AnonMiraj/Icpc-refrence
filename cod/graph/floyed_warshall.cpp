// Find shortest path from all nodes to all nodes, good for V = 5000, E = 1e6
int n, m, q; cin >> n >> m >> q;

vector<vi> dis(n + 1, vi(n + 1, LLONG_MAX));
for (int i = 1; i <= n; i++) {
    dis[i][i] = 0;
}

for (int i = 0; i < m; i++) {
    int a, b, c; cin >> a >> b >> c;
    dis[a][b] = min(dis[a][b], c);
    dis[b][a] = min(dis[b][a], c);
}

for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dis[i][k] < LLONG_MAX && dis[k][j] < LLONG_MAX)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
}

while (q--) {
    int a, b; cin >> a >> b;
    if (dis[a][b] == LLONG_MAX) cout << "-1\n";
    else cout << dis[a][b] << "\n";
}
