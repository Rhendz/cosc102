#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
	double next, sum(0);
	int count(0);

	ifstream in_stream;
	in_stream.open("average.txt");

	if(in_stream.fail()) {
		cout << "Input file opening failed!" << endl;
		exit(1);
	}

	// Read till end of file.
	// Essentially, in_stream feeds a value from the file to the
	// variable next. The >> is a condition that represents
	// as long as there is a value that can be stored in next in
	// the in_stream then true, otherwise false.
	while(in_stream >> next) {
		sum+=next;
		count++;
	}

	cout << "The average is " << sum/count << endl;
	return 0;
}