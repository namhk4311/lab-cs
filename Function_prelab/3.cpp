#include <bits/stdc++.h>
using namespace std;

void sum2(int * array, int numEls, int &result)
{
    for (int i = 0; i < numEls; i++)
    {
        result += array[i];
    }
}

int main()
{
    int n, op = 0; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sum2(a,n,op);
    cout << op;
    return 0;
}