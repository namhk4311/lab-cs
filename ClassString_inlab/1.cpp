#include <iostream>
#include <string>
using namespace std;

void replaceString(string s, string s1, string s2){
    int max = -1;
    for (int i = 0; i < s.length(); i++)
    {
        int j = 0; string tmp;
        while (j < s1.length()) //cho chuoi cua s vao chuoi tmp voi do dai bang cua chuoi s1
        {
            tmp += s[i+j];
            j++;
        }
        if (tmp == s1) //chuoi tmp trung voi chuoi s1
        {
            if (max < i) max = i; //tim chi so index lon nhat (vi tri cuoi cung)
        }
    }
    if(max == -1) cout << s << endl; // khong kiem dc s1 trong s thi giu nguyen
    else {
        s.replace(max, s1.length(), s2);
        cout << s << endl;
    }
}

int main()
{
    string s = "Truong Dai Hoc Bach Khoa, Sai Gon";
    string s1 = "ai";
    string s2 = "ong";
    replaceString(s, s1, s2);
    return 0;
}