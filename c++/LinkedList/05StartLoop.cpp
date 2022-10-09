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
    }
};


struct LinkedList
{
    Node* head;

    LinkedList()
    {
        head = NULL;
    }

    Node* hash_first_in_loop()
    {
        Node* temp = head;

        unordered_set<Node*> node_ptrs;

        while(temp != NULL)
        {
            if(node_ptrs.find(temp) != node_ptrs.end())
                break;

            node_ptrs.insert(temp);
            temp = temp->next;
        }

        return temp;
    }

    Node* floyd_len_first_in_loop()
    {
        Node* slow_ptr = head;
        Node* fast_ptr = head;

        while(slow_ptr && fast_ptr && fast_ptr->next)
        {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;

            if(slow_ptr == fast_ptr)
            {
                break;
            }
        }

        Node* t = fast_ptr;
        int k = 0;

        while(t)
        {
            k++;
            t = t->next;

            if(t == fast_ptr)
                break;
        }

        slow_ptr = head;
        fast_ptr = head;
        
        int temp = k;

        while(temp < k)
        {
            fast_ptr = fast_ptr->next;
            temp++;
        }

        while(fast_ptr && slow_ptr)
        {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next;

            if(slow_ptr == fast_ptr)
                break;
        }

        return slow_ptr;
    }

    // using floyd's loop detection - most optimized algorithm
    Node* floyd_first_in_loop()
    {
        Node* slow_ptr = head;
        Node* fast_ptr = head;

        while(slow_ptr && fast_ptr && fast_ptr->next)
        {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;

            if(slow_ptr == fast_ptr)
            {
                break;
            }
        }

        slow_ptr = head;

        while(slow_ptr && fast_ptr)
        {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next;

            if(slow_ptr == fast_ptr)
            {
                break;
            }
        }

        return slow_ptr;
    }

    Node* ptr_to_position(int n)
    {
        Node* temp = head;
        int counter = 0;

        while(counter < n && temp != NULL)
        {
            temp = temp->next;
            counter++;
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
    ll.push(24);
    ll.push(32);
    ll.push(76);
    
    ll.print();

    Node* s = ll.ptr_to_position(1);
    Node* e = ll.ptr_to_position(3);

    e->next = s;

    Node* t = ll.hash_first_in_loop();

    cout << t->data << endl;


    return 0;
}
