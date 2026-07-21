#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* root, int data) {
        if (root == nullptr)
            return new Node(data);

        if (data < root->data)
            root->left = insert(root->left, data);
        else
            root->right = insert(root->right, data);

        return root;
    }

    bool search(Node* root, int key) {
        if (root == nullptr)
            return false;

        if (root->data == key)
            return true;

        if (key < root->data)
            return search(root->left, key);

        return search(root->right, key);
    }

    Node* findMin(Node* root) {
        while (root->left != nullptr)
            root = root->left;

        return root;
    }

    Node* remove(Node* root, int key) {
        if (root == nullptr)
            return nullptr;

        if (key < root->data)
            root->left = remove(root->left, key);

        else if (key > root->data)
            root->right = remove(root->right, key);

        else {
            // Case 1: No child
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }

            // Case 2: One child
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }

            if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = remove(root->right, temp->data);
        }

        return root;
    }

    void inorder(Node* root) {
        if (root == nullptr)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void destroy(Node* root) {
        if (root == nullptr)
            return;

        destroy(root->left);
        destroy(root->right);
        delete root;
    }

public:
    BST() {
        root = nullptr;
    }

    ~BST() {
        destroy(root);
    }

    void insert(int data) {
        root = insert(root, data);
    }

    bool search(int key) {
        return search(root, key);
    }

    void remove(int key) {
        root = remove(root, key);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder: ";
    tree.inorder();

    cout << "Search 40: " << tree.search(40) << endl;
    cout << "Search 100: " << tree.search(100) << endl;

    tree.remove(50);

    cout << "After deleting 50: ";
    tree.inorder();

    return 0;
}
