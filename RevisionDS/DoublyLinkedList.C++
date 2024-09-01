#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node()
    {
        this->value = 0;
        this->next = nullptr;
        this->prev = nullptr;
    }

    Node(int value, Node *next, Node *prev)
    {
        this->value = value;
        this->next = next;
        this->prev = prev;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        head = tail = nullptr;
    }

    void AddToFirst(int item)
    {
        Node *NewNode = new Node(item, head, nullptr);
        if (head == nullptr)
            head = tail = NewNode;
        else
        {
            head->prev = NewNode;
            head = NewNode;
        }
    }

    void AddToLast(int item)
    {
        Node *NewNode = new Node(item, nullptr, tail);
        if (head == nullptr)
            head = tail = NewNode;
        else
        {
            tail->next = NewNode;
            tail = NewNode;
        }
    }

    void RemoveFromFirst() {
        if (head==nullptr) return;
        if (head==tail) {
            delete head;
            head = tail = nullptr;
        }
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    }
    

    void RemoveFromlast() {
        if (head==nullptr) return;
        if (head==tail) {
            delete head;
            head = tail = nullptr;
        }
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }

    void print() {
        Node* tamp = head;
        while (tamp!=nullptr) {
            cout << tamp->value << " -> ";
            tamp=tamp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    //TEST//
    DoublyLinkedList D1;
    for (int i=10;i<=100;i+=10) {
        D1.AddToLast(i);
    }
    D1.print();
        cout << "================" << endl;
}