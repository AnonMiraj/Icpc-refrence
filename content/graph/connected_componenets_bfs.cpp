/**
 * Author: Ramez Medhat
 * Description: Count number of connected componenets.
 * Time: O(V + E)
 */
int cnt = 0;
vi vis(n + 1, 0);

for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
        q.push(i);
        vis[i] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = 1;
            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                    p[v] = u;
                }
            }
        }
        cnt++;
    }
}

cout << "cnt = " << cnt << endl;