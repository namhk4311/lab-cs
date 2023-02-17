#include <iostream>
#include <fstream>
using namespace std;

//Write a function void threeChars(string fileName) that reads in rows from a txt file, each row containing a string of 3 characters. Determines if 3 characters per row are in correct alphabetical order (ASCII), if true output "true", otherwise "false". The program will loop until 3 characters read in is "***".

void threeChars(string fileName)   {
    ifstream fff;
    fff.open(fileName);
        string S;
        while (fff >> S){
            if(S == "***") break;
            if (S[0] <= S[1] && S[1] <= S[2]) {cout << "true" << endl;}
            else cout << "false" << endl;
        }
    fff.close();
}

int main()
{
    threeChars("output2.txt");
    return 0;
}