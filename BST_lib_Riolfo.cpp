#include "BST_lib_Riolfo.hpp"

Node::Node(int x)
    : data{x}, count{1}, left_child{nullptr}, right_child{nullptr} {};
    
Node* Node::insertI(int x) {
    Node* root = this;
    Node* current = root;
    Node* dad{nullptr};
    bool is_left;
    while(root != nullptr) {
        if (root->data == x) {
            root->count++;
            return current;
        }
        if (x < root->data) {
            dad = root;
            root = root->left_child;
            is_left = true;
        } else if (x > root->data) {
            dad = root;
            root = root->right_child;
            is_left = false;
        }
    }
    if (is_left) {
        dad->left_child = new Node(x);
    } else if (!is_left) {
        dad->right_child = new Node(x);
    }
    return current;
}