// Learning C++
// Exercise 02_05
// Preprocessor directives, by Eduardo Corpeño and Mayank Patel

#include <iostream>
#include <string>
#include <cstdint>

#define CAP 10000
// #define DEBUG

using namespace std;

int main()
{
    int32_t large = CAP;
    uint8_t small = 37;
#ifdef DEBUG
    cout << "adding" << endl;
#endif
    large += small;
    cout << "The large integer is " << large << endl;
    return (0);
}
