#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

// Encodes and decodes zipcodes and barcodes, respectively.
class Zipcode {
public:
	Zipcode(int zip_code);
	Zipcode(string bar_code);
	int getZipcode();
	string getBarcode();

private:
	const vector<int> valRef = {7, 4, 2, 1, 0};
	bool isBarcode(string bar_code);
	string encode(int zip_code);
	string getZipNumEncoding(int zip_num);
	int decode(string bar_code);
	int zip_code;
	string bar_code;
};

int main() {
	Zipcode test(99504);
	cout << "The barcode for " << test.getZipcode()
		 << " is " << test.getBarcode() << endl;

	Zipcode test2(test.getBarcode());
	cout << "The zipcode for " << test2.getBarcode()
		 << " is " << test2.getZipcode() << endl;

	return 0;
}

Zipcode::Zipcode(int zip_code) {
	zip_code = zip_code;
	bar_code = encode(zip_code);
}

Zipcode::Zipcode(string bar_code) {
	if(!isBarcode(bar_code)) {
		cout << "Invalid barcode!" << endl;
		exit(1);
	}
	else {
		zip_code = decode(bar_code);
	}
}

int Zipcode::getZipcode() {
	return zip_code;
}

string Zipcode::getBarcode() {
	return bar_code;
}

bool Zipcode::isBarcode(string bar_code) {
	return bar_code.at(0) == '1' && bar_code.at(bar_code.length() - 1) == '1';
}

string Zipcode::encode(int zip_code) {
	string bc = "1";
	string zc = to_string(zip_code);
	for(int i = 0; i < zc.length(); i++)
		bc+=(getZipNumEncoding(stoi(zc.substr(i, 1))));
	return bc += "1";
}

string Zipcode::getZipNumEncoding(int zip_num) {
	string group;
	int numOfOnes = 0;
	// Special Case
	if(zip_num == 0) return "11000";
	for(int i = 0; i < valRef.size(); i++) {
		if(zip_num >= valRef[i] && numOfOnes < 2) {
			group += "1";
			numOfOnes++;
			zip_num -= valRef[i];
		} else {
			group += "0";
		}
	}
	return group;
}
// Add in functionality for Barcode chunk
int Zipcode::decode(string bar_code) {
	string zcS;
	// Take out first one and last one
	string bc = bar_code.substr(1, bar_code.length()-2);
	for(int i = 0; i < bc.length(); i++) {
		int zip_num(0);
		if(bc.at(i%5) == '1') zip_num+=valRef[i%5];
		if(zip_num == 11) zip_num = 0;
		zcS += to_string(zip_num);
	}
	cout << zcS;
	return stoi(zcS);
}
