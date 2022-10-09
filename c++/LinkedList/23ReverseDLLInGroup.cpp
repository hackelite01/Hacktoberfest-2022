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

void pushInHead(Node** head, Node* node);

struct DLinkedList
{
    Node* head;

    DLinkedList()
    {
        head = NULL;
    }    

    Node* reverseDLLbyN(Node* head, int key)
    {
        Node* current = head;
        Node* next = NULL;
        Node* newhead = NULL;

        int count = 0;

        // reversing the nodes from the start
        // we are doing it by pushing the nodes in the newhead
        // this will reverse the list from the given head till count reaches key 
        while(current and count < key)
        {
            next = current->next;
            pushInHead(&newhead, current);
            current = next;
            count++;
        }

        // if next is not NULL i.e there are still elements left for swapping from next node
        if(next)
        {
            head->next = reverseDLLbyN(next, key);
            head->next->prev = NULL;
        }

        newhead->prev = NULL;

        return newhead;
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

void pushInHead(Node** head, Node* node)
{
    node->next = *head;
    if(*head)
        (*head)->prev = node;

    *head = node;
}

int main(void)
{
    DLinkedList dll;

    dll.push(2);
    dll.push(4);
    dll.push(8);
    dll.push(10);

    dll.print();

    dll.head = dll.reverseDLLbyN(dll.head, 2);

    dll.print();

    return 0;
}
