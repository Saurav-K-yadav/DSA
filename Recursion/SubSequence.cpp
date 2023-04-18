// Print all the subsequence
// subsequence is contiguous as well as non-contiguous
// But the order should be maintained

// The decision is take or leave a element on sub-array
// The function is rece=ursively called at first by taking an element next by leaving it out and going to next step
// Time Complexity --> O(n*2^n) as each recursive stephas 2 child and for loop takes O(N) time
// Space complexity -->O(N) at any time maximum number of recursive calls 
// waiting in stack cannot be more than N.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void subsequence(vector<int> &arr, vector<int> &sub, int n = 0)
{
    if (n == 3)
    {
        if (sub.empty())
        {
            cout << "{ }" << endl;
        }

        for (auto i = sub.begin(); i < sub.end(); i++)
        {
            cout << *i << "  ";
        }
        cout << endl;
        return;
    }
    sub.push_back(arr[n]);
    subsequence(arr, sub, n + 1);
    sub.pop_back();
    subsequence(arr, sub, n + 1);
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> sub = {};
    subsequence(arr, sub);
    return 0;
}