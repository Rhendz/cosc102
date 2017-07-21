#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double n, guess, previousGuess;
	cin >> n;
	previousGuess = n;
	guess = n/2;

	while(abs(previousGuess-guess)/((previousGuess+guess)/2)*100 > 0.01) {
		double r = n/guess;
		previousGuess = guess;
		guess = (guess + r) / 2;
	}

	cout << "The square root of " << n << " is " << guess << endl;
}