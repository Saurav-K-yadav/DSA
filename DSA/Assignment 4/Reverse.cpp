#include <iostream>
#include <cstring>
using namespace std;

class stack
{
public:
    char data;
    stack *next;

    stack(char data)
    {
        this->data = data;
        next = NULL;
    }
};

bool isEmpty(stack *head)
{
    return (head == NULL);
}

void push(stack *&head, char data)
{
    stack *temp = new stack(data);
    if (isEmpty(head))
    {
        head = temp;
        return;
    }

    else
        temp->next = head;
    head = temp;
}

void display(stack *head)
{
    if (isEmpty(head))
    {
        cout << "The stack is empty" << endl;
        return;
    }
    else
    {
        stack *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "   ";
            temp = temp->next;
        }
    }
}

void pop(stack *&head)
{
    if (isEmpty(head))
    {
        cout << "The stack is Empty" << endl;
        return;
    }
    else
    {
        stack *temp = head;
        head = head->next;
        cout << "deleting " << temp->data << endl;
        free(temp);
    }
}

void reverse(stack *head)
{
    while (!isEmpty(head))
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    stack *top = NULL;
    string s;
    cout << "Please Enter the string " << endl;
    getline(cin, s);

    //Here each charater of s is being taken and is pushed to the stack
    //s[i] will be null at the end so it will terminate at the end as last element of a string in null pointer

    for (int i = 0; s[i]; i++)
    {
        if (s[i] == ' ')
        {
            continue;
        }

        push(top, s[i]);
    }
    reverse(top);
    return 0;
}