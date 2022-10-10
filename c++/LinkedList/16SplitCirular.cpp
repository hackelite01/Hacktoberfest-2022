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

    void split_circular(Node **head1, Node **head2)
    {
        Node* slow = head;
        Node* fast = head;

        // it will stop in both the cases when the number of nodes is odd and when the number of nodes is even
        while(fast->next != head and fast->next->next != head)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // we are checking if the number of nodes was even so fast pointer will be two behind
        if(fast->next->next == head)
            fast = fast->next;

        // setting the head of the first circular half
        *head1 = head;

        // checking if there is only one node in the LinkedList
        if(head->next != head)
            *head2 = slow->next;

        // making the second circular half
        fast->next = slow->next;

        // making the first circular half
        slow->next = head;


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
    
    ll.push(9);
    ll.push(2);
    ll.push(4);
    ll.push(6);
    ll.push(3);

    LinkedList ll1, ll2;

    Node* s = ll.ptr_to_position(0);
    Node* e = ll.ptr_to_position(4);

    e->next = s;

    ll.split_circular(&ll1.head, &ll2.head);

    //ll1.print();

    ll2.print();

    return 0;
}
