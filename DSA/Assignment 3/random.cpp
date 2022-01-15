//Given a doubly linked list having exactly one of the node pointing to a random node in the list,
//  the task is to correct this random pointer in the doubly linked list, such that it points to the expected node.

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
};

void push(node *&head_ref, int data)
{
    node *temp = new node;
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if (head_ref == NULL)
    {
        head_ref = temp;
        return;
    }
    node *traverse = head_ref;
    while (traverse->next != NULL)
    {
        traverse = traverse->next;
    }
    traverse->next = temp;
    temp->prev = traverse;
    return;
}

void display(node *head)
{
    if (head == NULL)
    {
        cout << "The list is empty" << endl;
        return;
    }
    node *temp1 = head;
    while (temp1 != NULL)
    {
        cout << temp1->data << "  ";
        temp1 = temp1->next;
    }
    cout << endl;
    return;
}

int main()
{
    node *head = NULL;
    int number;
    cout << "Enter the number of nodes" << endl;
    cin >> number;
    cout << "Please Enter the numbers" << endl;
    for (int i = 0; i < number; i++)
    {
        int value;
        cin >> value;
        push(head, value);
    }
    display(head);
    return 0;
}