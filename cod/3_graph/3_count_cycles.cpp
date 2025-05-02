bool dfs(int v) {
    // if this function returned true, count++
    
    visited[v] = true;
    
    for (int i : graph[node]) {
        if (!visited[i]) {
            if (dfs(i)) {
                return true;
            }
        } else if (i != parent) {
            return true;
        }
    }
    return false;
}
