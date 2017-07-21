#include <iostream>
using namespace std;

void get_input(int& hours, int& minutes, char& ampm);
// Prompts the user for the time in 24-hour format,
// then stores the input into hours and minutes.

void convertTo12(int& hours);
// Converts 24-hour formatted time to 12-hour time.

void output(int hours, int minutes, char ampm);
// Prints out the 12 hour format.

int main() {
	int hours, minutes;
	char ampm;
	get_input(hours, minutes, ampm);
	convertTo12(hours);
	output(hours, minutes, ampm);

	return 0;
}

void get_input(int& hours, int& minutes, char& ampm) {
	cout << "Please enter the time in (24-hour format) hours and minutes (hh mm): ";
	cin >> hours >> minutes;
	if(hours < 12) 
		ampm = 'A';
	else 
		ampm = 'P';
}

void convertTo12(int& hours) {
	hours%=12;
	if(hours==0) hours = 12;
}

void output(int hours, int minutes, char ampm) {
	if(ampm == 'A')
		cout << "The time in 12-hour format is " << hours << ":" << minutes << "AM" << endl;
	else {
		cout << "The time in 12-hour format is " << hours << ":" << minutes << "PM" << endl;
	}
}