#include <iostream>
using namespace std;

int main() {
	int address = 0;
	int ones(0), tens(0), hundreds(0), thousands(1);
	for(int i = 1000; i < 10000 && address == 0; i++) {
		if(ones != tens && ones != hundreds && ones != thousands && tens != hundreds && tens != thousands && hundreds != thousands) {
			if(thousands == (3 * tens)) {
				if(i%2!=0) {
					if((ones + tens + hundreds + thousands) == 27) {
						address = i;
					}
				}
			}
		}

		ones++;
		if(ones == 10) {
			ones = 0;
			tens++;
		}
		if(tens == 10) {
			tens = 0;
			hundreds++;
		}
		if(hundreds == 10) {
			hundreds = 0;
			thousands ++;
		}
	}

	cout << "The address is : " << address << endl;
	return 0;
}
