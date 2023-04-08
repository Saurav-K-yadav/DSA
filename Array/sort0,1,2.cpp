#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int main()
{
    int arr[] = {0, 1, 2, 0, 2, 1, 0, 2, 1, 1, 0, 1, 2, 0, 1, 2};
    int start = 0;
    int mid = 0;
    int last = sizeof(arr) / sizeof(arr[1]) - 1;
    while (last >= mid)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[start]);
            start++;
            mid++;
            continue;
        }
        if (arr[mid] == 1)
        {
            mid++;
            continue;
        }
        if (arr[mid] == 2)
        {
            swap(arr[mid], arr[last]);
            last--;
            continue;
        }
    }

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << arr[i];
    }

    return 0;
}