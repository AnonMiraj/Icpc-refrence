// A topological sort takes a directed acyclic graph (DAG) and produces
// a linear ordering of its vertices such that for every directed edge u -> v, u comes before v in that order.
// Returns a vector of nodes in a valid order; if a cycle exists, the size will be < n.
// Useful for: Scheduling with Dependencies, Course Prerequisites


vi topologicalSort(int n, vector<vi>& adj, vi& inDeg) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDeg[i] == 0)
            q.push(i);
    }

    vi order;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            if (--inDeg[v] == 0)
                q.push(v);
        }
    }
    
    return order;
}