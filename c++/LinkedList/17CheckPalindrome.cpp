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

    //uisng mid pointer
    bool checkPalindrome_pointer()
    {
        Node* slow = head;
        Node* fast = head;

        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* mid = slow;

        bool odd = (fast) ? true : false;

        if(odd)
            mid = mid->next;

        Node* temp = head;
        
        Node* current = mid;
        Node *prev = slow, *next = NULL;

        while(current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        Node* tail = prev;
        current = head;

        while(current != tail and current != mid)
        {
            if(current->data != tail->data)
            {
                return false;
            }

            current = current->next;
            tail = tail->next;
        }

        tail = prev;
        prev = NULL;
        next = NULL;

        while(tail )

        

        return true;
    }


    // using stacks 
    bool checkPalindrome_stack()
    {
        stack<int> stack_checker;

        Node* temp = head;

        while(temp)
        {
            stack_checker.push(temp->data);
            temp = temp->next;
        }

        bool flag = true;
        temp = head;

        while(!stack_checker.empty())
        {
            if(stack_checker.top() != temp->data)
            {
                flag = false;
                break;
            }

            temp = temp->next;
            stack_checker.pop();
        }

        return flag;
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
    ll.push(3);
    ll.push(4);
    ll.push(4);
    ll.push(3);
    ll.push(9);

    ll.print();

    cout << ll.checkPalindrome_pointer() << endl;

    return 0;
}
