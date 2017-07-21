#include <iostream>

// #define NDEBUG // Turns debug on/off
#include <cassert>

// assert is a useful tool for debugging
// logical errors.
using namespace std;

int main() {
	int x, y, z;

	cout << "Enter three numbers: ";
	cin >> x >> y >> z;
	cout << endl;

	assert(z==0);
	x*=(y/z);
	cout << "x*y/z is " << x << endl;
	return 0;
}