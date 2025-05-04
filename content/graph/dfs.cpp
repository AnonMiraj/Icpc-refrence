/**
 * Author: Ramez Medhat
 * Description: Traversing graph
 * Time: O(V + E)
 */
int n; 
vector<vi> adj; 
vi vis(n + 1), ans;

void dfs(int u) {
    vis[u] = true;
    cout << u << ' ';

    for (int v : graph[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }

    ans.push_back(u);
}