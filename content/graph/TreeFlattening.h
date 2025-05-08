/**
 * Author: Ramez Medhat
 * Description: It is a way to **convert a tree into a linear array** (like a list) by 
 * **visiting each node multiple times** in a depth-first manner.
 * Useful for
 * - Querying the sum/maximum/value in a subtree
 * - Updating all nodes in a subtree
 * Time: O(V + E)
 */

int MAX = 3 * n;
vi in(MAX), out(MAX);
int timer = 1;

// tree flattening
function<void(int, int)> dfs = [&](int u, int p) {
	in[u] = timer++;
	for (int v : adj[u]) {
		if(v == p) continue;
		dfs(v, u);
	}
	out[u] = timer++;
};

dfs(1, 0);

/*
in[u] first index for u 
out[u] last index for u 
out[u] - in[u] number of nodes in the subtree of u (including u)
*/