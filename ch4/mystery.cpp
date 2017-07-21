#include <iostream>
using namespace std;

char mystery(int first_par, int second_par);

int main() {
	cout << mystery(10, 9) << "ow\n";
	return 0;
}

char mystery(int first_par, int second_par) {
	if(first_par >= second_par)
		return 'W';
	else 
		return 'H';
}