// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template<typename T>
class BST {
 private:
    struct Node {
        T value;
        int count;
        Node* left;
        Node* right;
    };
    Node* root;
    Node* addNode(Node* root, const T& val) {
        if (root == nullptr) {
            root = new Node;
            root->value = val;
            root->count = 1;
            root->left = root->right = nullptr;
        } else if (val < root->value) {
            root->left = addNode(root->left, val);
        } else if (val > root->value) {
            root->right = addNode(root->right, val);
        } else {
            root->count++;
        }
        return root;
    }
    int searchNode(Node* root, const T& val) {
        if (root == nullptr) {
            return 0;
        } else if (root->value == val) {
            return root->count;
        } else if (root->value > val) {
            return searchNode(root->left, val);
        } else {
            return searchNode(root->right, val);
        }
    }
    int heightTree(Node *root) {
        if (root == nullptr) {
            return 0;
        } else {
            int L = heightTree(root->left);
            int R = heightTree(root->right);
            if (L > R) {
                return L++;
            } else {
                return R++;
            }
        }
    }

 public:
    BST() : root(nullptr) {}
    void add(const T& value) {
        root = addNode(root, value);
    }
    int search(const T& value) {
        return searchNode(root, value);
    }
    int height() {
        return heightTree(root);
    }
};
#endif  // INCLUDE_BST_H_
