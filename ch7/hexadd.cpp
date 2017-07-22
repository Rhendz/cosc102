#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

void inputHex(char hexNum[], int& size, int& used);
// Allows the user to enter a hex number up to 10 numerals long.

void addHexes(const char hex1[], const int used1, const char hex2[], const int used2);
// Takes two hexadecimal numbers and prints out the sum of these numbers. If the sum happens to be greater than 10 numerals,
// then an addition overflow error is thrown.
// Prints the added number as a hexidecimal

long hexToInt(const char hex[], const int used);
// Converts a hex array of type char to an integer value of type int.

int intToHex(const long val, char hex[]);
// Converts an integer value of type int to a hex values and stores these values into a char array.
// Returns the used size of the hex

const char hexCode[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
const int hexCodeSize = 16;

int main() {
	char hexNum1[10], hexNum2[10];
	int size1(10), used1(0), size2(10), used2(0);

	inputHex(hexNum1, size1, used1);
	inputHex(hexNum2, size2, used2);

	addHexes(hexNum1, used1, hexNum2, used2);

	return 0;
}

void addHexes(const char hex1[], const int used1, const char hex2[], const int used2) {
	long num1 = hexToInt(hex1, used1);
	long num2 = hexToInt(hex2, used2);
	long sum = num1 + num2;

	char hex[10];
	int used = intToHex(sum, hex);

	cout << "The sum of the two hexidecimal numbers is: ";
	for(int i = used + 1; i < 10; i++) {
		cout << hex[i];
	}
}

void inputHex(char hexNum[], int& size, int& used) {
	cout << "Please enter a hexadecimal number within 10 digits long: ";
	char c;
	cin.get(c);
	do {
		hexNum[used] = c;
		used++;
		cin.get(c);
	} while(c != '\n' && used < size);
	cout << endl;
}

long hexToInt(const char hex[], const int used) {
	long sum(0);
	for(int i = used - 1; i >= 0; i--) {
		for(int j = 0; j < hexCodeSize; j++) {
			if(hex[i]==hexCode[j]) sum += (j*pow(16, (used - 1) - i));
		}
	}
	return sum;
}

int intToHex(const long val, char hex[]) {
	// Break the val into chunks of powers of 16 using modular arithmetic
	long tempVal = val;
	int counter = 9; // This keeps track of the size of the hex.
	while(tempVal != 0) {
		int remainder = tempVal % 16;
		tempVal/=16;
		for(int i = 0; i < hexCodeSize; i++) {
			if(remainder == i) hex[counter] = hexCode[i];
		}
		counter--;
		if(counter < 0) {
			cout << "Hexadecimal number is too big!" << endl;
			exit(1);
		}
	}
	return counter;
}
