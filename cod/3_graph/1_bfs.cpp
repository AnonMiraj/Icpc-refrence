vector<vector<int>> adj; // adjacency list
vector<int> vis(n+1, 0);
vector<int> p(n+1, -1); // parent of node

void bfs(int source) {
    queue<int> q;
    q.push(s);
    p[s]=-1; // root

    while(!q.empty()) {
        int g = q.front();
        cout << g << endl;
        vis[g]=1;
        q.pop();
        for(int v : adj[g]) {
            if(!vis[v]) {
                vis[v]=1;
                q.push(v);
                p[v]=g;
                cout << v << endl;
            }
        }
    }

    // to find the shortest path using BFS
    vector<int> path;
    int target = 5;   // targeted node
    for(int v = target; v != -1; v = p[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if(i!=path.size()-1) {
            cout << " --> ";
        }
    }

    // to count connected components using BFS
    int cnt = 0;
    vis = vector<int> (n+1, 0);
    for (int i = 1; i <= n; i++) {
        if(!vis[i]) {
            q.push(i);
            vis[i]=1;
            while(!q.empty()) {
                int g = q.front();
                q.pop();
                vis[g]=1;
                for(int v : adj[g]) {
                    if(!vis[v]) {
                        vis[v]=1;
                        q.push(v);
                        p[v]=g;
                    }
                }
            }
            cnt++;
        }
    }
    cout << "cnt= " << cnt << endl;
}
