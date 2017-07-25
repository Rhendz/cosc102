// Reads a parapraph
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

void showOutput(ifstream& fin);
// Preconditions: Requires paragraph.txt
// Outputs a paragraph line by line from the input file.

int main() {
	ifstream fin;
	fin.open("paragraph.txt");
	if(fin.fail()) {
		cout << "Opening input file failed!\n";
		exit(1);
	}
	showOutput(fin);
	fin.close();
	return 0;
}

void showOutput(ifstream& fin) {
	string input;
	getline(fin, input);
	do {
		cout << input << endl;
	} while(getline(fin, input));
}
