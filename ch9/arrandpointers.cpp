// Program to demonstrate that an array variable is a kind of pointer variable.
#include <iostream>
using namespace std;

// Used to assign a name to a type definition and then
// can be used to declare variables.
typedef int* IntPtr;

int main() {
	IntPtr p;
	int a[10];

	for(int i = 0; i < 10; i++)
		a[i] = i;

	p = a;

	for(int i = 0; i < 10; i++)
		cout << p[i] << " ";
	cout << endl;

	for(int i = 0; i < 10; i++)
		p[i] += 1;

	for(int i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}
