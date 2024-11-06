#include <iostream>

using namespace std;


// --------------------------------------Nodo----------------------------------------------------


struct node{
    int data;
    int count;
    node* left_child;
    node* right_child;
    node(int x) {
        data = x;
        count = 1;
        left_child = nullptr;
        right_child = nullptr;
    }
};


// ----------------------Aggiungiere nodi in modo ricorsivo----------------------------------------


node* apply_r(node* root, int x) {
    if (root == NULL) {
        return new node(x);
    }
    if (root->data == x) {
        root->count++;
        return root;
    }
    if (x < root->data) {
        root->left_child = apply_r(root->left_child, x);
    } else {
        root->right_child = apply_r(root->right_child, x);
    }
    return root;
}


// ------------------------Aggiungiere nodi in modo interativo--------------------------------------


node* apply_i(node* root, int x) {
    node* current = root;
    node* dad{nullptr};
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
        dad->left_child = new node(x);
    } else if (!is_left) {
        dad->right_child = new node(x);
    }
    return current;
}


// ----------------------------Verificare se e' un BST----------------------------------------------


bool is_bst(node* root) {
    bool check;
    bool condition = true;
    if (root->left_child == NULL || root->right_child == NULL) {
        if (root->left_child == NULL && root->right_child == NULL) {
            check = true;
            return check;
        } else if (root->left_child == NULL) {
            check = is_bst(root->right_child);
            condition = false;
        } else if (root->right_child == NULL) {
            check = is_bst(root->left_child);
            condition = false;
        } 
    }
    if (condition) {
        if (root->data > root->left_child->data) {
            check = is_bst(root->left_child);
            condition = true;
        }
        if (root->data < root->right_child->data) {
            check = is_bst(root->right_child);
            condition = true;
        }
        if (root->data < root->left_child->data || root->data > root->right_child->data) {
            check = false;
            return check;
        }
    }
    return check;
}


// ----------------------------Trovare un nodo---------------------------------------------------


bool find_data(node* root, int x) {
    bool check;
    if (root == NULL) {
        check = false;
        return check;
    }
    if (x == root->data) {
        check = true;
        return check;
    }
    if (x < root->data) {
        check = find_data(root->left_child, x);
    } else {
        check = find_data(root->right_child, x);
    }
    return check;
}


// --------------------------------Rimuovere nodi------------------------------------------------


node* remove_node(node* root, int x) {
    if (x == root->data) {
        if (root->left_child == NULL && root->right_child == NULL) {
            root = nullptr;
            delete root;
            return root;
        } else if (root->left_child == NULL) {
            root = root->right_child;
            root->right_child = nullptr;
            delete root->right_child;
            return root;
        } else if (root->right_child == NULL) {
            root = root->left_child;
            root->left_child = nullptr;
            delete root->left_child;
            return root;
        }
    }
    if (x < root->data) {
        root->left_child = remove_node(root->left_child, x);
    } else {
        root->right_child = remove_node(root->right_child, x);
    }
    return root;
}


// -----------------------------Preorder---------------------------------------------------------


void preorder(node* root) {
    if (root == NULL) {
        return;
    }
    cout << "[ " << root->data << " ]";
    preorder(root->left_child);
    preorder(root->right_child);
}


// -------------------------------Inorder--------------------------------------------------------


void inorder(node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left_child);
    cout << "[ " << root->data << " ]";
    inorder(root->right_child);
}


// -------------------------------Postorder------------------------------------------------------


void postorder(node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left_child);
    inorder(root->right_child);
    cout << "[ " << root->data << " ]";
}


// ----------------------Calcolare l'altezza di un BST-------------------------------------------


int level(node* root) {
    if (root == NULL) {
        return 0;
    }
    int l = level(root->left_child);
    int r = level(root->right_child);
    return max(l, r)+1;
}

int max(int l, int r) {
    if (l > r) {
        return l;
    } else if (l < r) {
        return r;
    } else {
        return r;
    }
}