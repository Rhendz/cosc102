/*------------------------------------------------
Author: Ankush Patel
Program: bmr2.cpp
Description: Uses the Harris-Benedict equation to
estimate the number of calories your body needs
to maintain your weight if you do no exercise.
In addition to the first version of BMR, this
calculator provides options for those who do
exercise.
------------------------------------------------*/

#include <iostream>
using namespace std;

int main() {
	//Weight in lbs and height in inches
	double weight(0), height(0), BMR(0);
	int age(0); //Age in years
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

	cout << "Please select one of the following options for a more accurate analysis of your BMR (Type in the number)\n" << "1. Sedentary\n" << "2. Somewhat active (exercise occasionally)\n" << "3. Active (exercise 3-4 days per week)\n" << "4. Highly active (exercise every day)\n";

	int option;

	cin >> option;

	switch(option) {
		case 1:
			BMR+=(BMR*0.2);
			break;
		case 2:
			BMR+=(BMR*0.3);
			break;
		case 3:
			BMR+=(BMR*0.4);
			break;
		case 4:
			BMR+=(BMR*0.5);
			break;
		default:
			cout << "BMR will not be manipulated based on invalid option selected" << endl;
			break;
	}

	cout << "You must consume " << BMR/CHOCOBAR_CAL << " chocolate bars in order to maintain your weight." << endl;

	return 0;
}
