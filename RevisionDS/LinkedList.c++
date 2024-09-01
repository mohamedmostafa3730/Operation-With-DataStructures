#include <iostream>
using namespace std;

class Node {
    public:
    Node *next;
    int item;

    Node() {
        this->next=NULL;
        this->item=0;
    }

    Node(Node *next,int item ) {
        this->next=next;
        this->item=item;
    }
};

class LinkedList {
    private:
    Node* head;
    public:

    LinkedList(){
    head = NULL;
    }

    void AddToFirst(int valeo) {
        Node* NewNode = new Node(head,valeo);
        head = NewNode;
    }

    void RemoveFromFirst() {
        head=head->next;
    }

    void AddToLast(int valeo) {
        if(head==NULL) {
            AddToFirst(valeo);
            return;
        }
        Node* NewNode = new Node(head,valeo);
        Node* temp = head;
        while (temp->next!=NULL) {
            temp=temp->next;
        }
        temp->next = NewNode;

    }

    void RemoveFromLast() {
        if (head==NULL) return;
        if(head->next==NULL) {
            delete head;
            head=NULL;
            return;
        }
        Node* temp = head;
        Node* temp2 = head;
        while (temp->next!=NULL) {
            temp2=temp;
            temp=temp->next;
        }
        delete temp;
        temp->next=NULL;
    }

    void Print() {
        Node* temp = head;
        while (temp!=NULL) {
            cout << temp->item << " -> " ; 
            temp=temp->next;
        }
        cout << "NULL" << "\n" ;
    }
};

int main() {
    LinkedList L1;
    for (int i = 10 ; i <= 100 ; i+=10) {
    L1.AddToFirst(i);
    }
    L1.Print();
}
