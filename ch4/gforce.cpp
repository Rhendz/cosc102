#include <iostream>
using namespace std;

double gforce(double m1, double m2, double d);
// Returns the gravitational attractive force
// between two masses (m1 and m2) separated
// by a distance d. 

const double G = 6.673e-8;

int main() {
	double m1, m2, d;

	cout << "Enter the mass of body 1 (in grams): ";
	cin >> m1;
	cout << "Enter the mass of body 2 (in grams): ";
	cin >> m2;
	cout << "Enter the distance between the bodies (in cm): ";
	cin >> d;
	cout << endl;

	cout << "The gravitational force between both bodies is " 
		 << gforce(m1, m2, d) << " gram-centimeters per seconds squared.";

	return 0;
}

double gforce(double m1, double m2, double d) {
	return (G*m1*m2)/(d*d);
}