#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
};

void push(Node **head_ref, int new_data)
{
    Node *new_node = (Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL)
    {
        (*head_ref)->prev = new_node;
    }
    (*head_ref) = new_node;
}

// Function to find the position of an integer in doubly linked list
void search(Node **head, int number)
{
    Node *temp = *head;
    int pos = 1;
    while ((temp->data != number) && (temp->next != NULL))
    {
        temp = temp->next;
        pos++;
    }
    if (temp->data != number)
    {
        cout << "Number not found";
    }
    else
    {
        cout << "The position is : " << pos << endl;
    }
}

int main()
{
    Node *head = NULL;
    int find;
    cout << "Enter a number to search";
    cin >> find;
    push(&head, 14);
    push(&head, 9);
    push(&head, 8);
    push(&head, 15);
    push(&head, 18);

    search(&head, find);

    return 0;
}