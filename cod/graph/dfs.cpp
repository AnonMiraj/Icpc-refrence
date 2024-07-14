vector<vector<int>> graph;
vector<bool> visited;

// manual
void dfs(int start) {
    stack<int> stack;
    stack.push(start);

    while (!stack.empty()) {
        int node = stack.top();
        stack.pop();

        if (!visited[node]) {
            cout << char(node + 'A') << ' ';
            visited[node] = true;
        }

        for (auto it = graph[node].rbegin(); it != graph[node].rend(); ++it) {
            if (!visited[*it]) {
                stack.push(*it);
            }
        }
    }
}

// with recursion
void dfs(int node) {
    visited[node] = true;
    cout << node << ' ';

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

