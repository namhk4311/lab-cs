#include <iostream>
#include <vector>
#include <string>
using namespace std;
    
//Given a two-dimensional array whose each element is integer, its size is M x N.
//Implement the following function:
    //int primeColumns(int arr[][1000], int row, int col);
//Where arr, row and col are the given two-dimensional array, its number of rows and its number of columns. A column of the given array is called as HN2 if the sum of all elements on it is a prime number. Find the number of HN2 columns in the given array.
//Note: Libraries iostream, vector, and string have been imported, and namespace std has been used.

int primeColumns(int arr[][1000], int row, int col) {
    vector<int> num; int cnt = 0, t = 0;
    for (int i = 0; i < col; i++)
    {
        int sum = 0;
        for (int j = 0; j < row; j++)
        {
            sum += arr[j][i];
        }
        num.push_back(sum);
    }
    for (int i = 0; i <= num.size() - 1; i++)
    {
        int k = 2; int check = 0;
        if (num[i] == 2) cnt++;
        else if (num[i] == 0 || num[i] == -1) check++;
        else{
        while (k <= abs(num[i])/2 + 1)
        {
            if (num[i] % k == 0 || num[i] <= 0) 
            {
                check++;
            }
            ++k;
        }
        }
        if (!check) cnt++;
    }
    return cnt;
}

int main()
{
    int arr[][1000] = {{34,-15,11,-70,-23,24},{-39,-90,63,-45,-52,48},{-42,92,55,92,82,81}};
    cout << primeColumns(arr,3,6);
    return 0;
}

