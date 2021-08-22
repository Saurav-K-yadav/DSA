#include <iostream>
using namespace std;
int main()
{
    int arrary[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> arrary[i];
    }
    int search;
    cout << "Enter the number to search";
    cin >> search;
    for (int i = 0; i < 10; i++)
    {
        if (search == arrary[i])
        {
            cout << "Number at position " << i + 1;
        }
    }
}