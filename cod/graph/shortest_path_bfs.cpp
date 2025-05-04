vi path;
int target = 5;  
for (int v = target; v != -1; v = p[v]) {
    path.push_back(v);
}

reverse(path.begin(), path.end());

for (int i = 0; i < path.size(); i++) {
    cout << path[i];
    if (i != path.size() - 1) {
        cout << " --> ";
    }
}