#include <iostream>
using namespace std;

int main() {
	cout << "Enter a line of input and I will echo it:\n";
	char symbol;
	do {
		cin.get(symbol);
		cout << symbol;
	} while(symbol != '\n');
	cout << "That's all for this demonstration!\n";
	cout << endl;

	cout << "Enter a line of input and I will echo it:\n";
	char symbol2;
	cin.get(symbol2);
	cout << symbol2;
	cout << "That's all for this demonstration!\n";
	return 0;
}
