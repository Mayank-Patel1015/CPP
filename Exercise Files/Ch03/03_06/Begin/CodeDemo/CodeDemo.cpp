// Learning C++
// Exercise 03_05
// Vectors, by Eduardo Corpeño and Mayank Patel

#include <iostream>
#include <string>
#include "cow.h"

using namespace std;

vector<int> primes;

int main()
{
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);
    primes.push_back(7);
    primes.push_back(11);
    cout << "The vector has " << primes.size() << " elements." << endl;
    cout << "The element at index 2 is " << primes[2] << endl;
    primes[2] = 13;
    cout << "The element at index 2 is " << primes[2] << endl;
    cout << endl;

    return (0);
}
