// if this function returned true, count++
bool countCyclesDFS(int u) {
    visited[u] = true;

    for (int v : graph[u]) {
        if (!visited[v]) {
            if (countCyclesDFS(v)) {
                return true;
            }
        } else if (v != u) {
            return true;
        }
    }
    return false;
}
