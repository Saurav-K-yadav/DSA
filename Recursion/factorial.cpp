// Factorial of N numbers
// e.g. input 3-->3*2*1=6

#include <iostream>
using namespace std;
int factorial(int num,int fact){
    if(num<1)
        return fact;
    return factorial(num - 1, fact * num);
};

int main()
{

    int num;
    cout << "Enter a number" << endl;
    cin >> num;
    int fac = 1;
    fac=factorial(num,fac);
    cout << "The factorial of number is " << fac;
    return 0;
}