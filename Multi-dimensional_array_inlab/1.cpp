#include <bits/stdc++.h>
using namespace std;

//Given a two-dimensional array whose each element is integer, its size is M x N.
// Implement the following function:
// int ascendingRows(int arr[][1000], int row, int col);
// Where arr, row and col are the given two-dimensional array, its number of rows and its number of columns. A row of the given array is called as HN1 if on this row, each element's value is not higher than all elements after it. Find the number of HN1 rows of the given array.
// Note: Libraries iostream, and string have been imported, and namespace std has been used.


int ascendingRows(int arr[][1000], int row, int col) {
    int cntR = 0;
    for (int i = 0; i < row; i++)
    {
        int cntC = 0;
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] <= arr[i][j + 1] && j + 1 != col) cntC++;
            else break;
        }
        if (cntC == col - 1) ++cntR;
    }
    return cntR;
}

int main()
{
    int arr[][1000] = {{-28,-8,-60,18},{-100,44,-1,24},{-94,92,-70,75}};
cout << ascendingRows(arr,3,4);
    return 0;
}