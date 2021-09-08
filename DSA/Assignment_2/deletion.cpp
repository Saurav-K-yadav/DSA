#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

void add(Node **head_ref, int new_data)
//insertion at the head
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = *(head_ref);
    *(head_ref) = new_node;
}

void display(Node *node)
//Prints the linked list
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void nodeDeleteBegining(Node **head_ref)
//Deletion from the begining i.e. head is to be deleted
{
    Node *temp = *head_ref;

    if ((temp != NULL))
    {
        *head_ref = temp->next;
        delete temp;
        return;
    }
    else
        cout << "Error, Create a list first" << endl;
    delete temp;
}

void nodeDeleteEnd(Node **head_ref)
{
    //delete the node fro the end
    Node *temp = *head_ref;
    if (temp == NULL)
    {
        cout << "Create a list first";
    }
    if (temp->next == NULL)
    {
        free(temp);
        
    }
    while (temp != NULL && temp->next != NULL)
    {
        temp = temp->next;
    }

    delete temp;
}

void search(Node **head_ref, int val)
{ //search for an element in the node
    Node *temp = *head_ref;
    int count = 1;
    while (temp != NULL && temp->data != val)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {

        cout << "The element " << val << " is found at position " << count << endl;
    }
    else
        cout << "NOT FOUND !!!" << endl;
}

int main()
{
    Node *head = NULL;
    add(&head, 60);
    add(&head, 1);
    add(&head, 2);
    add(&head, 3);
    add(&head, 4);
    add(&head, 5);
    display(head);

    nodeDeleteEnd(&head);
    display(head);

    nodeDeleteBegining(&head);
    display(head);

    search(&head, 2);

    nodeDeleteEnd(&head);
    display(head);
}