#include <bits/stdc++.h>
using namespace std;

//Write a function void uppercase(string output) to read the string S from the keyboard, then convert all characters in string S to uppercase characters and output the result to the output file.
//Note: change only lowercase letters, other characters will not change.

void uppercase(string output)  {
    string S;
    ofstream newofile;
    newofile.open(output);
        cin >> S;
        for (int i = 0; i < S.length(); i++)
        {
            if ('a' <= S[i] && S[i] <= 'z') S[i] = S[i] - 'a' + 'A';
        }
    newofile << S;
    newofile.close();
}

int main()
{
    uppercase("output.txt");
    return 0;
}