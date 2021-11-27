#include <iostream>
#include <string>
using namespace std;

class stack
{
public:
	char data;
	stack *next;
	stack(char data)
	{
		this->data = data;
		this->next = NULL;
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
		free(temp);
	}
}

int main()
{
	stack *top = NULL;
	string inp;
	cout << "Please enter the expression" << endl;
	getline(cin, inp);
	for (int i = 0; inp[i]; i++)
	{
		if ((inp[i] == '(') || (inp[i] == '{') || (inp[i] == '['))
			push(top, inp[i]);
		if (((inp[i] == ')') && (top->data == '(')) || ((inp[i] == '}') && (top->data = '{')) || ((inp[i] == ']') && (top->data == '[')))
			pop(top);
	}
	if (isEmpty(top))
	{
		cout << "The given expression is balanced " << endl;
	}
	else
		cout << "The given expression is not balanced " << endl;

	return 0;
}