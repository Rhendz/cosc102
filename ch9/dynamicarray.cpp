// Sorts a list of numbers entered at the keyboard.
#include <iostream>
#include <cstdlib>
#include <cstddef>
using namespace std;

typedef int* IntArrayPtr;

void fill_array(int a[], int size);
// Precondition: size is the size of the array a.
// Postcondition: a[0] through a[size - 1] have been
// filled with values read from the keyboard.

void sort(int a[], int size);
// Precondition: size is the size of the array a.
// The array elements a[0] through a[size - 1] have values.
// Postcondition: The values of a[0] through a[size - 1]
// have been rearranged so that a[0] <= a[1] ... <= a[size - 1].

int main() {
	cout << "This program sorts numbers from lowest to highest.\n";

	int array_size;
	cout << "How many numbers will be sorted? ";
	cin >> array_size;

	IntArrayPtr a;
	// The new operator creates a new dynamic variable
	// of the specified type. In this case, the
	// dynamic variable reserves space from the freestore
	// (memory) and is identified by the pointer a.
	a = new int[array_size];

	fill_array(a, array_size);
	sort(a, array_size);

	cout << "in sorted order the number are:\n";
	for(int i = 0; i < array_size; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	// The delete operator eliminates a dynamic variable and returns the memory that the dynamic variable occupied to the freestore.
	delete [] a;
	return 0;
}

void fill_array(int a[], int size) {
	cout << "Enter " << size << " integers.\n";
	for(int i = 0; i < size; i++)
		cin >> a[i];
}

void sort(int a[], int size) {
	for(int i = 0; i < size - 1; i++) {
		int temp = a[i];
		for(int j = i; j < size; j++) {
			if(a[i] > a[j]) {
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

// How to Use a Dynamic Array
// ■ Define a pointer type: Define a type for pointers to variables of the same
// type as the elements of the array. For example, if the dynamic array is an
// array of double, you might use the following:
// typedef double* DoubleArrayPtr;
// ■ Declare a pointer variable: Declare a pointer variable of this defined type.
// The pointer variable will point to the dynamic array in memory and will serve
// as the name of the dynamic array.
// DoubleArrayPtr a;
// ■ Call new: Create a dynamic array using the new operator:
// a = new double[array_size];
// The size of the dynamic array is given in square brackets as in the example
// above. The size can be given using an int variable or other int expression.
// In the example above, array_size can be a variable of type int whose
// value is determined while the program is running.
// ■ Use like an ordinary array: The pointer variable, such as a, is used just like
// an ordinary array. For example, the indexed variables are written in the usual
// way: a[0], a[1], and so forth. The pointer variable should not have any
// other pointer value assigned to it, but should be used like an array variable.
// ■ Call delete[ ]: When your program is finished with the dynamic variable,
// use delete and empty square brackets along with the pointer variable to
// eliminate the dynamic array and return the storage that it occupies to the
// freestore for reuse. For example:
// delete [] a;
