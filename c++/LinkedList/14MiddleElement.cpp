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

    Node* middle_element_odd()
    {
        Node* temp = head;
        Node* mid = head;
        
        int count = 0;

        while(temp)
        {

            if(count & 1)
                mid = mid->next;

            count++;
            temp = temp->next;
        }

        return mid;
    }

    Node* middle_element_ptrs()
    {
        Node* slow = head;
        Node* fast = head;

        while(slow and fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
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
        }
        cout << endl;
    }

};

int main(void)
{
    LinkedList ll;
    
    ll.push(9);
    ll.push(7);
    ll.push(3);
    ll.push(1);
    ll.push(2);


    cout << ll.middle_element_odd()->data << endl;

    return 0;
}
