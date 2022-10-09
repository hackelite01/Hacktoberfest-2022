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

    bool isCircular()
    {
        Node* temp = head;

        if(!temp)
            return true;

        temp = temp->next;

        while(temp and temp != head)
        {
            temp = temp->next;
        }

        return (temp == head);
    }

    Node* ptr_to_position(int n)
    {
       Node* temp = head;

       int count = 0;

       while(temp and count < n)
       {
           temp = temp->next;
           count++;
       }

       return temp;
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

    ll.push(3);
    ll.push(7);
    ll.push(9);
    ll.push(11);
    ll.push(31);

    ll.print();

    Node* s = ll.ptr_to_position(0);
    Node* e = ll.ptr_to_position(4);

    //e->next = s;

    //ll.print();

    cout << ll.isCircular() << endl;
    return 0;
}
