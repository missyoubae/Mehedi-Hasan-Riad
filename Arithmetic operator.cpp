#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int num1, num2, result;
    cout << "Enter num1 : ";
    cin >> num1;

    cout << "Enter num2 : ";
    cin >> num2;

    result = num1 + num2;
    cout << "sum is : " << result << endl;
    // sum means Addition

    result = num1 - num2;
    cout << "Subtraction is : " << result << endl;

    result = num1 * num2;
    cout << "Multiplication is : " << result << endl;

    result = num1 / num2;
    cout << "Division is : " << result <<endl;


    result = num1 % num2;
    cout << "Remainder is : " << result <<endl;


    getch();
}
