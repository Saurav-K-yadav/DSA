// Printing subsequences whose sum is k
// For every recursive call check if the sum is call , if more than k
// return else if equal then print
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// void SubsequenceSum(vector<int> &arr, vector<int> &sub, int n, int sum)
// {
//     if (n == 5)
//     {
//         if (sum == 0)
//         {
//             {
//                 for (auto itr = sub.begin(); itr < sub.end(); itr++)
//                 {
//                     cout << *itr << "  ";
//                 }
//                 cout << endl;
//             }
//         }
//                 return;
//     }
//     sub.push_back(arr[n]);
//     sum = sum - arr[n];
//     SubsequenceSum(arr, sub, n + 1, sum);
//     sub.pop_back();
//     sum = sum + arr[n];
//     SubsequenceSum(arr, sub, n + 1, sum);
// }

// IF the question asks to print ONLY ONE subsequence
bool SubsequenceSum(vector<int> &arr, vector<int> &sub, int n, int sum)
{
    if (n == 5)
    {
        if (sum == 0)
        {
            {
                for (auto itr = sub.begin(); itr < sub.end(); itr++)
                {
                    cout << *itr << "  ";
                }
                cout << endl;
            }
            return true;
        }
        return false;
    }
    sub.push_back(arr[n]);
    sum = sum - arr[n];
    if (SubsequenceSum(arr, sub, n + 1, sum) == true)
        return true;
    sub.pop_back();
    sum = sum + arr[n];
    if (SubsequenceSum(arr, sub, n + 1, sum) == true)
        return true;
    return false;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int sum = 5;
    int n = 0;
    vector<int> sub = {};
    SubsequenceSum(arr, sub, n, sum);

    return 0;
}