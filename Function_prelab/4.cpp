#include <bits/stdc++.h>
using namespace std;

bool completeNum(int N)
{
    int sum = 0;
    for (int i = 1; i < N; i++)
    {
        if (N % i == 0) sum += i;
    }
    if (sum == N) return true;
    return false;
}

int main()
{
    int n; cin >> n;
    cout << completeNum(n);
    return 0;
}