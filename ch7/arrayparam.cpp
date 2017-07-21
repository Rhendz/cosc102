#include <iostream>
using namespace std;

void fill_up(int a[], int size);
// Precondition: size is the declared size of the array a.
// The user will type in size integers.
// Postcondition: The array a is filled with size integers
// from the keyboard.

// As a safety precaution for arrays that you do not want
// manipulated, add the const modifier.
int main() {
	int score[5], number_of_scores = 5;
	fill_up(score, number_of_scores);
	return 0;
}

void fill_up(int a[], int size) {
	cout << "Enter " << size << " numbers:\n";
	for(int i = 0; i < size; i++) 
		cin >> a[i];
	size--;
	cout << "The last array index used is " << size << endl;
}