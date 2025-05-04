// Searching for a cycle 
// Color: 0 = unvisited, 1 = in‐stack, 2 = done
vi color(n + 1, 0), parents(n + 1, -1), cycle;
bool found = false;

function<bool(int)> dfs = [&](int u) -> bool {
    color[u] = 1;
    for (int v : adj[u]) {
        if (color[v] == 0) {
            parents[v] = u;
            if (dfs(v)) return true;
        }
        else if (color[v] == 1) {
            // back‐edge u→v = found a cycle
            found = true;
            cycle.push_back(v);
            for (int x = u; x != v; x = parents[x])
                cycle.push_back(x);
            cycle.push_back(v);
            reverse(all(cycle));
            return true;
        }
    }
    color[u] = 2;
    return false;
};

for (int i = 1; i <= n && !found; i++) {
    if (color[i] == 0) dfs(i);
}

if (!found) {
    cout << "IMPOSSIBLE\n";
} else {
    cout << cycle.size() << "\n";
    cout << cycle << "\n";
}