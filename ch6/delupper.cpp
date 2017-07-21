#include <iostream>
#include <cctype>
using namespace std;

void delUpper();

int main() {
	cout << "Enter a sentence, and I will delete all the lowercase letters\n";
	delUpper();
	return 0;
}

void delUpper() {
	char c;
	cin.get(c);
	do {
		if(!isupper(c)) 
			cout << c;
		cin.get(c);
	} while(c != '\n');
}