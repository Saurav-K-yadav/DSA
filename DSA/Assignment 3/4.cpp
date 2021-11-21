#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    char data;
    node *next;
    node *prev;
};

void add(node *(&head_ref), char text)
{
    node *temp = new node;
    temp->data = text;
    temp->next = NULL;
    temp->prev = NULL;
    if (head_ref == NULL)
    {
        head_ref = temp;
        return;
    }

    node *temp1 = head_ref;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    temp->prev = temp1;
}

void stringToText(node *&head_ref, string text)
{
    if (head_ref == NULL)
        add(head_ref, text[0]);

    {
        for (int i = 1; i < text.size(); i++)
        {
            add(head_ref, text[i]);
        }
    }
}

//used to test if list is properly created by printing it's elements
// void display(node *head_ref)
// {
//     node *temp = head_ref;
//     while (temp != NULL)
//     {
//         cout << temp->data << "  ";
//         temp = temp->next;
//     }
//     delete temp;
// }

bool checkPalidrome(node *head_ref)
{
    if (head_ref == NULL)
    {
        cout << "The list is empty" << endl;
        return true;
    }
    node *temp1 = head_ref;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    node *temp2 = head_ref;
    while (temp1 != temp2)
    {
        if ((temp1->data) != temp2->data)
        {
            return false;
        }
        if (temp2->next = temp1)
        {
            return true;
        }
        temp1 = temp1->prev;
        temp2 = temp2->next;
    }
    return true;
}

int main()
{
    node *head = new node;
    head = NULL;
    string text;
    cout << "PLease input the string : ";
    cin >> text;
    stringToText(head, text);
    // display(head);
    if (checkPalidrome(head))
    {
        cout<< "The given string is palidrome";
    }
    else
    {
        cout<< "The given list is not palidrome";
    }
    return 0;
}