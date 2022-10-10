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

    // another approach would be using stacks

    void reverse()
    {
        Node* current = head;
        Node *prev = NULL, *next = NULL;

        while(current)
        {
            next = current->next;
            current->prev = next;
            current->next = prev;

            prev = current;
            current = next;

        }

        head = prev;
    }


    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        temp->prev = NULL;

        if(head != NULL)
            head->prev = temp;

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

    dll.push(5);
    dll.push(3);
    dll.push(1);
    dll.push(8);
    dll.push(6);

    dll.print();

    dll.reverse();

    dll.print();

    return 0;
}
