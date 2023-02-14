#include <bits/stdc++.h>
using namespace std;

int findMax(int *vals, int numEls) {
    int max = -INT_MAX;
    for (int i = 0; i < numEls; i++)
    {
        if (vals[i] > max) max = vals[i];
    }
    return max;
}

int main()
{
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    findMax(a,n);
    return 0;
}