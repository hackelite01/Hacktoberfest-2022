#include<iostream>
#include<unordered_map>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

struct DLinkedList
{
    Node* head;

    DLinkedList()
    {
        head = NULL;
    }
    
    // use of two pointers
    int countPairs_ptrs(Node* first, Node* last, int key)
    {
        // we are basically counting the pairs which give the sum as the key
        int count = 0;

        // only stop when either the first or the last reaches the end
        // or when the last pointer crosses the first pointer or when the pointers become same
        while(first and last and last->next != first and first != last)
        {
            if(first->data + last->data == key)
            {
                // when the key is found, increment both the pointers as well as the count
                count++;
                first = first->next;
                last = last->prev;
            }

            else if(first->data + last->data < key)
            {
                // increase first pointer when the sum is less than key 
                first = first->next;
            }

            else if(first->data + last->data > key)
            {
                // increase last pointer when the sum is more than key
                last = last->prev;
            }
        }

        return count;
    }

    int countTriplets_ptrs(int key)
    {
        if(!head)
            return 0;

        Node* current = NULL;
        Node* first = NULL;
        Node* last = head;

        int count = 0;

        while(last->next)
            last = last->next;

        for(current = head; current; current = current->next)
        {
            first = current->next;

            count += countPairs_ptrs(first, last, key - current->data);
        }

        return count;
    }


    // counting the triplets using unordered_map
    int countTriplets_hashing(int key)
    {
        unordered_map<int, Node*> um;

        Node* ptr = head;
        Node* ptr1 = NULL;
        Node* ptr2 = NULL;

        // variable for counting the numbers of triplets
        int count = 0;

        // putting all the values in the unordered_map so that they can be extracted in O(1)
        while(ptr)
        {
            um[ptr->data] = ptr;
            ptr = ptr->next;
        }

        // two pointers are used to traverse through the linked list  
        for(ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next)
        {
            for(ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
            {
                // we add both the elements of the nodes that we have traversed
                int rest_p = ptr1->data + ptr2->data;

                // we are checking that after subtracting the above value from the key, if there exists a value which will the third number that is present in the map or not
                // also ensuring that it don't give back the same pointer that is used as ptr1 or ptr2
                if(um.find(key - rest_p) != um.end() and um[key - rest_p] != ptr1 and um[key - rest_p] != ptr2)
                {
                    count++;
                }
            }
        }

        // we are returning the count divided by 3 because all the numbers would have been taken 3 times
        return (count / 3);
    }

    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        if(head)
            head->prev = temp;
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
    DLinkedList dll;
    
    dll.push(9);
    dll.push(8);
    dll.push(6);
    dll.push(5);
    dll.push(4);
    dll.push(2);
    dll.push(1);

    dll.print();

    cout << dll.countTriplets_ptrs(17) << endl;

    return 0;
}
