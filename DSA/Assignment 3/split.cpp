#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void push(Node *&head_ref, int number)
{
    Node *temp = new Node;
    temp->data = number;
    temp->next = temp;
    if (!head_ref)
    {
        head_ref = temp;
        return;
    }
    else
    {
        Node *temp1 = head_ref;
        temp->next = head_ref;
        while (temp1->next != head_ref)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
        return;
    }
}

void printList(Node *head)
{
    Node *temp = head;
    if (head != NULL)
    {
        cout << endl;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
}

void split(Node *head,Node* &first,Node* &second)
{
    Node *fast = second;
    Node *slow = first;
    if (head == NULL)
    {
        cout << "The list is empty" << endl;
        return;
    }
        
        while ((fast->next != head) && (fast->next->next != head))
        {
            fast = (fast->next)->next;
            slow = slow->next;
        }
    if (fast->next!=head)
    {
        fast=fast->next;
    }
    fast->next=slow->next;
    second=slow->next;
    slow->next=head;
    
}

int main()
{
    Node *head = NULL;
    int total;
    cout << "Enter the total number of nodes " << endl;
    cin >> total;
    int values;
    cout << "Please Enter the values " << endl;
    for (int i = 0; i < total; i++)
    {
        cin >> values;
        push(head, values);
    }
    cout<<"The list is : "<<endl;
    printList(head);
    Node*first=head;
    Node* second=head;
    split(head,first,second);
    cout<<endl<<"The first list is : "<<endl;
    printList(first);
    cout<<endl<<"The Second list is : "<<endl;
    printList(second);
    return 0;
}