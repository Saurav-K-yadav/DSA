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

void remove(node *temp, node *&head_ref)
{
    if (head_ref == NULL || temp == NULL)
        return;
    if (head_ref == temp)
        head_ref = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    free(temp);
    return;
}

void removeEven(node *&head_ref)
{
    node *ptr = head_ref;
    node *next;
    while (ptr != NULL)
    {
        next = ptr->next;

        if (!parityCheck(ptr->data))
            remove(ptr, head_ref);

        ptr = next;
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
    // cout << endl;

    removeEven(head);
    cout << endl;

    display(head);
    return 0;
}