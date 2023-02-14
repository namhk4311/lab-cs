#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long int uli;

void calSum(string fileName)   {
    ifstream ttt;
    ttt.open(fileName);
        int n, sum = 0;
        while(ttt >> n)
        {
            sum += n;
        }
    ofstream tt;
    tt.open(fileName);
        cout << sum;
    tt.close();
    ttt.close();    
}

void solve()
{
    calSum("kkk.txt");
}

int main()
{
    int test = 1;
    while (test--) solve();
    return 0;
}