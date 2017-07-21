/*------------------------------------------------
Author: Ankush Patel
Program: sumevens.cpp
Description: Sums the values of even integers in
a for-based loop. The sentinal value (representing
the end of the sum) is 2.
------------------------------------------------*/

#include <iostream>
using namespace std;

int main() {
	int sum(0), n(0);

	while(n!=2) {
		cout << "Please enter an even integer to sum: ";
		cin >> n;
		cout << endl;
		if(n%2==0) {
			sum+=n;
		} else {
			cout << "That integer was odd!" << endl;
		}
	}

	cout << "The sum is " << sum << endl;
	return 0;
}