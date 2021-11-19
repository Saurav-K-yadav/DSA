#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

node *push(node *head, int value)
{
    node *temp = head;
    if ((head) == NULL)
    {
        node *temp1 = new node();
        temp1->data = value;
        temp = temp1;
        temp1->next = temp;
    return temp;
    }

    node* newnode=new node();
    newnode->data=value;
    newnode->next=NULL;

    while (temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
    // head=newnode->next;
    return temp->next->next;
    
}

void display(node *head)
{
    if (head == NULL)
        cout << "List is empty" << endl;
    node *temp = head;
    do
    {
        cout << temp->data << endl;
        temp = temp->next;
    } while (temp != head);
    cout<<temp->data<<endl;
    }

int main()
{
    node *head = NULL;
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);
    head = push(head, 4);
    display(head);
}