// C++ program to illustrate inserting a Node in
// a Circular Doubly Linked list in begging, end
// and middle
#include <bits/stdc++.h>
using namespace std;

// Structure of a Node
struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
};

// Function to insert a node at the end
void insertNode(struct Node** start, int value)
{
	// If the list is empty, create a single node
	// circular and doubly list
	if (*start == NULL)
	{
		struct Node* new_node = new Node;
		new_node->data = value;
		new_node->next = new_node->prev = new_node;
		*start = new_node;
		return;
	}

	// If list is not empty

	/* Find last node */
	Node *last = (*start)->prev;

	// Create Node dynamically
	struct Node* new_node = new Node;
	new_node->data = value;

	// Start is going to be next of new_node
	new_node->next = *start;

	// Make new node previous of start
	(*start)->prev = new_node;

	// Make last previous of new node
	new_node->prev = last;

	// Make new node next of old last
	last->next = new_node;
}

// Function to display the
// circular doubly linked list
void displayList(struct Node* start)
{
	struct Node *temp = start;

	while (temp->next != start)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("%d ", temp->data);
}

// Function to search the particular element
// from the list
int searchList(struct Node* start, int search)
{
	// Declare the temp variable
	struct Node *temp = start;
	
	// Declare other control
	// variable for the searching
	int count=0,flag=0,value;
	
	// If start is NULL return -1
	if(temp == NULL)
		return -1;
	else
	{
		// Move the temp pointer until,
		// temp->next doesn't move
		// start address (Circular Fashion)
		while(temp->next != start)
		{
			// Increment count for location
			count++;
			// If it is found raise the
			// flag and break the loop
			if(temp->data == search)
			{
				flag = 1;
				count--;
				break;
			}
			// Increment temp pointer
			temp = temp->next;
		}
		// Check whether last element in the
		// list content the value if contain,
		// raise a flag and increment count
		if(temp->data == search)
		{
			count++;
			flag = 1;
		}
		
		// If flag is true, then element
		// found, else not
		if(flag == 1)
			cout<<"\n"<<search <<" found at location "<<
											count<<endl;
		else
			cout<<"\n"<<search <<" not found"<<endl;
	}
}

// Driver code
int main()
{
	/* Start with the empty list */
	struct Node* start = NULL;

	// Insert 4. So linked list becomes 4->NULL
	insertNode(&start, 4);

	// Insert 5. So linked list becomes 4->5
	insertNode(&start, 5);

	// Insert 7. So linked list
	// becomes 4->5->7
	insertNode(&start, 7);

	// Insert 8. So linked list
	// becomes 4->5->7->8
	insertNode(&start, 8);

	// Insert 6. So linked list
	// becomes 4->5->7->8->6
	insertNode(&start, 6);

	printf("Created circular doubly linked list is: ");
	displayList(start);
	
	searchList(start, 5);

	return 0;
}
