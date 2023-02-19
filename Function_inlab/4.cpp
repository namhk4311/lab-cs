#include <iostream>
using namespace std;

// Write a function that determines if the elements in the given array is unique

bool checkElementsUniqueness(int* arr, int n) {
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (j < n)
        {
            if (arr[i] == arr[j] && i != j) return false;
            j++;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << checkElementsUniqueness(arr, n);
    delete[] arr;
    return 0;
}