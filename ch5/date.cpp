// This program computes the day of the week based on the date.
#include <iostream>
using namespace std;

bool isLeapYear(int year);
// Returns true if year is a leap year and false if it is not.

int getCenturyValue(int year);
int getYearValue(int year);
int getMonthValue(int month, int year);
// For calculating the day of the week

void getInput(int& year, int& month, int& day);
// Prompts the user for input and uses call-by-reference
// to initialize the variables.

int main() {
	int year(0), month(0), day(0);

	getInput(year, month, day);
	int sum = day + getCenturyValue(year) + getYearValue(year) + getMonthValue(month, year);
	sum%=7;

	cout << "The day is ";

	switch(sum) {
		case 0: 
			cout << "Sunday";
			break;
		case 1: 
			cout << "Monday";
			break;
		case 2: 
			cout << "Tuesday";
			break;
		case 3: 
			cout << "Wednesday";
			break;
		case 4: 
			cout << "Thursday";
			break;
		case 5: 
			cout << "Friday";
			break;
		case 6: 
			cout << "Saturday";
			break;
		default: 
			cout << "Something went wrong!";
			break;
	}

	return 0;
}

bool isLeapYear(int year) {
	return (year%400 == 0) || (year%4==0 && year%100!=0);
}

int getCenturyValue(int year) {
	int centuryVal = year/100;
	centuryVal%=4;
	return (3 - centuryVal)*2;
}

int getYearValue(int year) {
	int yearVal = year%100;
	return yearVal + yearVal/4;
}

int getMonthValue(int month, int year) {
	switch(month) {
		case 1: 
			if(isLeapYear(year)) return 6;
			else return 0;
		case 2:
			if(isLeapYear(year)) return 2;
			else return 3;
		case 3:
			return 3;
		case 4:
			return 6;
		case 5:
			return 1;
		case 6:
			return 4;
		case 7: 
			return 6;
		case 8:
			return 2;
		case 9:
			return 5;
		case 10:
			return 0;
		case 11:
			return 3;
		case 12:
			return 5;
		default: 
			cout << "Incorrect month!" << endl;
			return 99;
	}
}

void getInput(int& year, int& month, int& day) {
	cout << "Welcome, I am going to compute the day of the week, " 
		 << "but first I need a few pieces of information.\n";

	cout << "Please enter the year: ";
	cin >> year;
	cout << endl;

	cout << "Please enter the month(1-12): ";
	cin >> month;
	cout << endl;

	cout << "Please enter the day(1-31): ";
	cin >> day;
	cout << endl;
}