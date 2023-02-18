#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Write a function void process(string fileName) that reads a txt file, the first line consists of 2 numbers N and M separated by a space.
//N lines follow, each containing M real numbers separated by 1 space.
//Print the maximum value of each line and the maximum value of all numbers.
//Included libraries: iostream, fstream, string.

void process(string fileName)   {
    ifstream ip;
    ip.open(fileName);
        int N, M, k = 0; ip >> N >> M;
        double arr1[100][100], max1; 
        double arr2[100], max2; 
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                ip >> arr1[i][j];
            }
        }
        for (int i = 0; i < N; i++)
        {
            max1 = arr1[i][0];
            for (int j = 0; j < M; j++)
            {
                if (max1 < arr1[i][j]) max1 = arr1[i][j]; 
            }
            cout << max1 << " ";
            arr2[k++] = max1;
        }
        max2 = arr2[0];
        for (int i = 0; i < k; i++)
        {
            if (max2 < arr2[i]) max2 = arr2[i];
        }
        cout << max2 << endl;
    ip.close();
}

int main()
{
    process("output3.txt");
    return 0;
}