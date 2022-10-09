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
    
    void findPair(int key)
    {
        Node* front = head;
        Node* back = head;

        while(back->next)
            back = back->next;

        bool found = false;

        while(back->next != front and back != front)
        {
            if(front->data + back->data == key)
            {
                cout << "(" << front->data << "," << back->data << ")" << endl;
                found = true;

                front = front->next;
                back = back->prev;
            }
            else if(back->data + front->data < key)
            {
                front = front->next;                
            }
            else
            {
                back = back->prev;
            }
        }

        if(!found)
        {
            cout << "No pair found." << endl;
        }

    }

    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
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

    dll.push(9);
    dll.push(8);
    dll.push(6);
    dll.push(5);
    dll.push(4);
    dll.push(2);
    dll.push(1);

    dll.print();

    dll.findPair(23);

    return 0;
}
