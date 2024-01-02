// Learning C++
// Exercise 02_09
// Type Casting, by Eduardo Corpeño

#include <iostream>
#include <cstdint>

using namespace std;

float flt = -7.44f;
int32_t sgn;
uint32_t unsgn;

int main()
{
    sgn = flt;
    unsgn = sgn;

    cout << "float: " << flt << endl;
    cout << "sign: " << sgn << endl;
    cout << "unsign: " << unsgn << endl;

    int f = 100;
    int c;
    int c2;
    // the int division returns 0
    c = (5 / 9) * (f - 32);
    // casting one of the numbers insures the calculation is done in float then truncated at the end
    c2 = ((float)5 / 9) * (f - 32);

    cout << "C: " << c << " C2: " << c2 << endl;

    return (0);
}
