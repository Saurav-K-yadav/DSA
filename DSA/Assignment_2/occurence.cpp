#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

void end(Node **head_ref, int new_data)
//Insertion at the end
{
    Node *new_node = new Node();
    Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

void display(Node *node)
//Prints the linked list
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void occurance(Node **head_ref, int num)
{
    Node *temp = *head_ref;
    int count = 1;
    while (temp != NULL)
    {
        if (temp->data == num)
        {
            cout << "position " << count << endl;
            count++;
        }
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    int size = 1;
    char choice = 'a';
    while (choice != 'N' && choice != 'n')
    {
        cout << "Enter number to add";
        int number;
        cin >> number;
        end(&head, number);
        cout << "Press N to exit";
        cin >> choice;
    }
    display(head);
}