//Program to create a file called cplusad.dat that is identical to the file
//cad.dat, except that all occurrences of 'C' are replaced by "C++".
//Assumes that the uppercase letter 'C' does not occur in cad.dat except
//as the name of the C programming language.
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;
void add_plus_plus(ifstream& in_stream, ofstream& out_stream);

int main() {
	ifstream fin;
	ofstream fout;

	cout << "Begin editing files.\n";
	fin.open("cad.dat");
	if(fin.fail()) {
		cout << "Input file opening failed.\n";
		exit(1);
	}
	fout.open("cplusad.dat");
	if(fout.fail()) {
		cout << "Output file opening failed.\n";
		exit(1);
	}
	add_plus_plus(fin, fout);
	fin.close();
	fout.close();
	cout << "End of editing files.\n";
	return 0;
}

void add_plus_plus(ifstream& in_stream, ofstream& out_stream) {
	char next;
	in_stream.get(next);
	while(!in_stream.eof()) {
		if(next == 'C') {
			out_stream << "C++";
		} else {
			out_stream << next;
		}
		in_stream.get(next);
	}
}
