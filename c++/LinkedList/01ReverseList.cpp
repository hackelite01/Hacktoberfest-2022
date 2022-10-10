#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList {
    Node* head;
    LinkedList()
    {
        head = NULL;
    }

    void iterative_reverse()
    {
        Node* current = head;
        Node *prev = NULL, *next = NULL;

        while (current != NULL) {
            next = current->next;

            current->next = prev;

            prev = current;
            current = next;
        }

        head = prev;

    }

    Node* recursive_reverse(Node* head)
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        Node* rest = recursive_reverse(head->next);
        head->next->next = head;

        head->next = NULL;

        return rest;
    }
    
    void print()
    {
        Node* temp = head;
        while(temp != NULL)
        {
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



int main(void){

    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);

    ll.print();

    ll.iterative_reverse();

    ll.print();

    ll.head = ll.recursive_reverse(ll.head);

    ll.print();

    return 0;
}
