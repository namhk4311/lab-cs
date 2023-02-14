#include <iostream>
#include <cstring>
//Implement void process(const char str[], char outstr[]) function which standardizes English name. The standardized name has the following features:
//1. The first character of each word must be uppercase. The remaining characters of each word must be lowercase.
//2. Only contains characters in English alphabet.
//3. There are no consecutive space characters and there is no space character at the beginning/end of the name
using namespace std;
bool flag = false;
void process1(const char *name, char *outstr) {
    int t = 0;
    for (int i = 0; i < strlen(name); i++)
    {
        if (name[i] == ' ' && name[i+1] != ' ' && flag == true)
        {
            {outstr[t] = ' '; t++;}
        }
        else if (('a' <= name[i] && name[i] <= 'z') ||('A' <= name[i] && name[i] <= 'Z'))
        {
            outstr[t] = name[i]; t++;
            flag = true;
        }
    }
    outstr[t] = '\0';
    // for (int i = 0; i < strlen(outstr); i++)
    // {
    //     if ('a' <= outstr[0] && outstr[0] <= 'z') outstr[0] -= 32;
    //     if (outstr[i - 1] == ' ' && 'a' <= outstr[i] && outstr[i] <= 'z') outstr[i] -= 32; 
    //     if (outstr[i - 1] != ' ' && 'A' <= outstr[i] && outstr[i] <= 'Z') outstr[i] += 32;
    // }
    for (int i = 0; i < strlen(outstr); ++i)
    {
        if ((i == 0 || outstr[i - 1] == ' ') && ('a' <= outstr[i] && outstr[i] <= 'z')) 
            outstr[i] = outstr[i] - 'a' + 'A';

        if ((i != 0 && outstr[i - 1] != ' ') && ('A' <= outstr[i] && outstr[i] <= 'Z'))
            outstr[i] = outstr[i] - 'A' + 'a';
    }
}

void process2(const char str[], char outstr[]) // idea from god DVTD orz
{
    int tmpstrLength = 0, strLength = strlen(str), outstrLength = 0;
    char tmpstr[100];

    // Delete those character that is neither in abcABC or a spacebar
    for (int i = 0; i < strLength; ++i)
    {
        if (('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z') || (str[i] == ' '))
            tmpstr[tmpstrLength++] = str[i];
    }
    tmpstr[tmpstrLength] = '\0';

    // Delete excess spacebars
    bool flag = false;
    int i = 0;
    while (i < tmpstrLength)
    {
        while (tmpstr[i] == ' ') i++;
        if (flag && tmpstr[i - 1] == ' ') outstr[outstrLength++] = ' ';
        else flag = true;

        outstr[outstrLength++] = tmpstr[i++];
    }
    outstr[outstrLength] = '\0';

    // Uppercase and lowercase management
    for (int i = 0; i < outstrLength; ++i)
    {
        if ((i == 0 || outstr[i - 1] == ' ') && ('a' <= outstr[i] && outstr[i] <= 'z')) 
            outstr[i] = outstr[i] - 'a' + 'A';

        if ((i != 0 && outstr[i - 1] != ' ') && ('A' <= outstr[i] && outstr[i] <= 'Z'))
            outstr[i] = outstr[i] - 'A' + 'a';
    }
}

int main()
{
    const int MAX_SIZE = 100;
    char str[] = " doan VAN *(()hau @!#$" ;
    char outstr[MAX_SIZE];
    process2(str, outstr);
    cout << outstr;
}
