#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

void add(Node **head_ref, int new_data)
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

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    free(temp);
}

void middle(Node **ref)
{
    int count = 0;
    if (*ref == NULL)
    {
        cout << "Empty list";
        return;
    }

    Node *sort = new Node();
    sort = *ref;
    while (sort->next != NULL)
    {
        sort = sort->next;
        count++;
    }
    sort = *ref;
    if (count % 2 == 1)
    {
        cout << "Even number of elements" << endl
             << "Displaying number closer to head as middle number" << endl;
    }

    for (int i = 0; i < count / 2; i++)
    {
        sort = sort->next;
    }
    cout << "Middle element is " << sort->data << endl;
}

int main()
{
    Node *head;
    head = NULL;
    cout << "Enter the number of elemets" << endl;
    int size;
    cin >> size;
    int number;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the number at position " << i + 1 << endl;
        cin >> number;
        add(&head, number);
    }
    display(head);
    middle(&head);
}