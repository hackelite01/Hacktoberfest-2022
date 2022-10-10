#include<iostream>
#include<unordered_map>

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

    void map_remove_duplicate()
    {
        Node* temp = head;
        unordered_map<int, bool> check;

        while(temp)
        {
            if(check.find(temp->data) == check.end())
            {
                cout << temp->data << " ";
            }

            check[temp->data] = true;
            temp = temp->next;
        }
        cout << endl;
    }


    void remove_duplicate_recursive(Node* current)
    {
        if(current == NULL)
            return;

        if(current->next != NULL)
        {
            if(current->data == current->next->data)
            {
                Node* next = current->next;
                current->next = current->next->next;
                free(next);
                remove_duplicate_recursive(current);
            }
            else
            {
                remove_duplicate_recursive(current->next);
            }
        }
    }

    void remove_duplicate()
    {
        Node* current = head;

        if(current == NULL)
            return;

        while(current->next != NULL)
        {
            if(current->data == current->next->data)
            {
                Node* next = current->next->next;
                free(current->next);
                current->next = next;
            }
            else
            {
                current = current->next;
            }
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

        while(temp != NULL)
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

    ll.push(10);
    ll.push(23);
    ll.push(56);
    ll.push(56);
    ll.push(78);

    ll.print();

    ll.map_remove_duplicate();

    ll.print();

    ll.remove_duplicate_recursive(ll.head);

    ll.print();

    return 0;
}
