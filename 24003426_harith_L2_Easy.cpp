/*
id: 24003426
name: harith
group: g2
lab: L2 (Easy) - Efficiently compute sums of diagonals of a matrix
*/

#include <iostream>
using namespace std;

void computeDiagonalSums(int matrix[][100], int n)
{
    int principalDiagonalSum = 0;
    int secondaryDiagonalSum = 0;

    for (int i = 0; i < n; i++)
    {
        principalDiagonalSum += matrix[i][i];
        secondaryDiagonalSum += matrix[i][n - i - 1];
    }

    cout << "Output:\n";
    cout << "Primary Diagonal Sum: " << principalDiagonalSum << endl;
    cout << "Secondary Diagonal Sum: " << secondaryDiagonalSum << endl;
}

int main()
{
    int n;

    cout << "Input: ";
    cin >> n;

    int matrix[n][n];

    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    computeDiagonalSums(matrix, n);

    return 0;
}