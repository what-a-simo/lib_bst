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

bool Node::isBst() {
    bool check;
    bool condition = true;
    if (this->left_child == NULL || this->right_child == NULL) {
        if (this->left_child == NULL && this->right_child == NULL) {
            check = true;
            return check;
        } else if (this->left_child == NULL) {
            check = this->right_child->isBst();
            condition = false;
        } else if (this->right_child == NULL) {
            check = this->left_child->isBst();
            condition = false;
        } 
    }
    if (condition) {
        if (this->data > this->left_child->data) {
            check = this->left_child->isBst();
            condition = true;
        }
        if (this->data < this->right_child->data) {
            check = this->right_child->isBst();
            condition = true;
        }
        if (this->data < this->left_child->data || this->data > this->right_child->data) {
            check = false;
            return check;
        }
    }
    return check;
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

Node* Node::deleteNode(int k) {
    if (k == this->data) {
        if (this->left_child == NULL && this->right_child == NULL) {
            delete this;
            return nullptr;
        } else if (this->left_child == NULL) {
            this->data = this->right_child->data;
            this->right_child = nullptr;
            delete this->right_child;
            return this;
        } else if (this->right_child == NULL) {
            this->data = this->left_child->data;
            this->left_child = nullptr;
            delete this->left_child;
            return this;
        }
    }
    if (k < this->data) {
        this->left_child = this->left_child->deleteNode(k);
    } else {
        this->right_child = this->right_child->deleteNode(k);
    }
    return this;
}

void Node::inOrder() {
    if (this == NULL) {
        return;
    }
    this->left_child->inOrder();
    cout << "[ " << this->data << " ]";
    this->right_child->inOrder();
}

void Node::preOrder() {
    if (this == NULL) {
        return;
    }
    cout << "[ " << this->data << " ]";
    this->left_child->preOrder();
    this->right_child->preOrder();
}

void Node::postOrder() {
    if (this == NULL) {
        return;
    }
    this->left_child->postOrder();
    this->right_child->postOrder();
    cout << "[ " << this->data << " ]";
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