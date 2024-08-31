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
    
    Node* Search(Node* Snode,int key) {
        if(Snode==NULL)
        return NULL;

        else if (Snode->data==key)
        return Snode;

        else if (key<Snode->data)
        return Search(Snode->lift,key);

        else
        return Search(Snode->right,key);
    }

    bool Search(int key) {
        Node* result = Search(root,key);

        if (result==NULL)
        return false;

        else
        return true;
    }

    Node* findMin(node* Knode) {
        if (Knode==NULL)
        return Knode;

        else if (Knode->lift==NULL)
        return root;

        else
        return findMin(Knode->lift);    
    }

    Node* findMax(Node* Knode) {
        if (Knode==NULL)
        return Knode;

        else if (Knode->right==NULL)
        return root;

        else
        return findMax(Knode->right);
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

    int item;
    cout << "\n \t Enter your Search item: " << endl;
    cin >>item;
    if (B1.Search(item))
    cout << "\n \t item is found " << endl;

    else
    cout << "\n \t item is not found " << endl;

    cout << "===========================================================================" << endl;
    cout << "\n \t Find the minimum" << endl;
    Noded* item = B1.findMin(B1.root)[
        if ()
    ]
    if (findMin(B1))
}