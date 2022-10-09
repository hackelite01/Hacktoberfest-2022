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

    Node* reverse_by_group(Node* head, int k)
    {
        if(!head)
            return NULL;

        Node* current = head;
        Node *prev = NULL, *next = NULL;
        int count = 0;

        while(current != NULL && count < k)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        if(next != NULL) // current can also be used
        {
            head->next = reverse_by_group(next, k);
        }

        return prev;
    }

    void print()
    {
        Node* temp = head;

        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }

};

int main(void)
{
    LinkedList ll;
    int k = 2;

    ll.push(90);
    ll.push(75);
    ll.push(43);
    ll.push(20);
    ll.push(7);

    ll.print();

    ll.head = ll.reverse_by_group(ll.head, k);

    ll.print();

    return 0;
}
