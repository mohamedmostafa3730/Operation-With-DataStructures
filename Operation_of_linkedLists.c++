#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
};
class Linkedlist {
    public:
    Node* head;
    Linkedlist() {
        head = NULL;
    }
    bool isempty() {
        if(head==NULL)
        return true;
        else
        return false;
    }
    void insertFirst(int newValuo) {
        Node* Node1 = new Node();
        Node1->data=newValuo;
        if (isempty()) {
            Node1->next=NULL;
            head = Node1;
        }
        else {
            Node1->next=head;
            head = Node1;
        }
        
    }
    void Desplay() {
        Node* temp = head;
        while(temp!=NULL) {
            cout << temp->data << "\t";
            temp = temp->next;
        }
    }
    int count() {
        int counter = 0;
        Node* temp = head;
        while(temp!=NULL) {
            counter++;
            temp=temp->next;
        }
        return counter;
    }
    bool isfound(int key) {
        bool found = false;
        Node* temp = head;
        while(temp!=NULL) {
            if (temp->data==key)
                found = true;
                temp = temp->next;
        }
        return found;
    }
    void insertBefore(int item, int newValuo) {
        if (isfound(item)) {
            Node* newNode = new Node();
            newNode->data = newValuo;
            Node* temp = head;
            while (temp!=NULL && temp->next->data!=item) {
            temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode; 
        }
        else {
            cout << "soryy, this item is not found " << endl;
        }
        }
    
};
int main() {
    Linkedlist L1;

    if(L1.isempty())
    cout << "\n \t The Linkedlist is empty \t ";
    
    else
    cout << "\n \t The Linkedlist contain: " << L1.count() << "item/s \t" << endl;

    int item;
    cout << "\n \t Enter the item (1) \t" << endl;
    cin >> item;
    L1.insertFirst(item);
    L1.Desplay();
    
    cout << "\n \t Enter the item (2) \t" << endl;
    cin >> item;
    L1.insertFirst(item);
    L1.Desplay();
    
    cout << "\n \t Enter the item (3) \t" << endl;
    cin >> item;
    L1.insertFirst(item);
    L1.Desplay();

    cout << "\n \t The List contains are: " << L1.count() << endl;

    cout << "\n \t Enter Item to search for \n " << endl;
    cin >> item;
    if (L1.isfound(item))
    cout << "\n \t Item Found \n";
    else
    cout << "\n \t Item not Found \n";

    int newValeo;
    cout << "\n \t enter the item and the valeo  \t" << endl;
    cin >> item >> newValeo;
    L1.insertBefore(item,newValeo);
    L1.Desplay();
}

/*
Linkedlist L1;
    cout << "\n \t Welcome to Linkedlist program \t " << endl;
    if(L1.isempty()) 
        cout << "\n \t The Linkedlist is empty \t ";
    else
    cout << "\n \t The Linkedlist contain: " << L1.count() << "item/s \t" << endl;
    int item;
    int cho;
    cout << "\n \t============================================= \t"<<endl;
    cout << "\n \t 0- To exit for program \t"<< endl;
    cout << "\n \t 1- Enter the item to insert in the List \t" << endl;
    cout << "\n \t 2- Do you need to print items in list \t" << endl;
    cout << "\n \t 3- Do you need to know number of items in list? \t" << endl;
    cout << "\n \t 4- Do you need to search of spicific item? \t" << endl;
    while(cho!=0) {
        if ((cho==1)||(cho==2)||(cho==3)||(cho==4)||(cho==0));
        if (cho==1) {
        cout << "\n \t 1- Enter anathrt item to List \t" << endl;
        cin >> item;
        L1.insertFirst(item);
        }
        else if (cho==2) {
        L1.Desplay();
        }
        else if (cho==3) {
        cout << "\n \t The number of items is: " << L1.count() << "\t \n";
        }
        else if (cho==4) {
        int key;
        cout << "\n \t Enter the item to search it: \t" << endl;
        cin >> key;
        if(L1.Search(key)) {
            cout << "\n \t Item is found \t \n";
            }
            else {
                cout << "\n \t Item is not found \t \n";
                }
                }
        else {
            return;
        }    
            }
            */