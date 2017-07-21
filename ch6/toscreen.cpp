#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void to_screen(ifstream& fin);
//Precondition: The stream file_stream has been connected
//to a file with a call to the member function open. The
//file contains a list of integers (and nothing else).
//Postcondition: The numbers in the file connected to
//file_stream have been written to the screen one per line.
//(This function does not close the file.)

int main() {
	ifstream fin;
	fin.open("toscreen.txt");
	if(fin.fail()) {
		cout << "Opening file failed!\n";
		exit(1);
	}

	to_screen(fin);

	fin.close();

	return 0;
}

void to_screen(ifstream& fin) {
	cout.setf(ios::fixed);
	cout.precision(0);
	double next;
	while(fin >> next) {
		cout << next << endl;
	}
}
