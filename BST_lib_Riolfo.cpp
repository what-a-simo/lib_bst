#include "BST_lib_Riolfo.h"
#include <iostream>

using namespace std;

Node::Node(int k)
    : data{ k }, count{ 1 }, left_child{ nullptr }, right_child{ nullptr } {
};

Node* Node::insertR(int k) {
    if (this == NULL) {
        return new Node(k);
    }
    if (this->data == k) {
        this->count++;
        return this;
    }
    if (k < this->data) {
        this->left_child = this->left_child->insertR(k);
    }
    else {
        this->right_child = this->right_child->insertR(k);
    }
    return this;
}

Node* Node::insertI(int k) {
    Node* dad{ nullptr };
    Node* carry = this;
    bool is_left;
    while (carry != nullptr) {
        if (carry->data == k) {
            this->count++;
            return this;
        }
        if (k < carry->data) {
            dad = carry;
            carry = carry->left_child;
            is_left = true;
        }
        else if (k > carry->data) {
            dad = carry;
            carry = carry->right_child;
            is_left = false;
        }
    }
    if (is_left) {
        dad->left_child = new Node(k);
    }
    else if (!is_left) {
        dad->right_child = new Node(k);
    }
    return this;
}

bool Node::searchR(int k) {
    bool check;
    if (this == NULL) {
        check = false;
        return check;
    }
    if (k == this->data) {
        check = true;
        return check;
    }
    if (k < this->data) {
        check = this->left_child->searchR(k);
    }
    else {
        check = this->right_child->searchR(k);
    }
    return check;
}

bool Node::searchI(int k) {
    bool check{ false };
    Node* dad{ nullptr };
    Node* carry = this;
    while (carry != nullptr) {
        if (carry->data == k) {
            check = true;
            return check;
        }
        if (k < carry->data) {
            dad = carry;
            carry = carry->left_child;
        }
        else if (k > carry->data) {
            dad = carry;
            carry = carry->right_child;
        }
    }
    return check;
}

void Node::inOrder() {
    if (this == NULL) {
        return;
    }
    this->left_child->inOrder();
    cout << "[ " << this->data << " ]";
    this->right_child->inOrder();
}

istream& operator>>(istream& is, Node* node) {
    is >> node->data >> node->left_child >> node->right_child;
    return is;
}

ostream& operator<<(ostream& os, Node* node) {
    os << "Data -> " << node->data << " (" << node->count << ")" << endl;
    if (node->left_child != NULL && node->right_child != NULL) {
        os << "Left child: " << node->left_child->data << " (" << node->left_child->count << ")" << endl;
        os << "Right child: " << node->right_child->data << " (" << node->right_child->count << ")" << endl;
    } else if (node->right_child == NULL) {
        os << "Left_child: " << node->left_child->data << " (" << node->left_child->count << ")" << endl;
    } else {
        os << "Right child: " << node->right_child->data << " (" << node->right_child->count << ")" << endl;
    }
    return os;
}