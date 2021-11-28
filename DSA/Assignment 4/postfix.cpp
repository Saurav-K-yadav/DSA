#include <iostream>
#include <cstring>
using namespace std;

class stack
{
public:
    int data;
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

void push(stack *&head, int data)
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

int pop(stack *&head)
{
    if (isEmpty(head))
    {
        return 0;
    }
    else
    {
        int data = head->data;
        stack *temp = head;
        head = head->next;
        free(temp);
        return data;
    }
}

int operation(int exp1, int exp2, char oper)
{
    switch (oper)
    {
    case '+':
        return exp2 + exp1;
        break;

    case '-':
        return exp2 - exp1;
        break;

    case '*':
        return exp1 * exp2;
        break;

    case '/':
        return exp2 / exp1;
        break;

    case '^':
        return exp2 ^ exp1;
        break;

    default:
        break;
        return -1;
    }
    return -1;
}

void post(stack *top, string str)
{
    int exp1, exp2;
    for (int i = 0; str[i]; i++)

    {
        if ((str[i] >= '0' ) && (str[i] <= '9'))
        {
            // to convert string to it's decimal value
            push(top, str[i]-'0');
            continue;
        }

        exp1 = pop(top);
        exp2 = pop(top);
        push(top, operation(exp1, exp2, str[i]));
    }
    display(top);
}

int main()
{
    stack *top = NULL;
    string exp;
    cout << "Please Enter the expression " << endl;
    cin >> exp;
    post(top, exp);
    return 0;
}