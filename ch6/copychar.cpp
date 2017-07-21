#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void copy_char(istream& is = cin);
// Default stream is cin
// NOTE! Default paremter implementation
// should only be defined in the function header!

int main() {
	ifstream ifs;
	ifs.open("stuff.dat");
	if(ifs.fail()) {
		cout << "Opening file failed!\n";
		exit(1);
	}

	copy_char(ifs);
	copy_char();

	ifs.close();
	return 0;
}

void copy_char(istream& is) {
	char c;
	cout << "Enter text or sit back and wait for the file!\n";
	is.get(c);
	cout << "This is the symbol " << c << endl;
}

