#include <iostream>
using namespace std;
int main()
{
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    for (int i = 0; i <= 6; i++)
    {
        for (int j = 0; j <=5; j++)
        {

            if ((array[j]) > (array[j + 1]))
            {
                int temp;
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 6; i++)
    {
        cout << array[i] << endl;
    }
}