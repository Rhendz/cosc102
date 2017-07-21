#include <iostream>
using namespace std;

int out_of_order(double s[], int size);
// Determines if any elements from left to right
// in the array are out of order. If an element
// is out of order, the index of that element is
// returned; otherwise, the function returns -1.

int main() {
	double a[10] = {1.2, 2.1, 3.3, 2.5, 4.5, 7.9, 5.4, 8.7, 9.9, 1.0};
	int x = out_of_order(a, 10);
	cout << "The first element out of order is " << x << endl;
	return 0;
}

int out_of_order(double s[], int size) {
	for(int i = 0; i < size - 1; i++) {
		if(s[i] > s[i+1]) return i+1;
	}
	return -1;
}