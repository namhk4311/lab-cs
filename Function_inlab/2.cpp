#include <bits/stdc++.h>
using namespace std;

// A natural number n is special if and only if n is a prime number and the sum of all the digits of n is also a prime number. Write a function that determines if a natural number is a special or not.

bool isSpecialNumber(int n) {
    bool flag = true; int cnt = 1; int a[100], check = 0;
    for (int i = 2; i <= n/2 + 1; i++)
    {
        if (n % i == 0) {
            flag = false;
            break;
        }
    }
    check += flag;
    int sizenumber = log10(n) + 1, p = 10, k = 0, t = 0; 
    while (cnt <= sizenumber)
    {
        for (int i = 0; i < 10; i++)
        {
            if ((n - (i*(p/10) + k)) % p == 0 && n - (i*(p/10) + k) >= 0) 
            {
                a[t++] = i;
                k += i*(p/10);
                p *= 10;
            } 
        }
        cnt++;
    }
    int sum = 0;
    for (int i = 0; i <= t; i++) sum += a[i];
    for (int i = 2; i <= sum/2 + 1; i++)
    {
        if (sum % i == 0) {
            flag = false;
            break;
        }
    }
    check += flag;
    if (n == 0 || n == 1) check = 0;
    else if (n == 2 || sum == 2) check = 2;
    if (check != 2) return false;
    return true;
}

int main()
{
    int n;
    cin >> n;
    cout << isSpecialNumber(n);
    return 0;
}