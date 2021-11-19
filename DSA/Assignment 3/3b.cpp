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

void findSize(node *head)
{
    int count = 0;
    node *temp = head;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);
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