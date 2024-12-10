#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

using namespace std;

class Node {
    private:
        int data;
        int count;
        Node* left_child;
        Node* right_child;
    public:
        Node(int k);
        Node* insertR(int k);
        Node* insertI(int k);
        bool isBst();
        bool searchR(int K);
        bool searchI(int k);
        Node* deleteNode(int k);
        void inOrder();
        void preOrder();
        void postOrder();
        friend istream& operator>>(istream& is, Node* node);
        friend ostream& operator<<(ostream& os, Node* node);
};

#endif // NODE_HPP