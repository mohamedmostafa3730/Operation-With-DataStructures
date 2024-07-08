#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node() {
        data=0;
        next=NULL;
        }
    };

class Queue {
    public:
    Node* front;
    Node* rear;

    Queue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        if (front==NULL)
        return true;
        else
        return false;
    }

    void Enqueue(int item) {
        Node* neoNode = new Node();
        neoNode->data = item;
        if(isEmpty())
         front = rear = neoNode;
        else {
            rear->next = neoNode;
            rear = neoNode;
        }
    }

    void disPlay() {
        Node* temp = front;
        while(temp!=NULL) {
            cout << temp->data << "\t";
            temp=temp->next;
        }
        cout << endl;       
    }
    
    int  Dequeue() {
        int deletValeo; 
        if(isEmpty())
        cout << "\n \t the Queue is empty " << endl;
        else if (front==rear) {
            delete front;
            front = rear = NULL;
        }        
        else {
            Node* delptr = front;
            front = front->next;
            deletValeo = delptr->data;
            delete delptr; 
        }
        return deletValeo;
    }

    int getFront() {
        return front->data;
    }
    
    int getRear() {
        return rear->data;
    }

    int count() {
        int counter = 0;
        Node* temp = front;
        while (temp!=NULL){
            counter++;
            temp=temp->next;
        }
        return counter;
    }

    bool isFound(int item) {
        bool found = false;
        Node* temp = front;
        while (temp!=NULL){
            if (temp->data==item)
            return true;
            temp=temp->next;
        }
        return found;
    }

    void clear() {
        while (!isEmpty()) {
            Dequeue();
        }
    }
};


int main() {
    int size,item;
    Queue Q1;   
    cout << "\n \t Enter your size of Queue \n";
    cin>>size;
    for(int i=0;i<size;i++) {
        cout << "\n \t Enter your item num " << i << endl;
        cin>>item;
        Q1.Enqueue(item);
        cout << "\n \t The count of items is/are " << Q1.count() << endl;
    }
    Q1.disPlay();
    cout << "==============================================" << endl;
    Q1.Dequeue();
    Q1.disPlay();
    cout << "\n \t The count of items is/are " << Q1.count() << endl;
    cout << "==============================================" << endl;
    Q1.Dequeue();
    Q1.disPlay();
    cout << "\n \t The count of items is/are " << Q1.count() << endl;
    cout << "==============================================" << endl;
    cout << "\n \t The item to start is: " << Q1.getFront() << endl;
    cout << "\n \t The item to end is: " << Q1.getRear() << endl;
    cout << "==============================================" << endl;
    cout << "\n \t what is item to search it ? " << endl;
    cin >> item;
    if(Q1.isFound(item))
    cout << "\n \t Item is found \n";
    else
    cout << "\n \t Item is not found \n";
    cout << "==============================================" << endl;
    Q1.clear();
    Q1.disPlay();
    cout << "================ After Clear =================" << endl;
}