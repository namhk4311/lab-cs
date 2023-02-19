#include <iostream>
#include <cstring>
using namespace std;

void encrypt(char* text, int shift) {
    shift = shift % 26;
    for (int i = 0; i < strlen(text); i++)
    {
        int ntext = (int)text[i] + shift;
        if ('a' <= text[i] && text[i] <= 'z' && ntext > (int)'z') ntext = ntext - 26;
        else if ('A' <= text[i] && text[i] <= 'Z' && ntext > (int)'Z') ntext = ntext - 26;
        text[i] = (char)ntext;
    }
}

void decrypt(char* text, int shift) {
     shift = shift % 26;
    for (int i = 0; i < strlen(text); ++i)
    {
        text[i] = text[i] - shift;
        if ('a' <= text[i] + shift && text[i] + shift <= 'z' && text[i] < 'a') text[i] = text[i] + ('z' - 'a' + 1);
        else if ('A' <= text[i] + shift && text[i] + shift <= 'Z' && text[i] < 'A') text[i] = text[i] + ('Z' - 'A' + 1);
    }   
}

int main()
{
    int n, shift; 
    cin >> n >> shift;
    char* text = new char[n+1];
    for(int i = 0; i < n; i++) cin >> text[i];
    text[n] = 0;

    encrypt(text, shift);
    cout << text << '\n';
    decrypt(text, shift);
    cout << text;

    delete[] text;
    return 0;
}