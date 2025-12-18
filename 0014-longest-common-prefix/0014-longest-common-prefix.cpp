class TrieNode {
public:
    TrieNode* children[26];
    bool isTerminal;
    int childCount;

    TrieNode() {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* curr = root;

        for (char ch : word) {
            int index = ch - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
                curr->childCount++;
            }
            curr = curr->children[index];
        }
        curr->isTerminal = true;
    }

    string getLCP() {
        string ans = "";
        TrieNode* curr = root;

        while (curr && curr->childCount == 1 && curr->isTerminal == false) {
            for (int i = 0; i < 26; i++) {
                if (curr->children[i]) {
                    curr = curr->children[i];
                    ans.push_back('a' + i);
                    break;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        Trie trie;
        for (string& s : strs) {
            trie.insert(s);
        }

        return trie.getLCP();
    }
};
