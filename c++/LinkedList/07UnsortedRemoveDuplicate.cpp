#include<iostream>
#include<unordered_set>

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

    void two_loop_remove_duplicates()
    {
        Node* outer = head;
        Node* inner = head;
        Node* prev = NULL;

        while(outer)
        {
            inner = outer->next;
            prev = outer;

            while(inner)
            {
                if(outer->data == inner->data)
                {
                    Node* t = inner;
                    inner = inner->next;
                    free(t);
                    prev->next = inner;
                }
                else
                {
                    prev = inner;
                    inner = inner->next;
                }
            }

            outer = outer->next;
        }
    }

    void hash_remove_duplicates()
    {
        Node* current = head;
        Node* prev = NULL;
        unordered_set<int> track;

        while(current)
        {
            if(track.find(current->data) != track.end())
            {
                prev->next = current->next;
                free(current);
            }
            else
            {
                prev = current;
                track.insert(current->data);
            }

            current = prev->next;
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

    ll.push(5);
    ll.push(54);
    ll.push(7);
    ll.push(7);
    ll.push(54);

    ll.print();

    ll.two_loop_remove_duplicates();

    ll.print();

    return 0;
}
