// To reverse an array using the recursive call
// Instead of passign two arhguments i and j an to swap them,a argument i is passed and
// another position is found using n-i-1
#include <bits/stdc++.h>
using namespace std;

void reverse(int *a, int n, int i = 0)
{

    if (floor(i < (n / 2)))
    {
        swap(a[i], a[n - i - 1]);
        reverse(a, n, i + 1);
    }
    return;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    reverse(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "    ";
    }

    return 0;
}