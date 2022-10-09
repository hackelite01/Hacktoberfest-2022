#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

struct DLinkedList
{
    Node* head;

    DLinkedList()
    {
        head = NULL;
    }

    void rotateByN(int key)
    {
        if(key == 0)
            return;

        Node* current = head;
        Node* last = head;

        while(last->next)
        {
            last = last->next;
        }

        last->next = head;
        head->prev = last;

        int count = 0;

        while(count < key)
        {
            current = current->next;
            last = last->next;
            count++;
        }

        last->next = NULL;
        current->prev = NULL;

        head = current;        
    }

    void push(int data)
    {
        Node* temp = new Node(data);
        if(head)
            head->prev = temp;
        temp->next = head;

        head = temp;
    }

    void print()
    {
        Node* temp = head;

        while(temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main(void)
{
    DLinkedList dll;

    dll.push(1);
    dll.push(2);
    dll.push(3);
    dll.push(4);
    dll.push(5);

    dll.print();

    dll.rotateByN(2);

    dll.print();

    return 0;
}
