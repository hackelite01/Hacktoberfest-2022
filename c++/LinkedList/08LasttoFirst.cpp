#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList
{
    Node* head;

    LinkedList()
    {
        head = NULL;
    }

    void last_to_first()
    {
        Node* current = head;
        Node* prev = NULL;

        while(current->next)
        {
            prev = current;
            current = current->next;
        }

        prev->next = NULL;
        current->next = head;
        head = current;
    }

    void push(int data)
    {
        Node* temp = new Node(data);
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
    LinkedList ll;

    ll.push(5);
    ll.push(4);
    ll.push(87);

    ll.print();

    ll.last_to_first();

    ll.print();

    return 0;
}
