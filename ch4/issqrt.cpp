#include <iostream>
#include <cmath>
using namespace std;

bool is_root_of(int sqrtNum, int num);

int main() {
	int num1, num2;

	cout << "Please enter two numbers: ";
	cin >> num1 >> num2;
	cout << endl;

	if(is_root_of(num1, num2)) 
		cout << num1 << " is the square root of " << num2 << endl;
	else 
		cout << num1 << " is not the square root of " << num2 << endl;
	return 0;
}

bool is_root_of(int sqrtNum, int num) {
	return sqrt(sqrtNum)==num;
}