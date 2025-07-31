/**
 * Author: Ramez
 * Description: Trie
 * Time: $O(1)$ time, $O(N)$ space
 */

struct Trie {
    struct Node {
        Node* child[26];
        int IsEnd, Prefix;
        Node() {
            memset(child, 0, sizeof child);
            IsEnd = Prefix = 0;
        }
    };

    Node* root = new Node();
    
    void insert(string& s)
    {
        Node* cur = root;
        for (auto it : s)
        {
            int idx = it - 'a';
            if (cur->child[idx] == 0)
            {
                cur->child[idx] = new Node();
            }
            cur = cur->child[idx];
            cur->Prefix++;
        }
        cur->IsEnd++;
    }
    
    bool searchWord(string& s)
    {
        Node* cur = root;
        for (auto it : s)
        {
            int idx = it - 'a';
            if (cur->child[idx] == 0)return 0;
            cur = cur->child[idx];
        }
        return cur->IsEnd;
    }
    
    int countWord(string& s)
    {
        Node* cur = root;
        for (auto it : s)
        {
            int idx = it - 'a';
            if (cur->child[idx] == 0)return 0;
            cur = cur->child[idx];
        }
        return cur->IsEnd;
    }
    
    int countPrefix(string& s)
    {
        Node* cur = root;
        for (auto it : s)
        {
            int idx = it - 'a';
            if (cur->child[idx] == 0)return 0;
            cur = cur->child[idx];
        }
        return cur->Prefix;
    }
};