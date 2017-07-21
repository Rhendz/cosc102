/*------------------------------------------------
Author: Ankush Patel
Program: bmr.cpp
Description: Uses the Harris-Benedict equation to 
estimate the number of calories your body needs
to maintain your weight if you do no exercise.
------------------------------------------------*/

#include <iostream>
using namespace std;

int main() {
	//Weight in lbs and height in inches
	double weight, height, BMR;
	int age; //Age in years
	char gender;

	const int CHOCOBAR_CAL = 230;

	cout << "Please enter your weight in lbs: ";
	cin >> weight;
	cout << endl;

	cout << "Please enter your height in inches: ";
	cin >> height;
	cout << endl;

	cout << "Please enter your age in years: ";
	cin >> age;
	cout << endl;

	cout << "Please enter your gender (M or F): ";
	cin >> gender;
	cout << endl;

	if (gender=='M') {
		BMR = 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age);
	} else if (gender=='F') {
		BMR = 655 + (4.3 * weight) + (4.7 * height) - (4.7 * age);
	} else {
		cout << "No gender-specific analysis found." << endl;
	}

	cout << "You must consume " << BMR/CHOCOBAR_CAL << " chocolate bars in order to maintain your weight." << endl;

	return 0;
}