#ifndef NODE_HPP
#define NODE_HPP

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
    bool searchR(int K);
    bool searchI(int k);
    void inOrder();
};

#endif // NODE_HPP