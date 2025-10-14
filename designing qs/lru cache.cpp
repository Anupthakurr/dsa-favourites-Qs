qs link -----> https://leetcode.com/problems/lru-cache/
  
  
#include <bits/stdc++.h>
using namespace std;

// Doubly Linked List Node
class Node {
public:
    int key, val;
    Node* prev;
    Node* next;

    Node(int _key, int _val) {
        key = _key;
        val = _val;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
    int cap; // capacity
    unordered_map<int, Node*> mp; // key -> Node*
    Node* head; // dummy head
    Node* tail; // dummy tail

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // 🔹 Helper: add node right after head
    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    // 🔹 Helper: delete a node
    void deleteNode(Node* delNode) {
        Node* prevNode = delNode->prev;
        Node* nextNode = delNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // 🔹 Get value of key
    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];
        int value = node->val;

        // Move this node to front (most recently used)
        mp.erase(key);
        deleteNode(node);
        addNode(new Node(key, value));
        mp[key] = head->next;

        return value;
    }

    // 🔹 Insert or update key-value pair
    void put(int key, int value) {
        // If key already exists, remove it
        if (mp.find(key) != mp.end()) {
            Node* existingNode = mp[key];
            mp.erase(key);
            deleteNode(existingNode);
        }

        // If cache full, remove least recently used
        if (mp.size() == cap) {
            Node* lruNode = tail->prev;
            mp.erase(lruNode->key);
            deleteNode(lruNode);
        }

        // Insert new node right after head
        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};
