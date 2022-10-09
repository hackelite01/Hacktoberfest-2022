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

void delete_element_circular(Node **head, int key)
{
    // if the linked list is empty
    if(*head == NULL)
        return;

    // if there is only one node in the linked list 
    if((*head)->next == (*head) and (*head)->data == key)
    {
        free(*head);
        *head = NULL;
        return;
    }

    Node* current = *head;
    Node* prev = NULL;

    //if the data is at the head
    if((*head)->data == key)
    {
        while(current->next != *head)
        {
            current = current->next;
        }

        current->next = (*head)->next;
        free(*head);
        *head = current->next;
        return;
    }

    current = *head;

    while(current->next != NULL and current->next->data != key)
    {
        current = current->next;
    }

    if(current->next->data == key)
    {
        prev = current->next;
        current->next = current->next->next;
        free(prev);
    }
    else
    {
        cout << "Key not found." << endl;
    }
        
}

int main(void)
{
    LinkedList ll;

    ll.push(9);
    ll.push(3);
    ll.push(1);
    ll.push(5);
    ll.push(6);

    ll.print();

    Node* s = ll.ptr_to_position(0);
    Node* e = ll.ptr_to_position(4);

    e->next = s;

    delete_element_circular(&ll.head, 6);

    ll.print();

    return 0;
}
