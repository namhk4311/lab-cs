#include <iostream> //idea from god DVTD
using namespace std;

// Given a positive decimal number as input, we need to implement function
// long int decimalToBinary(int decimal_number){}
// to convert the given positive decimal number into equivalent binary number.
// Please note that you can't using key work for, while, goto (even in variable names, comment).
// For this exercise, we have #include <iostream> and using namespace std;


long int decimalToBinary(int decimal_number)
{
	if (decimal_number == 0) return 0;
    return (decimal_number % 2) + decimalToBinary(decimal_number / 2) * 10;
}

int main()
{
    cout << decimalToBinary(20);
}