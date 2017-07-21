#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void copy_line(istream& is = cin);

int main() {
	ifstream fin;
	fin.open("stuff.dat");
	if(fin.fail()) {
		cout << "File opening failed!\n";
		exit(1);
	}
	cout << "Enter text or sit back and wait for the file!\n";
	copy_line(fin);
	copy_line();
	fin.close();
	return 0;
}

void copy_line(istream& is) {
	char c;
	is.get(c);
	do {
		cout << c;
		is.get(c);
	} while(c != '\n');
	cout << c;
}