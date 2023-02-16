#include <iostream>
#include <string>
using namespace std;
//Implement deleteWord(string s, string s1) function with function to print string s after deleting all strings s1 contained in s.

void deleteWord(string s, string s1){
    string delWord; int k = 0; int flag1 = -50; bool flag2 = false;
    for (int i = 0; i < s.length(); i++)
        {
            int j = 0; string tmp;
            while (j < s1.length()) //cho chuoi cua s vao chuoi tmp voi do dai bang cua chuoi s1
            {
                tmp += s[i+j];
                j++;
            }
            if (tmp == s1)
            { 
                flag1 = i; //tmp = s1, flag được đánh dâu, bỏ qua index cách i đc đánh dấu (flag) 2 đơn vị
                flag2 = true; 
            }
            else {
                int t = 0;
                if (i > flag1 && i < flag1 + s1.length() && flag2 == true) continue; //flag2 kích hoạt khi xuất hiện tmp đầu tiên
                else delWord += s[i];
            }
        }
    cout << delWord << endl;
}
// cách 1

int main()
{
    string s = "Truong Dai Hoc Bach Khoa, Sai Gon";
    string s1 = "ach ";
    deleteWord(s, s1);
    return 0;
}