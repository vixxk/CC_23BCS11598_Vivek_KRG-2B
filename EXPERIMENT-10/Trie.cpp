#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* links[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; i++) links[i] = nullptr;
        isEnd = false;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->links[idx])
                node->links[idx] = new TrieNode();
            node = node->links[idx];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->links[idx]) return false;
            node = node->links[idx];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->links[idx]) return false;
            node = node->links[idx];
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl;
    cout << trie.search("app") << endl;
    cout << trie.startsWith("app") << endl;
    trie.insert("app");
    cout << trie.search("app") << endl;
    return 0;
}