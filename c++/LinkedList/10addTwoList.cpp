#include<iostream>
#include<stack>

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

    //using recursion
    // First, we calculate the sizes of both the linked lists, size1 and size2, respectively.
    // Then we traverse the bigger linked list, if any, and decrement till the size of both become the same.
    // Now we traverse both linked lists till the end.
    // Now the backtracking occurs while performing addition.
    // Finally, the head node is returned to the linked list containing the answer.
    
    Node* addition(Node* l1, Node* l2, int s1, int s2)
    {
        Node* newnode = new Node(0);

        if(l1->next == NULL and l2->next == NULL)
        {
            newnode->data = l1->data + l2->data;

            return newnode;
        }

        Node* returnednode = new Node(0);

        if(s1 == s2)
        {
            returnednode = addition(l1->next, l2->next, s1, s2 - 1);

            newnode->data = l1->data + l2->data + returnednode->data / 10;

        }
        else
        {
            returnednode = addition(l1, l2->next, s1, s2 - 1);

            newnode->data = l2->data + returnednode->data / 10;
        }

        returnednode->data = returnednode->data % 10;

        newnode->next = returnednode;

        return newnode;
    }

    Node* addLinkedList_recursive(Node* r, Node* l)
    {
        Node* t1 = r;
        Node* t2 = l;
        Node* ans = NULL;

        int s1 = 0, s2 = 0;

        while(t1)
        {
            s1++;
            t1 = t1->next;
        }

        while(t2)
        {
            s2++;
            t2 = t2->next;
        }
        
        Node* returnednode;

        if(s2 > s1)
        {
            returnednode = addition(l, r, s2, s1);
        }
        else
        {
            returnednode = addition(r, l, s1, s2);
        }

        if(returnednode->data > 9)
        {
            Node* temp = new Node(1);
            returnednode->data = returnednode->data % 10;
            temp->next = returnednode;
            ans = temp;
        }
        else
        {
            ans = returnednode;
        }

        return ans;
    }

    // using reversing the list 
    
    Node* reverse(Node* head)
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

        return prev;
    }

    Node* addTwoList_reverse(Node* lst1, Node* lst2)
    {
        Node* l1 = reverse(lst1);
        Node* l2 = reverse(lst2);

        Node* prev = NULL;
        int carry = 0;
        Node* current = NULL;

        while(l1 || l2)
        {
            int sum = (l1 ? l1->data : 0) + (l2 ? l2->data : 0) + carry;

            Node* temp = new Node(sum % 10);

            if(sum > 9)
                carry = 1;
            else
                carry = 0;

            if(current != NULL)
                prev->next = temp;
            else
                current = temp;

            prev = temp;

            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }

        if(carry == 1)
        {
            Node* temp = new Node(1);
            prev->next = temp;
            prev = temp;
        }

        current = reverse(current);

        return current;
    }

    //using stack

    Node* addTwoList_stack(Node* l1, Node* l2)
    {
        stack<Node*> s1, s2, s3;

        while(l1)
        {
            s1.push(l1);
            l1 = l1->next;
        }

        while(l2)
        {
            s2.push(l2);
            l2 = l2->next;
        }

        int carry = 0;

        while(!s1.empty() and !s2.empty())
        {
            int sum = s1.top()->data + s2.top()->data + carry;
            Node* temp = new Node(sum % 10);
            s3.push(temp);

            if(sum > 9)
                carry = 1;
            else
                carry = 0;

            s1.pop();
            s2.pop();
        }


        while(!s1.empty())
        {
            int sum = s1.top()->data + carry;
            Node* temp = new Node(sum % 10);
            s3.push(temp);

            if(sum > 9)
                carry = 1;
            else
                carry = 0;
            
            s1.pop();
        }

        while(!s2.empty())
        {
            int sum = s2.top()->data + carry;
            Node* temp = new Node(sum % 10);
            s3.push(temp);

            if(sum > 9)
                carry = 1;
            else
                carry = 0;

            s2.pop();
        }

        if(carry == 1)
        {
            Node* temp = new Node(1);
            s3.push(temp);
        }

        Node* h = NULL;

        if(!s3.empty())
        {
            h = s3.top();
        }

        while(!s3.empty())
        {
            Node* temp = s3.top();
            s3.pop();

            if(s3.size() == 0)
            {
                temp->next = NULL;
            }
            else
            {
                temp->next = s3.top();
            }
        }

        return h;
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
    LinkedList ll1;
    LinkedList ll2;

    ll1.push(0);
    ll1.push(5);
    ll1.push(4);

    ll2.push(4);
    ll2.push(5);

    ll1.print();
    ll2.print();

    LinkedList ll3;
    
    ll3.head = ll3.addTwoList_reverse(ll1.head, ll2.head);

    ll3.print();

    return 0;
}
