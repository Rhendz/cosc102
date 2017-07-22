#include <iostream>
using namespace std;

void one_more(int a[]) {
	for(int i = 0; i < 5; i++) a[i]++;
}

int main() {
	int arr[5];
	cout << "Type in value for array:\n";
	for(int& i : arr) {
		cin >> i;
	}
	cout << endl;

	cout << "The values of the array after adding one:\n";
	one_more(arr);
	for(int i : arr) {
		cout << i << " ";
	}
	return 0;
}
