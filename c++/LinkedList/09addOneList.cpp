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

    void addOne_storing()
    {
        Node* current = head;
        Node* prev = NULL;
        Node* non_nine = NULL;
        int checker = 1;

        while(current)
        {
            if(current->data == 9 and checker)
            {
                non_nine = prev;
                checker = 0;
            }
            else if(current->data != 9)
            {
                checker = 1;
            }

            prev = current;
            current = current->next;
        }

        
        non_nine = new Node(0);
        non_nine->next = head;
        head = non_nine;

        non_nine->data += 1;
        current = non_nine->next;

        while(current)
        {
            current->data = 0;
            current = current->next;
        }
    }

    int addOne_recursive(Node* current)
    {
        if(!current)
            return 1;

        int k = addOne_recursive(current->next);

        if(k)
        {
            if(current->data == 9)
            {
                current->data = 0;
                return 1;
            }
            else
            {
                current->data += 1;
                return 0;
            }
        }

        return 0;
    }

    void addOne_recursive_last()
    {
        addOne_recursive(head);

        if(head->data == 0)
        {
            Node* t = new Node(1);
            t->next = head;
            head = t;
        }
    }

    void addOne_reverse()
    {
        Node* current = head;
        Node *prev = NULL, *next = NULL;

        while(current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;

        current = head;
        int carry = 1;

        while(current)
        {
            if(carry)
            {
                if(current->data == 9)
                {
                    current->data = 0;
                    carry = 1;
                }
                else
                {
                    current->data += 1;
                    break;
                }
            }

            current = current->next;
        }


        current = head;
        prev = NULL, next = NULL;

        while(current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;

        if(head->data == 0)
        {
            Node* t = new Node(1);
            t->next = head;
            head = t;
        }
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
    ll.push(9);
    ll.push(9);
    ll.push(9);

    ll.print();

    ll.addOne_storing();

    ll.print();

    return 0;
}
