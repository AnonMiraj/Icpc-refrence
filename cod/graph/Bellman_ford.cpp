// Find maximum score to travel from 1 to n 
// negative allowed, infinite cycles allowed
// good for V = 500

struct edge {
    int u, v, w;
};

int n, m; cin >> n >> m;

vector<edge> edges;

for (int i = 0; i < m; i++) {
    int u, v, w; cin >> u >> v >> w;
    edges.push_back({ u, v, w });
}

vi score(n + 1, LLONG_MIN);
score[1] = 0;

// Relaxation (n - 1) times
for (int i = 1; i <= n - 1; i++) {
    for (int j = 0; j < m; j++) {
        auto [u, v, w] = edges[j];
        if (score[u] != LLONG_MIN) {
            score[v] = max(score[v], score[u] + w);
        }
    }
}

/*
After the initial relaxation steps, we check if any edge can still be relaxed.
If it can, that means there's a cycle (specifically a "positive cycle" for maximizing the score)
that can improve the score.
*/
vector<bool> hasPositiveCycle(n + 1, false);
for (int i = 0; i < m; i++) {
    auto [u, v, w] = edges[i];
    if (score[u] != LLONG_MIN && score[v] < score[u] + w) {
        hasPositiveCycle[v] = true;
    }
}


/*
However, simply detecting an edge that can be relaxed doesn't tell us which vertices
might be affected downstream by this cycle.
The propagation loop iterates over all edges several times (in this case, n times)
to "spread" the effect of the positive cycle
*/
for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
        auto [u, v, w] = edges[j];
        if (hasPositiveCycle[u]) hasPositiveCycle[v] = true;
    }
}

if (hasPositiveCycle[n]) cout << -1 << "\n";
else cout << score[n] << "\n";
