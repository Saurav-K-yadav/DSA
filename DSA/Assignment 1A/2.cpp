#include <iostream>
using namespace std;
class sparseMatrix
{
    int row, col;
    int n = 0;
    int **triplet;

public:
    sparseMatrix();
    sparseMatrix(int r, int c)
    {
        row = r;
        col = c;
        triplet = new int *[(row * col)];
        for (int i = 0; i < (row * col); i++)
        {
            triplet[i] = new int[3];
        }
    }
    void insert(int r, int c, int ele)
    {
       
        triplet[n][0] = r;
        triplet[n][1] = c;
        triplet[n][2] = ele;
        ++n;
    }
    void input()
    {
        cout << "Enter the sparse matrix :\n";
        cin >> row >> col;
        int arr[row][col];
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> arr[i][j];
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (arr[i][j] != 0)
                {
                    insert(i, j, arr[i][j]);
                }
            }
        }
    }
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            cout << triplet[i][0] << " " << triplet[i][1] << " " << triplet[i][2] << "\n";
        }
        cout << "\n";
    }
    sparseMatrix operator+(sparseMatrix &second)
    {
        sparseMatrix ans(row, col);
        int i = 0, j = 0;
        while (i < n || j < second.n)
        {
            if (triplet[i][0] == second.triplet[j][0] && triplet[i][1] == second.triplet[j][1])
            {
                ans.insert(triplet[i][0], triplet[i][1], (triplet[i][2] + second.triplet[j][2]));
                ++i;
                ++j;
            }
            else if (triplet[i][0] == second.triplet[j][0])
            {
                if (triplet[i][1] < second.triplet[j][1])
                {
                    ans.insert(triplet[i][0], triplet[i][1], triplet[i][2]);
                    ++i;
                }
                else
                {
                    ans.insert(second.triplet[j][0], second.triplet[j][1], second.triplet[j][2]);
                    ++j;
                }
            }
            else if (triplet[i][0] < second.triplet[j][0])
            {
                ans.insert(triplet[i][0], triplet[i][1], triplet[i][2]);
                ++i;
            }
            else
            {
                ans.insert(second.triplet[j][0], second.triplet[j][1], second.triplet[j][2]);
                ++j;
            }
        }
        return ans;
    }
    void sort()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (triplet[i][0] > triplet[j][0])
                {
                    swap(triplet[i][0], triplet[j][0]);
                    swap(triplet[i][1], triplet[j][1]);
                    swap(triplet[i][2], triplet[j][2]);
                }
                else if ((triplet[i][0] == triplet[j][0]) && (triplet[i][1] > triplet[j][1]))
                {
                    swap(triplet[i][0], triplet[j][0]);
                    swap(triplet[i][1], triplet[j][1]);
                    swap(triplet[i][2], triplet[j][2]);
                }
            }
        }
    }
    void transpose()
    {
        for (int i = 0; i < n; i++)
        {
            swap(triplet[i][0], triplet[i][1]);
        }
        sort();
    }
    sparseMatrix operator*(sparseMatrix second)
    {
        //multiplicaiton
        sparseMatrix ans(row, second.col);
        second.transpose();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < second.n; j++)
            {
                if (triplet[i][1] == second.triplet[j][1])
                {
                    ans.insert(triplet[i][0], second.triplet[j][0], (triplet[i][2] * second.triplet[j][2]));
                }
            }
        }
        //add duplicates
        for (int i = 0; i < ans.n; i++)
        {
            for (int j = i + 1; j < ans.n; j++)
            {
                if ((ans.triplet[i][0] == ans.triplet[j][0]) && (ans.triplet[i][1] == ans.triplet[j][1]))
                {
                    
                    ans.triplet[i][2] += ans.triplet[j][2];
                    ans.triplet[j][0] = -1;
                }
            }
        }
        //delete duplicates
        for (int i = 0; i < ans.n; i++)
        {
            if (ans.triplet[i][0] == -1)
            {
                for (int j = i + 1; j < ans.n; j++)
                {
                    ans.triplet[j - 1][0] = ans.triplet[j][0];
                    ans.triplet[j - 1][1] = ans.triplet[j][1];
                    ans.triplet[j - 1][2] = ans.triplet[j][2];
                }
                --ans.n;
            }
        }
        ans.sort();
        second.transpose();
        return ans;
    }
};

int main()
{
    sparseMatrix a(4, 4);
    sparseMatrix b(4, 4);
    // a.input();
    // b.input();
    cout<<"MAtrix 1 :\n";
    a.insert(1, 2, 10);
    a.insert(1, 3, 4);
    a.insert(1, 4, 2);
    a.insert(3, 3, 3);
    a.insert(4, 1, 4);
    a.insert(4, 2, 2);
    a.display();

    cout<<"MAtrix 2 :\n";
    b.insert(1, 3, 8);
    b.insert(2, 4, 3);
    b.insert(3, 2, 2);
    b.insert(3, 3, 9);
    b.insert(4, 1, 2);
    b.insert(4, 2, 7);
    b.display();
    
    cout<<"Sum of matrix 1 and 2 :\n";
    sparseMatrix c = a+b;
    c.display();

    cout<<"Transpose of sum matrix : \n";
    c.transpose();
    c.display();

    cout<<"Multiplication of matrix 1 and 2 : \n";
    sparseMatrix mul = a * b;
    mul.display();
    return 0;
}