#include <iostream>
using namespace std;

int strlen(char cstring[]);
// Returns the length of the cstring.

int main() {
	char someRandomString[] = "Hello, how are you doing?";
	cout << "Expected length: 25" << endl;
	cout << "Actual length: " << strlen(someRandomString) << endl;
	return 0;
}

int strlen(char cstring[]) {
	int length(0);
	while(cstring[length] != '\0') length++;
	return length;
}