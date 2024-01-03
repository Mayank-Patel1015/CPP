// Learning C++
// Challenge 02_10
// Calculate an Average, by Eduardo Corpeño and Mayank Patel

#include <iostream>

using namespace std;

int main()
{
	int nums[5] = {1, 23, 32, 24, 337};
	float result = 0.0f;
	// alternatively you can divide by sizeof(nums[0]) if you do not know the type of the array
	for (int i = 0; i < sizeof(nums) / sizeof(int); i++)
	{
		result += nums[i];
		cout << result << endl;
	}
	result = result / (sizeof(nums) / sizeof(int));
	cout << "The average is " << result << endl;
	return (0);
}
