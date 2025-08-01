/**
 * Author: ezz
 * Description: trie that supports update(val, op),
 * where op = +1 to insert, op = –1 to erase
 * Time: $O(1)$ time, $O(N)$ space
 */

struct Trie {
    struct Node {
        int ch[26]{};
        int cnt = 0, end = 0;
    };
    vector<Node> t = {{}};
    
    void update(string s, int op) {
        int u = 0;
        for (char c : s) {
            int v = c - 'a';
            if (!t[u].ch[v]) {
                if (op == -1) return;
                t[u].ch[v] = t.size();
                t.push_back({});
            }
            u = t[u].ch[v];
            t[u].cnt += op;
        }
        t[u].end += op;
    }
    
    bool find(string s) {
        int u = 0;
        for (char c : s) {
            int v = c - 'a';
            if (!t[u].ch[v]) return false;
            u = t[u].ch[v];
        }
        return t[u].end > 0;
    }
    
    int prefix(string s) {
        int u = 0;
        for (char c : s) {
            int v = c - 'a';
            if (!t[u].ch[v]) return 0;
            u = t[u].ch[v];
        }
        return t[u].cnt;
    }
};
