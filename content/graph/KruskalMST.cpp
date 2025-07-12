/**
 * Author: Ramez Medhat
 * Description: it finds the minimum cost of forming a minimum spanning tree, if it can't be formed it returns -1, it can also help detecting cycles easily in graph 
 * Time: O(mlogm)
 */

struct Edge {
    int u, v, w;
    Edge() : u(0), v(0), w(0) {} 
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator<(Edge const &other) const { return w < other.w; }
};

int kruskalMST(vector<Edge> &edges, int n) {
    sort(all(edges));
    int cost = 0; DSU dsu(n + 1);
    for (auto &[u, v, w] : edges) {
        if (!dsu.same(u, v)) {
            cost += w;
            dsu.merge(u, v);
        }
    }
    if (dsu.getSize(dsu.find(1)) == n) return cost;
    return -1;
}