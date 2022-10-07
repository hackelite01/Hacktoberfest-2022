#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Linked List Node
class Node
{
	public:
	int data;
	Node* next;
};

Node* newNode(int key)
{
	Node *temp = new Node;
	temp->data = key;
	temp->next = NULL;
	return temp;
}

Node *rearrangeEvenOdd(Node *head)
{
	if (head == NULL)
		return NULL;

	Node *odd = head;
	Node *even = head->next;
	Node *evenFirst = even;

	while (1)
	{
		if (!odd || !even || !(even->next))
		{
			odd->next = evenFirst;
			break;
		}

		odd->next = even->next;
		odd = even->next;

		if (odd->next == NULL)
		{
			even->next = NULL;
			odd->next = evenFirst;
			break;
		}

		even->next = odd->next;
		even = odd->next;
	}

	return head;
}

void printlist(Node * node)
{
	while (node != NULL)
	{
		cout << node->data << "->";
		node = node->next;
	}
	cout << "NULL" << endl;
}

int main(void)
{
	Node *head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);

	cout << "Given Linked List\n";
	printlist(head);

	head = rearrangeEvenOdd(head);

	cout << "Modified Linked List\n";
	printlist(head);

	return 0;
}
