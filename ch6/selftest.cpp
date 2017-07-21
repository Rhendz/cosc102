#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cout << "*" << setw(5) << 123;
	cout.setf(ios::left);
	cout << "*" << setw(5) << 123;
	cout.setf(ios::right);
	cout << "*" << setw(5) << 123 << "*" << endl;
	return 0;
}