#include <iostream>
#include <map>

class TrieNode {
public:
    std::map<char, TrieNode*> children;
    bool endOfWord;

    TrieNode() : endOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(std::string word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->endOfWord = true;
    }

    bool search(std::string word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return current != nullptr && current->endOfWord;
    }

    // Additional methods like delete can also be implemented.
};

int main() {
    Trie trie;
    trie.insert("hello");
    std::cout << "Is 'hello' in trie? " << trie.search("hello") << std::endl;
    std::cout << "Is 'world' in trie? " << trie.search("world") << std::endl;
    return 0;
}
