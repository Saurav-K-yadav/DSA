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

//delete a node at the given position
void deleteNode(struct Node **head_ref, struct Node *del)
{
    if (*head_ref == NULL || del == NULL)
        return;

    if (*head_ref == del)
        *head_ref = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;
    if (del->prev != NULL)
        del->prev->next = del->next;
    free(del);
}
void deleteNodeAtGivenPos(struct Node **head_ref, int n)
{
    if (*head_ref == NULL || n <= 0)
        return;
    struct Node *current = *head_ref;
    int i;
    for (int i = 1; current != NULL && i < n; i++)
        current = current->next;
    if (current == NULL)
        return;
    deleteNode(head_ref, current);
}

int main()
{
    Node *head = NULL;
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    display(&head);
    deleteNodeAtGivenPos(&head, 1);
    display(&head);
}