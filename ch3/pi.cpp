/*------------------------------------------------
Author: Ankush Patel
Program: pi.cpp
Description: Approximates pi
------------------------------------------------*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n; // number of terms used in the approximation of pi
	double pi = 4;
	double approximationSum = 1;
	cout << "Please enter the number of terms to be used in the approximation of pi: ";
	cin >> n;
	cout << endl;

	for(int i=1; i < n; i++) approximationSum += (pow(-1, i)/(2*i + 1));

	pi*=approximationSum;

	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(10);
	cout << "The value of pi for " << n << " iterations is " << pi << endl;
	return 0;
}
