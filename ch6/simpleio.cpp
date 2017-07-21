// Reads three numbers from the file infile.dat, sums the numbers,
// and writes the sum to the file outfile.dat.

// For overview of simple file io go to page 318.

#include <iostream>
#include <cstdlib>
#include <fstream>
// This library is used to open streams.
using namespace std;

int main() {
	ifstream in_stream; // This reads files for input
	ofstream out_stream; // This reads files for output

	in_stream.open("infile.dat");
	// After each call to open a file, make sure to include
	// a response if the file fails to open.
	if(in_stream.fail()) {
		cout << "Input file opening failed.\n";
		exit(1); // Ends the program (in cstdlib)
	}

	out_stream.open("outfile.dat");
	if(out_stream.fail()) {
		cout << "Output file opening failed.\n";
		exit(1); // Ends the program (in cstdlib)
	}
	int first, second, third;
	in_stream >> first >> second >> third;
	out_stream << "The sum of the first 3\n"
			   << "numbers in infile.date\n"
			   << "is " << (first + second + third)
			   << endl;

	// Close the streams if you don't want the files to be corrupted.
	in_stream.close();
	out_stream.close();
	return 0;
}
