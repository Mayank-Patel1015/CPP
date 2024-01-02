// Learning C++
// Exercise 02_07
// Arrays, by Eduardo Corpeño and Mayank Patel

#include <iostream>

using namespace std;

int age[4];

int main()
{
    for (int i = 0; i < 4; i++)
    {
        age[i] = 23 + 2 * i;
    }
    for (int i = 0; i < 4; i++)
    {
        cout << age[i] << endl;
    }
    return (0);
}
