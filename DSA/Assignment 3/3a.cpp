#include <iostream>
using namespace std;

class node
{
public:
    node *next;
    node *prev;
    int data;
};

void push(node *&head_ref, int value)
{
    node *temp = new node;
    temp->data = value;
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
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    return;
}

void findSize(node *head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    cout << endl
         << "The size is : " << count << endl;
    return;
}

int main()
{
    node *head = new node;
    head = NULL;
    push(head, 1);
    push(head, 2);
    push(head, 3);
    display(head);
    findSize(head);
    return 0;
}