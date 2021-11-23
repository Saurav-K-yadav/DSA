#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

void push(node *&head_ref, int data)
{
    node *temp = new node();
    temp->data = data;
    temp->next = temp;
    if (head_ref == NULL)
    {
        head_ref = temp;
        return;
    }
    node *traverse = head_ref;
    while (traverse->next != head_ref)
    {
        traverse = traverse->next;
    }
    traverse->next = temp;
    temp->next = head_ref;
    return;
}

void display(node *head)
{
    if (head == NULL)
    {
        cout << "The list is empty" << endl;
        return;
    }
    int count = 1;
    node *temp1 = head;
    do
    {

        cout << temp1->data << "  ";
        temp1 = temp1->next;
    } while (temp1 != head);
    cout << endl;
    return;
}

//To check parity continue to use & operator with number and it's precedence till you get number value as 0000
bool parityCheck(unsigned int number)
{
    bool parity = false;
    while (number)
    {
        parity = !parity;
        number = (number) & (number - 1);
    }
    return parity;
    //odd->true,even->false
}

void deleteNode(node *&head_ref, node *del)
{
    if (head_ref == del)
        head_ref = del->next;
    node *temp = head_ref;
    while (temp->next != del)
    {
        temp = temp->next;
    }
    temp->next = del->next;
    free(del);
    return;
}

void deleteEven(node *&head)
{
    if (head == NULL)
    {
        cout << "The head is empty" << endl;
        return;
    }
    if (head == head->next)
    {
        if (!parityCheck(head->data))
        {
            head = NULL;
        }
        return;
    }
    node *check = head;
    while (check->next != head)
        check = check->next;
    node *temp1 = head;
    node *forward = temp1->next;
    while (temp1 != check)
    {
        forward = temp1->next;
        if (!parityCheck(temp1->data))
        {
            deleteNode(head, temp1);
        }
        temp1 = forward;
    }

    if (!parityCheck(temp1->data))
    {
        deleteNode(head, temp1);
    }

    if (head == head->next)
    {
        if (!parityCheck(head->data))
        {
            head = NULL;
        }
        return;
    }
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
    cout << endl;

    deleteEven(head);
    cout << endl;

    display(head);
    return 0;
}