#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

void add(Node **head_ref, int new_data)
//insertion at the head
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = *(head_ref);
    *(head_ref) = new_node;
}
int size = 0;
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

Node *getNode(int data)
// function to create and return a Node
{
    Node *newNode = new Node();

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertPos(Node **current, int pos, int data)
//adding a node at a required position
{
    if (pos < 1 || pos > size + 1)
        cout << "Invalid position!" << endl;
    else
    {
        while (pos--)
        {
            if (pos == 0)
            {
                Node *temp = getNode(data);
                temp->next = *current;
                *current = temp;
            }
            else
                current = &(*current)->next;
        }
        size++;
    }
}

void printList(Node *node)
//printing the linked list
{
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
}
int main()
{
    Node *head = NULL;
    add(&head, 3);
    add(&head, 2);
    int number;
    cout << "Enter number to add at the begining" << endl;
    cin >> number;
    add(&head, number);
    int last;
    cout << "Enter an element to append at end" << endl;
    cin >> last;
    end(&head, last);
    int inbetween;
    cout << "Enter a number and it's position to add";
    cin >> inbetween;
    int pos;
    cin >> pos;
    size = 4;
    insertPos(&head, pos, inbetween);

    cout << "The linked list is " << endl;
    printList(head);
    return 0;
}