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

void occurencedelete(Node **ref, int key)
{
    //delete all the occurence
    Node *temp = *ref;
    Node *dummy;
    while (temp != NULL && temp->data == key)
    {
        //If first elements are matched too

        *ref = temp->next;
        delete temp;
        temp = *ref;
    }
    if (temp == NULL)
    {
        return;
    }

    while (temp->next != NULL)
    {
        if (temp->next->data == key)
        {
            dummy = temp->next;
            temp->next = temp->next->next;
            delete dummy;
        }
        else
        {
            temp = temp->next;
        }
    }
}

void occurance(Node **head_ref, int num)
{

    //count the number of the occurence
    Node *temp = *head_ref;
    int count = 0;
    while (temp != NULL)
    {
        if (temp->data == num)
        {
            count++;
        }
        temp = temp->next;
    }
    cout << "Total number of occurence : " << count << endl;
    cout << "Deleting the number " << endl;
    occurencedelete(head_ref, num);
}

int main()
{
    Node *head = NULL;
    cout << "Enter the number of elements " << endl;
    int size;
    int key;
    cin >> size;
    while (size)
    {
        cout << "Enter number to add ";
        int number;
        cin >> number;
        end(&head, number);
        size--;
    }
    cout << "Enter the number to find it's occurence " << endl;

    cin >> key;
    display(head);

    occurance(&head, key);
    cout << "New list : " << endl;
    display(head);
}