#include <iostream>
using namespace std;

// #define m 4
// #define n 4

void row_sum(int arr[][],m,n)
{

    int i, j, sum = 0;

    cout << "\nFinding Sum of each row:\n\n";

    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {

            sum = sum + arr[i][j];
        }

        cout
            << "Sum of the row "
            << i << " = " << sum
            << endl;

        sum = 0;
    }
}

void column_sum(int arr[m][n])
{

    int i, j, sum = 0;

    cout << "\nFinding Sum of each column:\n\n";

    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {

            sum = sum + arr[j][i];
        }

        cout
            << "Sum of the column "
            << i << " = " << sum
            << endl;

        sum = 0;
    }
}

int main()
{
    cout<<"Enter the number of rows"<<endl;
    int m;
    cin>>m;
    cout<<"Enter the number of column"<<endl;
    int n;
    cin>>n;
    int i, j;
    int arr[m][n];

    int x = 1;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++){
            cout << "Enter the element of " << i + 1 << "row and " << j + 1 << " column" << endl;
    cin >> arr[i][j];}
    row_sum(arr,m,n);

    column_sum(arr);

    return 0;
}