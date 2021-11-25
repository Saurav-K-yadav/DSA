#include <iostream>
#include <cstdlib>
using namespace std;

#define size 10
class stack
{
public:
    int top;
    int arr[size];
    stack()
    {
        top = -1;
    }
};

bool isFull(stack s)
{
    if (s.top == (size - 1))
    {
        return true;
    }
    else
        return false;
}

bool isEmpty(stack s)
{
    if (s.top == -1)
    {
        return true;
    }
    else
        return false;
}

void push(stack &s, int x)
{
    if (!isFull(s))
    {
        s.top++;
        s.arr[s.top] = x;
    }
    else
        cout << "OVERFLOW" << endl;
};

void pop(stack &s)
{
    if (isEmpty(s))
    {
        cout << "The stack is empty " << endl;
    }
    else
    {
        int temp = s.arr[s.top];
        s.top--;
        cout << "The deleted element is : " << temp;
    }
}

void peek(stack s)
{
    if (isEmpty(s))
    {
        cout << "The stack is Empty " << endl;
    }
    else
    {
        cout << "The top element is : ";
        cout << s.arr[s.top] << endl;
    }
}

void display(stack s)
{
    if (!isEmpty(s))
    {
        cout << "The elements of the stack are as follow " << endl;
        for (int i = s.top; i >= 0; i--)
        {
            cout << s.arr[i] << "  ";
        }
    }
    else
        cout << "The Stack is Empty ";
    cout << endl;
}

int main()
{
    stack s;
    int n = 0;
    while (n != 7)
    {
        cout << "please choose one of the options " << endl;
        cout << "1: Push " << endl;
        cout << "2: pop " << endl;
        cout << "3: check if empty " << endl;
        cout << "4: check if full " << endl;
        cout << "5: display " << endl;
        cout << "6: peek " << endl;
        cout << "7: quit " << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "Please enter the number to push " << endl;
            int number;
            cin >> number;
            push(s, number);
            break;

        case 2:
            pop(s);
            break;

        case 3:
            if (isEmpty(s))
            {
                cout << "The stack is Empty" << endl;
            }
            else
                cout << "The stack is not Empty " << endl;
            break;

        case 4:
            if (isFull(s))
            {
                cout << "The list is Full " << endl;
            }
            else
                cout << "The list is not full " << endl;
            break;

        case 5:
            display(s);
            break;

        case 6:
            peek(s);
            break;

        case 7:
            exit(EXIT_SUCCESS);
            break;

        default:
            cout << "Please choose a valid option" << endl;
            break;
        }
        cout << endl;
    }

    return 0;
}