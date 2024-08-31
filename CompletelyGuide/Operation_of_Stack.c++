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
    int pop() {
        int valeo;
        Node* delptr = top;
        valeo = top->data;
        top = top->next;
        delete delptr;
        return valeo;
    }
    void desplay() {
        Node* temp = top;
        while (temp!=NULL) {
            cout << temp->data << "\t" << endl;
            temp = temp ->next;
        }
        cout << endl;
    }
    int Peek() {
        return top->data;
    }
    int count() {
        int counter;
        Node* temp = top;
        while (temp!=NULL) {
            counter++;
            temp = temp->next;
        }
        return counter;
    }
    bool isFound(int item) {
        bool Found = false;
        Node* temp = top;
        while (temp!=NULL) {
            if (temp->data==item)
               Found = true;
            temp=temp->next;   
        }
        return Found;
    }
    bool isFull() {
        Node* ptr = new Node();
        if (ptr==NULL)
        cout << " the stake is Full" << endl;
    }
};
int main() {
    int item;
    Stack S1;
    
    for (int i =0 ; i<4 ; i++) {
        cout << "Enter the item ";
        cin >> item;
        S1.push(item);
        cout << "==========" << endl;
        S1.desplay();
        cout << "==========" << endl;
        cout << endl;
        S1.count();
    }
    cout << " this item " << S1.pop() << " is deleted " << endl;
    S1.desplay();

    cout << "enter the item to search for " << endl;
    cin >> item;
    S1.isFound(item);

    if (S1.isFound(item)) {
        cout << "is fond";
    }
    else {
        cout << "not fond";
    }


}