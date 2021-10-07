#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    struct Node *next;
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

void reverse(Node **head)
{//create three pointers
//set current as head
    Node *current = new Node();
    current = *head;
    //initialize others as NULL
    Node *prev = new Node();
    prev = NULL;
    Node *next = new Node();
    next = NULL;
    //while current is not at the end
    while (current != NULL)
    {
        //next is set as current's next
        next = current->next;
        //we change direction of flow of linked list
        current->next = prev;
        //store it in prev
        prev = current;
        //increase current
        current = next;
    }
    //set head as prev as it has null at the end
    *head = prev;
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

    reverse(&head);
    cout << "\nReversed Linked list \n";
    display(head);
    return 0;
}