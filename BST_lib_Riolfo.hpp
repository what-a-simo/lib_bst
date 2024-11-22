#ifndef BST_LIB_RIOLFO_HPP
#define BST_LIB_RIOLFO_HPP

class Node {
    private:
        int data;
        int count;
        Node* left_child;
        Node* right_child;
    public:
        Node(int x);
        Node* insertI(int x);
        void inOrder();
};

#endif // BST_LIB_RIOLFO_HPP