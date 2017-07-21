#include <iostream>
#include <cstdlib>
using namespace std;

void shoot(bool& targetAlive, double accuracy);
// Simulates a single shot

char startDuel(bool& p1, double p1a, bool& p2, double p2a, bool& p3, double p3a);
// Simulates a duel with 3 players and their respective accuracies.
// Returns symbol representing who won.

char newStartDuel(bool& p1, double p1a, bool& p2, double p2a, bool& p3, double p3a);
// Simulates a duel with 3 players and their respective accuracies.
// Returns symbol representing who won.
// Aaron does not fire on the first shot in this one.

bool isMoreThanOne(bool t1, bool t2, bool t3);
// Returns whether more than one target is still alive or not.

int main() {

	bool a(true), b(true), c(true);
	double aA(static_cast<double>(1)/3), bA(static_cast<double>(1)/2), cA(1);

	// In order to generate a random number a
	// random seed must be used.
	// time(NULL) returns a new time object of
	// the current time.
	srand(time(NULL));

	int aC(0), bC(0), cC(0);
	for(int i = 0; i < 10000; i++) {
		char winner = startDuel(a, aA, b, bA, c, cA);
		if(winner == 'A') {
			aC++;
			cout << "Aaron won!" << endl;
		}
		else if(winner == 'B') {
			bC++;
			cout << "Bob won!" << endl;
		} 
		else {
			cC++;
			cout << "Charlie won!" << endl;
		}
		a = true, b = true, c = true;
	}
	cout << endl;

	cout << "Aaron has a probability of " << static_cast<double>(aC)/10000 << " of winning.\n";
	cout << "Bob has a probability of " << static_cast<double>(bC)/10000 << " of winning.\n";
	cout << "Charlie has a probability of " << static_cast<double>(cC)/10000 << " of winning.\n";


	return 0;
}

void shoot(bool& targetAlive, double accuracy) {
	double hitChance = static_cast<double>(rand() % 101) / 100;
	cout << "Accuracy is " << hitChance << endl;
	if(hitChance <= accuracy) {
		cout << "target was shot!" << endl;
		targetAlive = false;
	} else {
		cout << "target was missed!" << endl;
	}
	cout << endl;
}

char startDuel(bool& p1, double p1a, bool& p2, double p2a, bool& p3, double p3a) {
	// The most accurate duelist is targeted first.
	// Players go in the order of least accuracy.
	do {
		if(p3) {
			if(p1 && p3) {
				cout << "Aaron attempts to shoot Charlie!" << endl;
				shoot(p3, p1a);
			}
			if(p2 && p3) {
				cout << "Bob attempts to shoot Charlie!" << endl;
				shoot(p3, p2a);
			}
			if(p3 && p2) {
				cout << "Charlie attempts to shoot Bob!" << endl;
				shoot(p2, p3a);
			} else if (p3 && p1) {
				cout << "Charlie attempts to shoot Aaron!" << endl;
				shoot(p1, p3a);
			}
		} else {
			if(p1 && p2) {
				cout << "Aaron attempts to shoot Bob!" << endl;
				shoot(p2, p1a);
			}
			if(p2 && p1) {
				cout << "Bob attempts to shoot Aaron!" << endl;
				shoot(p1, p2a);
			}
		}
	} while(isMoreThanOne(p1, p2, p3));

	if(p1) return 'A';
	else if(p2) return 'B';
	else return 'C';
}

char newStartDuel(bool& p1, double p1a, bool& p2, double p2a, bool& p3, double p3a) {
	// The most accurate duelist is targeted first.
	// Players go in the order of least accuracy.
	do {
		if(p3) {
			if(p2 && p3) {
				cout << "Bob attempts to shoot Charlie!" << endl;
				shoot(p3, p2a);
			}
			if(p3 && p2) {
				cout << "Charlie attempts to shoot Bob!" << endl;
				shoot(p2, p3a);
			} else if (p3 && p1) {
				cout << "Charlie attempts to shoot Aaron!" << endl;
				shoot(p1, p3a);
			}
		} else {
			if(p1 && p2) {
				cout << "Aaron attempts to shoot Bob!" << endl;
				shoot(p2, p1a);
			}
			if(p2 && p1) {
				cout << "Bob attempts to shoot Aaron!" << endl;
				shoot(p1, p2a);
			}
		}
	} while(isMoreThanOne(p1, p2, p3));

	if(p1) return 'A';
	else if(p2) return 'B';
	else return 'C';
}

bool isMoreThanOne(bool t1, bool t2, bool t3) {
	return (t1 && t2) || (t1 && t3) || (t2 && t3);
}