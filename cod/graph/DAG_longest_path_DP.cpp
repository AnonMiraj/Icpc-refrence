// What is the maximum number of cities I can visit on any directed path from 1 to n in a graph with no cycles DAG?
// dp[i] = the maximum number of cities you can visit on any path from city 1 ending at city i

vi order = topologicalSort(n, adj, inDeg);

vi dp(n + 1, -1), parent(n + 1, -1);
dp[1] = 1;

for (int u : order) {
    if (dp[u] < 0)    // not reachable from 1
        continue;

    for (int v : adj[u]) {
        if (dp[u] + 1 > dp[v]) {
            dp[v] = dp[u] + 1;
            parent[v] = u;
        }
    }
}

if (dp[n] < 0) {
    cout << "IMPOSSIBLE\n";
    return;
}