#include <iostream>
#include <string>
using namespace std;

//Write a program that reads into a string s, finds all substrings in s whose substring has only 1 character (for example: aaaa, bbbb, cc, ...) and returns the length of the longest substring.


int main()
{
    string s; cin >> s;
    int cnt = 1, max = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == s[i+1] && i + 1 != s.length()) 
        {
            ++cnt;
            if (max < cnt) max = cnt; 
        }
        else cnt = 1;
       
    }
    cout << max;
    return 0;
}