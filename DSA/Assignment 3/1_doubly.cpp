#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};

//Insertions at the first of the list
void push(Node **head, int new_data)
{
    Node *temp = new Node();
    temp->data = new_data;
    temp->next = *head;
    temp->prev = NULL;
    *head = temp;
    if ((*head) != NULL)
    {
        (*head)->prev = temp;
    }
}

//insertion after a given node
void insertafter(Node *prev_node, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

//insetion at the end
void append(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    Node *last = *head_ref; 
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    new_node->prev = last;
    return;
}

//displays the elements
void display(Node **head)
{
    Node *temp = new Node();
    temp = *head;
    while ((temp) != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    display(&head);
    insertafter(head->next, 10);
    display(&head);
    append(&head, 20);
    display(&head);
}
