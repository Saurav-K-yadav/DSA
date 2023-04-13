// To reverse an string  is palindrome using the recursive call
#include <bits/stdc++.h>
using namespace std;
// Check if a[i]==a[n-i-1] till i<n/2
// if any don't print false
bool reverse(string &s, int n, int i = 0)
{
    if (i < n / 2)
    {
        if (s[i] == s[n - 1 - i])
        {
            return reverse(s, n, i + 1);
        }
        else
            return false;
    }
    return true;
}

int main()
{
    string b = "racecar";
    int n = b.length();
    int check = reverse(b, n);
    if (check)
    {
        cout << "It is palindrome";
    }
    else
    {
        cout << "It is not palindrome";
    }
    return 0;
}