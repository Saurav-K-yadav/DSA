#include <iostream>
using namespace std;
int main()
{
    cout << "Enter number of elements" << endl;
    int number;
    cin >> number;
    int *array = new int[number];
    for (int i = 0; i < number; i++)
    {
        cout << "Enter the element number " << i + 1 << endl;
        cin >> (*(array + i));
    }
    for (int i = 0; i < number - 1; i++)
    {
        for (int j = 0; j < number - i - 1; j++)
        {

            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    int total = ((number + 1) * (number + 2)) / 2;
    for (int i = 0; i < number; i++)
    {
        total -= array[i];
    }
    cout << "The missing number is " << total << endl;
    return 0;
}