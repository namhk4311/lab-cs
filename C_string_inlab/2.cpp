#include <iostream>
#include <cstring>
using namespace std;
int cnt[100];
void printFirstRepeatedWord(char str[]) {
    // char *a[1000]; int t = 0, j = 0, i = 0; char tmp[100];
    // while(i < strlen(str))
    // {
    //     while (str[i] != ' ' && i < strlen(str))
    //     {
    //         tmp[j] = str[i]; j++;
    //         i++;
    //     }
    //     tmp[j] = '\0';
    //     j = 0;
    // }
    int i = 0, t = 0; char *word[100];
    while (i < strlen(str))
    {
        char *tmp = new char[100];
        int k = 0;
        while (str[i] != ' ' && i < strlen(str))
        {
            tmp[k] = str[i];
            k++; i++;
        }
        tmp[k] = '\0';
        word[t] = tmp;
        t++;
        i++;
    }


    for (int i = 0; i < t; i++)
    {
        for (int s = 0; s < t; s++)
        {
            if (!strcmp(word[s], word[i]) && s != i)
            {
                cout << word[i];
                return;
            } 
        }
    }
    cout << "No Repetition";
}    

int main()
{
    char str[] = "car taxi bike nam nam";
    printFirstRepeatedWord(str);
    return 0;
}