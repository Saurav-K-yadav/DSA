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
        return;
    }
    else
    {
        stack *temp = head;
        head = head->next;
        free(temp);
    }
}

int precedence(char str)
{
    if ((str == '+') || (str == '-'))
        return 1;
    else if ((str == '*') || (str == '/'))
    {
        return 2;
    }
    else if (str == '^')
    {
        return 3;
    }
    else
        return 0;
}

void infixToPostfix(stack *&top, string str)
{
    string result;
    for (int i = 0; str[i]; i++)
    {
        if (((str[i] <= 'z') && (str[i] >= 'a')) || ((str[i] <= 'Z') && (str[i] >= 'A')) || ((str[i] <= '9') && (str[i] >= '0')))
        {
            result += str[i];
        }

        else if (str[i] == '(')
        {
            push(top, str[i]);
        }

        else if (str[i] == ')')
        {
            while (top != NULL)
            {
                if (top->data == '(')
                {
                    break;
                }

                result += top->data;
                pop(top);
            }
            pop(top);
        }

        else
        {
            int n = precedence(str[i]);
            if ((top == NULL) || (top->data == '(') || (n > precedence(top->data)))
            {
                push(top, str[i]);
            }
            else
            {
                while ((top != NULL) && (n <= precedence(top->data)))
                {
                    if ((top->data == '(') || (top->data == '{') || (top->data == '[') || (top->data == ')') || (top->data == '}') || (top->data == ']'))
                    {
                        break;
                    }
                    result += top->data;
                    pop(top);
                }
                push(top, str[i]);
            }
        }
    }
    cout << result;
}

int main()
{
    stack *top = NULL;
    string inp;
    cout << "Please Enter the expression " << endl;
    getline(cin, inp);
    infixToPostfix(top, inp);
    display(top);
    return 0;
}