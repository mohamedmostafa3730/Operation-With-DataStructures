#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* lift, *right;

    Node(int value) {
        data = value;
        lift = right = NULL;
    }
};

class BST {
    public:
    Node* root;

    BST() {
        root = NULL; 
    }
    Node* Insert(Node* Root,int item) { //first func
        if(Root==NULL) {  //case 1 => do not have root
            Node* newNode = new Node(item); //Create a new node with the given value
            Root = newNode;    //Assign Root to new node  
        }
        else if (item < Root->data) {  //case 2 => the element lesser data of Root
        Root->lift = Insert(Root->lift,item) //going to Recur on the left child
        }

        else  //case 3 => the element greater data of Root
        Root->right = Insert(Root->right,item);  //going to Recur on the rite child

        return Root; // return if make recur
    }

    void Insert(int item) {
        root = Insert(root,item);
    }

    void preOrder(Node* Root) {
        if(Root==NULL)
         return;
        cout << Root->data << "\t";
        preOrder(Root->lift);
        preOrder(Root->right);
    }

    void inOrder(Node* Root) {
        if(Root==NULL)
         return;
        inOrder(Root->lift);
        cout << Root->data << "\t";
        inOrder(Root->right);
    }

    void postOrder(Node* Root) {
        if(Root==NULL)
         return;
        postOrder(Root->lift);
        postOrder(Root->right);
        cout << Root->data << "\t";
    }
    
    Node* Search(Node* Root,int key) {
        if(Root==NULL)
        return NULL;

        else if (Root->data==key)
        return Root;

        else if (key<Root->data)
        return Search(Root->lift,key);

        else
        return Search(Root->right,key);
    }

    bool Search(int key) {
        Node* result = Search(Root,key);

        if (result==NULL)
        return false;

        else
        return true;
    }

    Node* findMin(node* Root) {
        if (Root==NULL)
        return Root;

        else if (Root->lift==NULL)
        return root;

        else
        return findMin(Root->lift);    
    }

    Node* findMax(Node* Root) {
        if (Root==NULL)
        return Root;

        else if (Root->right==NULL)
        return root;

        else
        return findMax(Root->right);
        }

    Node* Delete(Node* Root, int item) {
        if (Root==NULL) return NULL;                                                //Empty Tree
        if (item < Root->data) Root->lift = Delete(Root->lift, item);            //item exists in left sub-tree
        else if (item > Root->data) Root->right = Delete(Root->right,item);     //item exists in rite-tree
        else {  // item exists in Parent node 
                //[ leave node - have one childe left - have one childe rite - have 2 children]
            if (Root->lift==NULL&&Root->right==Root) {    //leave node
                Root=NULL;
            }

            if else (Root->lift!=NULL&&Root->right==Root) { //have one childe left
                Root->data = Root->lift->data;
                delete Root->lift;
                Root->lift = NULL;
            }
            
            if else (Root->lift==NULL&&Root->right!=Root) { //have one childe rite 
                Root->data = Root->right->data;
                delete Root->right;
                Root->right = NULL;
            }

            else { //have 2 children
                Node* Max = findMax(Root->lift);
                Root->data = Max->data;
                Root->lift = Delete(Root->lift,Max->data);

            }

        }

        return Root;
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
    B1.preOrder(B1.root);
    cout << "===========================================================================" << endl;
    B1.Delete(22);
    B1.preOrder(B1.root);

    

}