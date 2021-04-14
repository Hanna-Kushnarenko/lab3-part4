
#include<iostream>
 #include <cstdlib>
#include <time.h>
#include <cmath>
using namespace std;
 
// A structure representing a node of a linked list.
struct node
{
	int data;
	node *next;
};
 int rrand(int range_min, int range_max) {
    return rand() % (range_max - range_min + 1) + range_min;}
// A function creating a new node.
node* NewNode(int d)
{
	struct node *temp = new node;
	temp->data = d;
	temp->next = NULL;
	// Returning temp as the new node.
	return temp;
}
 
// A function adding the given data at the end of the linked list.
node* AddToList(node *tail, int data)
{
	struct node *newnode;
	newnode = NewNode(data);
 
	if(tail == NULL)
	{
		tail = newnode;
	}
	// If tail is not null assign newnode to the next of tail.
	else
	{
		tail->next = newnode;
		// Shift tail pointer to the added node.
		tail = tail->next;
	}
 
	return tail;
}
 
node* Merge(node* h1, node* h2)
{
	node *t1 = new node;
	node *t2 = new node;
	node *temp = new node;
 
	// Return if the first list is empty.
	if(h1 == NULL)
		return h2;
 
	// Return if the Second list is empty.
	if(h2 == NULL)
		return h1;
 
	t1 = h1;
 
	// A loop to traverse the second list, to merge the nodes to h1 in sorted way.
	while (h2 != NULL)
	{
		// Taking head node of second list as t2.
		t2 = h2;
 
		// Shifting second list head to the next.
		h2 = h2->next;
		t2->next = NULL;
 
		// If the data value is lesser than the head of first list add that node at the beginning.
		if(h1->data > t2->data)
		{
			t2->next = h1;
			h1 = t2;
			t1 = h1;
			continue;
		}
 
		// Traverse the first list.
		flag:
		if(t1->next == NULL)
		{
			t1->next = t2;
			t1 = t1->next;
		}
		// Traverse first list until t2->data more than node's data.
		else if((t1->next)->data <= t2->data)
		{
			t1 = t1->next;
			goto flag;
		}
		else
		{
			// Insert the node as t2->data is lesser than the next node.
			temp = t1->next;
			t1->next = t2;
			t2->next = temp;
		}
	}
 
	// Return the head of new sorted list.
	return h1;
}
 
 
// A function implementing Merge Sort on linked list using reference.
void MergeSort(node **head)
{
	node *first = new node;
	node *second = new node;
	node *temp = new node;
	first = *head;
	temp = *head;
 
	// Return if list have less than two nodes.
	if(first == NULL || first->next == NULL)
	{
		return;
	}
	else
	{
		// Break the list into two half as first and second as head of list.
		while(first->next != NULL)
		{
			first = first->next;
			if(first->next != NULL)
			{
				temp = temp->next;
				first = first->next;
			}
		}
		second = temp->next;
		temp->next = NULL;
		first = *head;
	}
 
	// Implementing divide and conquer approach.
	MergeSort(&first);
	MergeSort(&second);
 
	// Merge the two part of the list into a sorted one.      
	*head = Merge(first, second);
}
 
int main()
{
	long  i, num;
	struct node *head = new node;
	struct node *tail = new node;
	head = NULL;
	tail = NULL;
	long long n =10e8;
 
 
	// Create linked list.
	for(i = 0; i < n; i++)
	{
	
		num =rrand(-100000, 1000000);
        pow(num,10000);
		tail = AddToList(tail, num);
		if(head == NULL)
			head = tail;
	}
 
	// Send reference of head into MergeSort().
	MergeSort(&head);
 
	// Printing the sorted data.
//	cout<<"\nSorted Data ";
 
//	while(head != NULL) 
//	{
//		cout<<".."<<head->data;
//		head=head->next;
//	}
	return 0;	
}
