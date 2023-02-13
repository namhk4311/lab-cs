#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long int uli;

int calc(char str[]) {
    int k = 1, ans = 0;
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        if(str[i] == '1')
        {
            ans += k;
        }
        k *= 2;
    }
    return ans;
}

void cutString(string s, int index)
{
    char cut[100]; int cnt = 0;
    for (int i = index; i < s.length(); i++)
    {
        cut[cnt++] = s[i];
    }
    cut[cnt] = '\0';
    cout << cut;
}

void findAllIndex(string s1, string s2)
{
    int cnt = 0;
    bool flag;
    for (int i = 0; i < s1.length() - s2.length(); i++)
    {
        flag = true;
        for (int j = 0; j < s2.length(); j++)
        {
            if (s1[i + j] != s2[j])
            {
                flag = false;
            }
        }

        if (flag)
        {
            cout << i << ' '; cnt++;
        }
    }
    if (!cnt) cout << -1;
}

void findAllIndex2(string s1, string s2)
{
    int cnt = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        int j = 0; string str;
        while (j < s2.length())
        {
            str += s1[i+j];
            j++;
        }
        if (str == s2)
        {
            cout << i << " ";
            cnt++;
        }
    }
    if (!cnt) cout << -1 << endl;
}

int findMaxColumn(int arr[][1000], int row, int col) 
{    
    int j = 0, mIndex = 0, max = -1000000; 
    while (j < col)
    {
        int sum = 0;
        for(int i = 0; i < row; i++)
        {
            sum += arr[i][j];   
        }
        if (max < sum) {
            max = sum;
            if (mIndex < j) mIndex = j;
        }
        ++j;
    }
    return mIndex;
}

int diagonalProduct(int arr[][1000], int row, int col) {
    int product = 1;
    for (int i = 0; i < row; i++)
    {
        product *= arr[i][i];
    }
    return product;
}

bool isSymmetric(int arr[][1000], int row, int col) {
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] != arr[j][i])
            return false;
        }
    }    
    return true;
}

int diagonalDiff(int arr[][1000], int row, int col, int x, int y) {
    int diag1 = 0, diag2 = 0;
    for (int k = -min(x, y); k <= min(row - x, col - y) - 1; ++k) diag1 += arr[x + k][y + k];
    for (int k = -min(row - x - 1, y); k <= min(x, col - y - 1); ++k) diag2 += arr[x - k][y + k];
    return (abs(diag1 - diag2));
}

void solve()
{

}


int main()
{
    int test = 1; 
    while (test--) solve();
    return 0;
}