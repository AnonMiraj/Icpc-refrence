// Searching for a cycle 
// Color: 0 = unvisited, 1 = in‐stack, 2 = done
vi color(n + 1, 0), parents(n + 1, -1), cycle;
bool found = false;

function<bool(int)> dfs = [&](int parent) -> bool {
    color[parent] = 1;
    for (int child : adj[parent]) {
        if (color[child] == 0) {
            parents[child] = parent;
            if (dfs(child)) return true;
        }
        else if (color[child] == 1) {
            // back‐edge u→v ⇒ found a cycle
            found = true;
            cycle.push_back(child);
            for (int x = parent; x != child; x = parents[x])
                cycle.push_back(x);
            cycle.push_back(child);
            reverse(all(cycle));
            return true;
        }
    }
    color[parent] = 2;
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