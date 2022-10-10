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

    LinkedList(Node* head)
    {
        this->head = head;
    }

    //one of the method is using hashing
    
    Node* intersection_recursive(Node* l1, Node* l2)
    {
        if(!l1 || !l2)
            return NULL;

        if(l1->data > l2->data)
            return intersection_recursive(l1, l2->next);

        if(l1->data < l2->data)
            return intersection_recursive(l1->next, l2);

        Node* temp = new Node(0);

        temp->data = l1->data;

        temp->next = intersection_recursive(l1->next, l2->next);

        return temp;
    }

    Node* intersection_sorted(Node* l1, Node* l2)
    {
        LinkedList ll;

        while(l1 and l2)
        {
            if(l1->data == l2->data)
            {
                ll.push(l1->data);
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1->data > l2->data)
            {
                l2 = l2->next;
            }
            else
            {
                l1 = l1->next;
            }
        }

        return ll.head;
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
    LinkedList l1;
    LinkedList l2;

    l1.push(9);
    l1.push(4);
    l1.push(2);
    l1.push(1);

    l2.push(9);
    l2.push(7);
    l2.push(5);
    l2.push(4);
    l2.push(3);

    l1.print();
    l2.print();

    LinkedList res;

    res.head = res.intersection_recursive(l1.head, l2.head);

    res.print();

    return 0;
}
