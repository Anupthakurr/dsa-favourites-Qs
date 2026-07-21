#include <iostream>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        isTerminal = false;

        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;

    void insertUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    bool searchUtil(TrieNode* root, string word) {
        if (word.length() == 0)
            return root->isTerminal;

        int index = word[0] - 'a';

        if (root->children[index] == nullptr)
            return false;

        return searchUtil(root->children[index], word.substr(1));
    }

    bool prefixUtil(TrieNode* root, string prefix) {
        if (prefix.length() == 0)
            return true;

        int index = prefix[0] - 'a';

        if (root->children[index] == nullptr)
            return false;

        return prefixUtil(root->children[index], prefix.substr(1));
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }

    void insert(string word) {
        insertUtil(root, word);
    }

    bool search(string word) {
        return searchUtil(root, word);
    }

    bool startsWith(string prefix) {
        return prefixUtil(root, prefix);
    }
};

int main() {

    Trie t;

    t.insert("cat");
    t.insert("car");
    t.insert("care");
    t.insert("dog");

    cout << t.search("cat") << endl;       // 1
    cout << t.search("care") << endl;      // 1
    cout << t.search("cow") << endl;       // 0

    cout << t.startsWith("ca") << endl;    // 1
    cout << t.startsWith("car") << endl;   // 1
    cout << t.startsWith("do") << endl;    // 1
    cout << t.startsWith("de") << endl;    // 0

    return 0;
}
