#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* lift, *right;

    Node(int valeo) {
        data = valeo;
        lift = right = NULL;
    }
};

class BST {
    public:
    Node* root;

    BST() {
        root = NULL;
    }
    Node* Insert(Node* pnode,int item) {
        if(pnode==NULL) {
            Node* newNode = new Node(item);
            pnode = newNode;
        }
        else if (item <pnode->data) {
        pnode->lift = Insert(pnode->lift,item);
        }

        else 
        pnode->right = Insert(pnode->right,item);

        return pnode;
    }

    void Insert(int item) {
        root = Insert(root,item);
    }

    void preOrder(Node* pnode) {
        if(pnode==NULL)
         return;
        cout << pnode->data << "\t";
        preOrder(pnode->lift);
        preOrder(pnode->right);
    }

    void inOrder(Node* pnode) {
        if(pnode==NULL)
         return;
        inOrder(pnode->lift);
        cout << pnode->data << "\t";
        inOrder(pnode->right);
    }

    void postOrder(Node* pnode) {
        if(pnode==NULL)
         return;
        postOrder(pnode->lift);
        postOrder(pnode->right);
        cout << pnode->data << "\t";
    }
};


int main() {
    BST B1;
    B1.Insert(21);
    B1.Insert(32);
    B1.Insert(43);
    B1.Insert(12);
    B1.Insert(22);
    B1.Insert(1);
    B1.Insert(5);
    B1.Insert(34);
    B1.Insert(343);
    B1.Insert(234);
    B1.Insert(359);

    B1.inOrder(B1.root);
    cout << "===========================================================================" << endl;
    B1.postOrder(B1.root);
    cout << "===========================================================================" << endl;
    B1.preOrder(B1.root);
    cout << "===========================================================================" << endl;
}