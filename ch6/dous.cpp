// The following is an old word puzzle: "Name a common word
// , besides tremendous, stupendous, and horrendous, that 
// ends in dous."
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void find_dous(ifstream& fin, ofstream& fout);
// Outputs all occurrences of dous to file.
bool isDous(ifstream& fin2);
// Checks whether a word countains dous or not.

int main() {
	ifstream fin;
	ofstream fout;

	fin.open("simple.txt");
	if(fin.fail()) {
		cout << "Opening input failed!\n";
		exit(1);
	}
	fout.open("dous.txt");
	if(fout.fail()) {
		cout << "Opening output failed!\n";
		exit(1);
	}

	find_dous(fin, fout);

	fin.close();
	fout.close();

	return 0;
}

void find_dous(ifstream& fin, ofstream& fout) {
	ifstream fin2;
	fin2.open("simple.txt");
	if(fin2.fail()) {
		cout << "Opening input failed!\n";
		exit(1);
	}
	while(!fin.eof()) {
		char c;
		fin.get(c);
		if(c == '\n') break;
		// Check if word contains dous
		if(isDous(fin2)) {
			do {
				fout.put(c);
				fin.get(c);
			} while(c != '\n');
		} else {
			do {
				fin.get(c);
			} while(c != '\n');
		}
	}

	fin2.close();
}

bool isDous(ifstream& fin2) {
	char c;
	fin2.get(c);
	bool trigger; // Flag for dous
	do {
		trigger = false; // If s was not the last letter
		if(c == 'd') {
			fin2.get(c);
			if(c == 'o') {
				fin2.get(c);
				if(c == 'u') {
					fin2.get(c);
					if(c == 's') {
						trigger = true;
						fin2.get(c);
					}
				}
			}
		}
		fin2.get(c);
	} while(c != '\n');
	return trigger;
}