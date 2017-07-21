// Appends data to the end of the file data.txt
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {

	cout << "Opening data.txt for appending.\n";
	ofstream out_stream;
	out_stream.open("data.txt", ios::app); 
	// ios::app allows appending.
	// it is a special constant defined in 
	// iostream.
	if(out_stream.fail()) {
		cout << "File opening failed!\n";
		exit(1);
	}

	out_stream << "5 6 pick up sticks.\n";
	out_stream << "7 8 ain't C++ great!\n";

	out_stream.close();
	cout << "End of appending to file.\n";

	return 0;
}