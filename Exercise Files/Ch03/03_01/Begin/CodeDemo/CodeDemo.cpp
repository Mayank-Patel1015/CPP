// Learning C++
// Exercise 03_01
// Structures, by Eduardo Corpeño and Mayank Patel

#include <iostream>
#include <string>

using namespace std;

enum cow_purpose
{
    dairy,
    meat,
    hide,
    pet
};

struct cow
{
    string name;
    int age;
    unsigned char purpose;
};

int main()
{
    cow my_cow;
    my_cow.age = 2;
    my_cow.name = "Bob";
    my_cow.purpose = pet;

    cout << my_cow.age << my_cow.name << (int)my_cow.purpose;

    return (0);
}
