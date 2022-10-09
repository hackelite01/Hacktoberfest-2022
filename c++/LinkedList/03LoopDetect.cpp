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
    
    // usuage of data structure
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

    // the other variation of this problem requires that there should be a flag in the Node struct which will tell if that particular Node has been visited or not. 
    // In this we just have to check the flag if that has been visited or not.

    // using Floyd's Cycle Finding Algorithm
    bool floyd_detect_loop()
    {
        Node *slw_ptr = head;
        Node *fst_ptr = head;
        
        while(slw_ptr && fst_ptr && fst_ptr->next)
        {
            slw_ptr = slw_ptr->next;
            fst_ptr = fst_ptr->next->next;

        if(slw_ptr == fst_ptr)
            {
                return true;
            }
        }

        return false;
    }

    //point every node to a particular node(personaaly don't like it at all)
    bool pointer_detect_loop()
    {
        Node* t = new Node(0);
        Node* temp = head;

        while(temp != NULL)
        {
            if(temp->next == NULL)
            {
                return false;
            }

            if(temp->next == t)
            {
                return true;
            }

            Node* ne = temp;
            temp = temp->next;

            ne->next = t;
        }

        return false;
    }

    //string length method

    int distance(Node* first, Node* last)
    {
        int counter = 0;
        Node* current = first;

        while(current != last)
        {
            counter += 1;
            current = current->next;
        }

        return counter+1;
    }

    bool len_detect_loop()
    {
        Node* first = head;
        Node* last = head;

        int curr_length = 0;
        int prev_length = -1;

        while(curr_length > prev_length && last != NULL)
        {
            prev_length = curr_length;
            curr_length = distance(first, last);

            last = last->next;
        }

        if(last == NULL)
        {
            return false;
        }
        else
        {
            return true;
        }
            
    }

    // assign new data to each node when visited, if the data mathces then we can say that loop is there

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
            temp = temp->next;
        }
        cout << endl;
    }

};

int main(void)
{
    LinkedList ll;

    ll.push(12);
    ll.push(18);
    ll.push(89);
    ll.push(65);

    ll.print();

    Node* s = ll.ptr_to_position(1);
    Node* e = ll.ptr_to_position(3);

    e->next = s;

    if(ll.len_detect_loop())
        cout << "Loop" << endl;
    else
        cout << "No Loop" << endl;

    return 0;
}
