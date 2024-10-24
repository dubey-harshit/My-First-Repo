// FIND FACTORIAL OF A NUMBER

#include <iostream>
using namespace std;

int fact(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n * fact(n - 1);
}

int main()
{

    int user;   
    cout << "Enter a number : ";
    cin >> user;

    cout << "The Factorial of " << user << " is : " << fact(user);
}