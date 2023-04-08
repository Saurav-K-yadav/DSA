#include <iostream>
#include<map>
// Given an unsorted array of size n. Array elements are in the range of 1 to n. One number from set {1, 2, …n} is missing and one number occurs twice in the array. Find these two numbers.

using namespace std;
int main()
{
    int arr[] = {3, 1,4,5, 3};
    map<int,int> count;
    int min = INT32_MAX;
    int max = INT32_MIN;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
        
    }
    cout << max << min;
    return 0;
}