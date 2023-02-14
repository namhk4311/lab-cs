#include <bits/stdc++.h>
using namespace std;
    
int factorial(int N)
{
    int ans = 1;
    for (int i = 1; i <= N; i++)
    {
        ans *= i;
    }
    return ans;
}

int main()
{
    int N;
    cin >> N;
    long result;
    // call function calculateFactorial in here and assign value to the variable result
    result = factorial(N);
    cout << result << endl;
    return 0;
    return 0;
}