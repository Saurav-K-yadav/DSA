// Reverse a doubly linked list in groups of given size
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
void addAtFirst(node *&head, int data)
{
    node *temp1 = head;
    node *add = new node;
    add->data = data;
    add->next = NULL;
    add->prev = NULL;
    if (head == NULL)
    {
        head = add;
        return;
    }
    add->next = temp1;
    temp1->prev = add;
    head = add;
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

node *reverse(node *head, int group)
{
    node *temp = head;
    node *newhead = NULL;
    for (int i = 0; i < group; i++)
    {
        addAtFirst(newhead, temp->data);
        temp = temp->next;
        if (temp == NULL)
        {
            break;
        }
    }
    if (temp != NULL)
    {
        node *traverse = newhead;
        while (traverse->next != NULL)
        {
            traverse = traverse->next;
        }

        traverse->next = reverse(temp, group);
    }
    return newhead;
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
    cout << "The given list is : " << endl;
    display(head);
    int group;
    cout << "Enter the size of each group " << endl;
    cin >> group;
    node *newhead = NULL;
    newhead = reverse(head, group);
    display(newhead);
    return 0;
}