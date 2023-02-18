#include <iostream>
#include <cstring>
using namespace std;

//A string is a palindrome if it reads the same forward and backward. For example: "eye", "noon", "abcba", ...
//Write a function to check if a given string is a palindrome

bool isPalindrome(const char* str) {
    char *invstr = new char[100]; int k = 0;
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        invstr[k++] = str[i];
    }
    invstr[k] = '\0';
    for (int i = 0; i < strlen(invstr); i++)
    {
        if (invstr[i] != str[i]) return false;
    }
    return true;
}

int main()
{
    const char* str = "abba";
    cout << isPalindrome(str);
    return 0;
}