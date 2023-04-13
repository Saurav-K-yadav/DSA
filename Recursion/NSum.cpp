// Sum of first N numbers
#include <iostream>
using namespace std;

void paramiterized(int num, int sum)
// Does not return the final output
{
    if (num < 1)
    {
        printf("Sum is : %d", sum);
        return;
    }
    return paramiterized(--num, sum + num);
}

int functional(int num, int sum)
{
    // Returns the final output to the caller function

    if (num < 1)
    {
        return sum;
    }
    return functional(num - 1, sum + num);
}

int main()
{
    int num;
    cout << "Enter a number" << endl;
    cin >> num;
    paramiterized(num, 0);
    int sum = 0;
    sum = functional(num, 0);
    printf("The sum is %d ", sum);
    return 0;
}