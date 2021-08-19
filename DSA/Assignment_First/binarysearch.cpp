#include <bits/stdc++.h>
using namespace std;

int binarySearch(int array[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (array[mid] == x)
            return mid;

        if (array[mid] > x)
            return binarySearch(array, l, mid - 1, x);

        return binarySearch(array, mid + 1, r, x);
    }

    return -1;
}

int main(void)
{
    int array[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(array) / sizeof(array[0]);
    int search = binarySearch(array, 0, n - 1, x);
    if (search == -1)
    {
        cout << "Element is not present in array";
    }
    else
        cout << "Element is present at index " << search;
    return 0;
}
