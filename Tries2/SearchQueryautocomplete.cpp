struct TrieNode {
    map<char, TrieNode*> children;
    bool isEnd = false;
    int freq = 0;
};

class AutoCompleteSystem {
    TrieNode* root;
    string currentQuery;
    public:
        AutoCompleteSystem(vector<string>& sentences, vector<int>& times) {
            root = new TrieNode();
            for (int i = 0; i < sentences.size(); i++) {
                insert(sentences[i], times[i]);
            }
        }
        
        void insert(string sentence, int times) {
            TrieNode* node = root;
            for (char c : sentence) {
                if (!node->children.count(c)) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
            node->isEnd = true; 
            node->freq += times; 
        }
        
        void dfs(TrieNode* node, string sentence, vector<pair<int, string>>& sentences) {
            if (node->isEnd) {
                sentences.push_back({ node->freq, sentence });
            }
            for (auto& child : node->children) {
                dfs(child.second, sentence + child.first, sentences);
            }
        }
    
        vector<string> input(char c) {
            if (c == '#') {
                insert(currentQuery, 1);
                currentQuery = ""; 
                return {}; 
            }
    
            currentQuery += c; 
            TrieNode* node = root;
            vector<pair<int, string>> sentences; 
    
            for (char ch : currentQuery) {
                if (!node->children.count(ch)) {
                    return {}; 
                }
                node = node->children[ch];
            }
    
            dfs(node, currentQuery, sentences);
    
            sort(sentences.begin(), sentences.end(), [](pair<int, string>& a, pair<int, string>& b) {
                return a.first > b.first || (a.first == b.first && a.second < b.second);
            });
    
            vector<string> result;
            for (int i = 0; i < min(3, (int)sentences.size()); ++i) {
                result.push_back(sentences[i].second);
            }
            return result;
        }
};
