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

    bool hash_detect_loop()
    {
        Node* temp = head;
        unordered_set<Node*> node_ptrs;

        while(temp != NULL)
        {
            if(node_ptrs.find(temp) != node_ptrs.end())
                return true;

            node_ptrs.insert(temp);

            temp = temp->next;
        }

        return false;
    }

    void floyd_len_delete_loop()
    {
        Node* slw_ptr = head;
        Node* fst_ptr = head;

        // applying floyd's to find a loop node
        while(slw_ptr && fst_ptr && fst_ptr->next)
        {
            slw_ptr = slw_ptr->next;
            fst_ptr = fst_ptr->next->next;

            if(slw_ptr == fst_ptr)
            {
                break;
            }
        }

        Node* t = slw_ptr;
        int k = 0;

        // counting number of nodes in loop
        while(t)
        {
            t = t->next;
            k++;

            if(t == fst_ptr)
            {
                break;
            }
        }

        int temp = 0;

        slw_ptr = head;
        fst_ptr = head;

        // advancing the fast pointer forwards by k
        while(temp < k)
        {
            fst_ptr = fst_ptr->next;
            temp++;
        } 

        Node* prev = NULL;

        // increasing slow and fast by 1 so they meet at the staring loop node
        while(slw_ptr && fst_ptr)
        {
            prev = fst_ptr;
            slw_ptr = slw_ptr->next;
            fst_ptr = fst_ptr->next;

            if(slw_ptr == fst_ptr)
            {
                break;
            }
        }

        prev->next = NULL;
    }

    // one of the best method
    // after finding the node using floyd 
    // put slow+ptr to head and increment fst_ptr along slw_ptr with 1
    // they will meet at the origin node
    void floyd_delete_loop()
    {
        Node* slw_ptr = head;
        Node* fst_ptr = head;

        // applying floyd's to find a loop node 
        while(slw_ptr && fst_ptr && fst_ptr->next)
        {
            slw_ptr = slw_ptr->next;
            fst_ptr = fst_ptr->next->next;

            if(slw_ptr == fst_ptr)
            {
                break;
            }
        }
        
        // putting the slow at the head pointer 
        slw_ptr = head;
        Node* prev = NULL;

        // increasing the slow and fast by 1 so that they meet at the starting loop node at some point
        while(slw_ptr && fst_ptr)
        {
            prev = fst_ptr;
            slw_ptr = slw_ptr->next;
            fst_ptr = fst_ptr->next;

            if(slw_ptr == fst_ptr)
            {
                break;
            }
        }

        prev->next = NULL;
        
    }

    void delete_loop()
    {
        Node* temp = head;
        unordered_set<Node*> node_ptrs;
        Node* prev = NULL;

        while(temp != NULL)
        {
            if(node_ptrs.find(temp) != node_ptrs.end())
            {
                prev->next = NULL;
                return;
            }

            node_ptrs.insert(temp);
            prev = temp;
            temp = temp->next;
        }

    }

    Node* ptr_to_position(int n)
    {
        Node* temp = head;
        int count = 0;

        while(temp != NULL && count < n)
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

        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
};

int main(void)
{
    LinkedList ll;
    ll.push(16);
    ll.push(34);
    ll.push(36);
    ll.push(58);
    ll.push(7);

    ll.print();

    Node* s = ll.ptr_to_position(1);
    //cout << s->data << endl;
    Node* e = ll.ptr_to_position(4);

    e->next = s; 

    cout << ll.hash_detect_loop() << endl;

    ll.floyd_delete_loop();

    cout << ll.hash_detect_loop() << endl;    

    ll.print();

    return 0;
}
