#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
	ofstream ofs;
	ofs.open("putback.txt");
	if(ofs.fail()) {
		cout << "Opening file failed\n";
		exit(1);
	}

	cout << "Enter a sentence and the program will write to putback.txt until the first space (not including the first space)\n";
	char symbol;
	cin.get(symbol); // Don't forget to initialize symbol.
	do {
		// It is crucial to output before input so that the next symbol can be checked.
		// This way a space is not included in the .txt. 
		ofs.put(symbol);
		cin.get(symbol);
	} while(symbol != ' ');
	cin.putback(symbol); // This puts the 'space' symbol back into the input stream.

	// Refreshing the symbol from the input stream
	// If there is no putback, the symbol will be 'i' otherwiser it is a ' '.
	cin.get(symbol);
	cout << "This is the symbol that was put back into the input stream: " << "\"" << symbol << "\""<< endl;
	return 0;
}