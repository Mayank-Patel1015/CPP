// Learning C++
// Exercise 02_08
// Strings, by Eduardo Corpeño and Mayank Patel

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int LENGTH1 = 25;
char array_str1[LENGTH1] = "Hello, World! ";
char array_str2[] = "Hello, Bob!";

string std_str1 = "Hello, std! ";
string std_str2 = "What's popping? ";

int main()
{
    // mutates array_str1
    strcat(array_str1, array_str2);
    cout << array_str1 << endl;
    // doesn't mutate
    cout << std_str1 + std_str2 << endl;
    return (0);
}
