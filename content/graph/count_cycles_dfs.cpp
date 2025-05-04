/**
 * Author: Ramez Medhat
 * Description: Counts cycles in graph, if this function returned true, count++.
 * Time: O(V + E)
 */

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
