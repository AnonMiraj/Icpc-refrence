/**
 * Author: Ramez
 * Description: binary trie that supports update(val, op),
 * where op = +1 to insert, op = –1 to erase and query(x) → ans is the maximum XOR you can
 * achieve between x and any value currently in the trie.
 * Time: $O(1)$ time, $O(N)$ space
 */

struct node {
    int ch[2]{}, frq[2]{}, sz{};

    int& operator[](int x) {
        return ch[x];
    }
};

const int M = 60;

struct BinaryTrie {
    vector<node> nodes;

    int newNode() { return nodes.emplace_back(), nodes.size() - 1; }

    void init() { nodes.clear(), newNode(); }

    BinaryTrie() { init(); }

    void update(int val, int op) { /// 1 -> add , -1 -> delete
        int u = 0;
        for (int i = M - 1; i >= 0; --i) {
            int v = val >> i & 1;
            if (!nodes[u][v]) {
                nodes[u][v] = newNode();
            }
            nodes[u].frq[v] += op;
            nodes[u].sz += op;
            u = nodes[u][v];
        }
        nodes[u].sz++;
    }

    int query(int x) {
        int ans = 0, u = 0;
        for (int i = M - 1; i >= 0 && u >= 0; --i) {
            int v = x >> i & 1;
            if (nodes[u].frq[v]) {
                u = nodes[u][v];
            }
            else {
                u = nodes[u][!v];
                ans |= 1LL << i;
            }
        }
        return ans;
    }
};
