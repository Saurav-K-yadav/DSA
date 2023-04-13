// An example of multiple recursin calls
// Fibonacci series -->  0,1,2,3,5,8...
// f(n)=f(n-1)+f(n-2)

// Display the nth fibonacci series number
#include <iostream>
using namespace std;

int fibonacci(int num)
{

    if (num <= 1) // as there is f(n-1)== 1 and f(n-2)==0
    {
        return num;
    }
    return fibonacci(num - 1) + fibonacci(num - 2);
}
int main()
{
    int pos;
    cin >> pos;
    cout << "The nth positional fibonacci number is " << fibonacci(pos);
    return 0;
}