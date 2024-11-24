#include "BST_lib_Riolfo.hpp"
#include <iostream>

using namespace std;

Node::Node(int k)
    : data{k}, count{1}, left_child{nullptr}, right_child{nullptr} {};
    
Node* Node::insertR(int k) {
    Node* root = this;
    if (root == NULL) {
        return new Node(k);
    }
    if (root->data == k) {
        root->count++;
        return root;
    }
    if (k < root->data) {
        root->left_child = root->left_child->insertR(k);
    } else {
        root->right_child = root->right_child->insertR(k);
    }
    return root;
}
    
Node* Node::insertI(int k) {
    Node* root = this;
    Node* current = root;
    Node* dad{nullptr};
    bool is_left;
    while(root != nullptr) {
        if (root->data == k) {
            root->count++;
            return current;
        }
        if (k < root->data) {
            dad = root;
            root = root->left_child;
            is_left = true;
        } else if (k > root->data) {
            dad = root;
            root = root->right_child;
            is_left = false;
        }
    }
    if (is_left) {
        dad->left_child = new Node(k);
    } else if (!is_left) {
        dad->right_child = new Node(k);
    }
    return current;
}

void Node::inOrder() {
    Node* root = this;
    if (root == NULL) {
        return;
    }
    root->left_child->inOrder();
    cout << "[ " << root->data << " ]";
    root->right_child->inOrder();
}