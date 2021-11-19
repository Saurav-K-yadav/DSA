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
    temp->next = temp;
    temp->prev = temp;
    if (head_ref == NULL)
    {
        head_ref = temp;
        return;
    }
    temp->next = head_ref;
    node *temp1 = head_ref;
    while (temp1->next != head_ref)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    temp->prev = temp1;
    return;
}

void display(node *head)
{
    if (head == NULL)
    {
        cout << "Empty linked list";
    }

    node *temp = head;
    do
    {
        cout << temp->data << "  ";
        temp = temp->next;
    } while (temp != head);

    return;
}

bool check(node *head)
{

    if (head == NULL)
    {
        cout << "The list is empty";
        return false;
    }
    node *temp = head;
    do
    {
        temp = temp->next;
    } while ((temp->next != NULL) && (temp != head));

    if (temp == head)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    node *head = new node;
    head = NULL;
    push(head, 1);
    push(head, 2);
    push(head, 3);
    display(head);
    if (check(head))
    {
        cout << endl
             << "This is a circular linked list";
    }
    else
        cout << endl
             << "This is not a circular linked list";

    return 0;
}