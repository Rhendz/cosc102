#include <iostream>
using namespace std;

int main() {
	v1 = 0;
	// Assigns the memory location of v1 to p1.
	// Now, p1 points to the memory location of v1.
	p1 = &v1;
	// Dereferences the parameter, so now the actual
	// value of v1 can be manipulated.
	*p1 = 42;
	cout << v1 << endl; // Prints out the value of v1.
	cout << *p1 << endl; // Prints out the value of v1,
	// by derefencing the pointer that points to the value of v1.
	return 0;
}
