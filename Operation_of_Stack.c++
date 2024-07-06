#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node() {
        data = 0;
        next = NULL;
    }
};
class Stack {
    Node* top;
    public:

    Stack() {
        top = NULL;
    }
    bool isEmpty() {
        if (top==NULL)
        return true;
        else 
        return false;
    }
    void push(int item) {
        Node* newNode = new Node();
        newNode->data = item;
        if (isEmpty()) {
            newNode->next = NULL;
            top = newNode;
        }
        else {
            newNode->next = top;
            top = newNode;
        }
        
         
    }
    void pop() {

    }
    void desplay() {
        Node* temp = top;
        while (temp!=NULL) {
            cout << temp->data << "\t" << endl;
            temp = temp ->next;
        }
        cout << endl;
    }




};
int main() {
    int item;
    Stack S1;
    
    for (int i =0 ; i<4 ; i++) {
        cout << "Enter the item ";
        cin >> item;
        S1.push(item);
        S1.desplay();
    }

}