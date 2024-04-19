// User function Template for C++
class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
        isEnd = false;
    }
};
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children[ch - 'a'] == nullptr)
                node->children[ch - 'a'] = new TrieNode();
            node = node->children[ch - 'a'];
        }
        node->isEnd = true;
    }

    vector<string> search(string prefix) {
        TrieNode* node = root;
        vector<string> result;
        for (char ch : prefix) {
            if (node->children[ch - 'a'] == nullptr)
                return result;
            node = node->children[ch - 'a'];
        }
        dfs(node, prefix, result);
        return result;
    }

    void dfs(TrieNode* node, string prefix, vector<string>& result) {
        if (node == nullptr)
            return;
        if (node->isEnd)
            result.push_back(prefix);
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                char ch = 'a' + i;
                dfs(node->children[i], prefix + ch, result);
            }
        }
    }
};

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie trie;
        for (int i = 0; i < n; i++) {
            trie.insert(contact[i]);
        }
        vector<vector<string>> result;
        string prefix;
        for (char ch : s) {
            prefix += ch;
            vector<string> matches = trie.search(prefix);
            if (matches.empty()) {
                result.push_back({"0"});
            } else {
                result.push_back(matches);
            }
        }
        return result;
    }
};
