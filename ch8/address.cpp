#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

vector<string> getContact(ifstream& fin, string& kw);
// Returns a vector filled with strings of the
// resident's details

void outputPalmdale(const vector<string> contact);
// Outputs address data if the user is in Palmdale

void outputZip(const vector<string> contact);
// Outputs zip data for residents who have zips 90210 through 90214

void removeTag(string& str);
// Removes the angles brackets associated with a string

void getContactDetails(const vector<string> contact);
// Cleans up data label

bool isAddressBook(ifstream& fin, string& kw);
// Makes sure the XML is properly formatted
// and contains an Address Book

int main() {
	ifstream fin;
	fin.open("address.xml");
	if(fin.fail()) {
		cout << "Opening input file failed!\n";
		exit(1);
	}

	string kw;
	if(isAddressBook(fin, kw)) {
		getline(fin, kw);
		cout << "These are the residents of Palmdale and reisdents who possess zips of 90210 - 90214: " << endl;
		do {
			vector<string> contact = getContact(fin, kw);
			outputPalmdale(contact);
			outputZip(contact);
			getline(fin, kw);
		} while(kw.find("/address_book") == -1 && !fin.eof());
	}
	return 0;
}

bool isAddressBook(ifstream& fin, string& kw) {
	do {
		getline(fin, kw);
	} while(kw.find("address_book") == -1 && !fin.eof());

	if(kw.find("address_book") != -1) {
		cout << "Address Book has been found!\n";
		return true;
	}
	else {
		cout << "Address Book has not been found!\n";
		return false;
	}
}

vector<string> getContact(ifstream& fin, string& kw) {
	vector<string> contact;
	do {
		if(kw.find("contact") == -1) contact.push_back(kw);
		getline(fin, kw);
	} while(kw.find("/contact") == -1 && !fin.eof());
	return contact;
}

void outputPalmdale(const vector<string> contact) {
	// Checks whether the person is in Palmdale
	if(contact[2].find("Palmdale") != -1) {
		string name = contact[0], street = contact[1], city = contact[2], state = contact[3], zip = contact[4];

		removeTag(name);
		removeTag(street);
		removeTag(city);
		removeTag(state);
		removeTag(zip);

		cout << "Palmdale: " << "Hello, " << name << " lives at " << street << " " << city << ", " << state << " " << zip << endl;
	}
}

void outputZip(const vector<string> contact) {
	string zip = contact[4];
	removeTag(zip);
	int zipNum = atoi(zip.c_str());
	if(zipNum >= 90210 && zipNum <= 90214) {
		string name = contact[0], street = contact[1], city = contact[2], state = contact[3];

		removeTag(name);
		removeTag(street);
		removeTag(city);
		removeTag(state);

		cout << "Zip: " << "Hello, " << name << " lives at " << street << " " << city << ", " << state << " " << zip << endl;
	}
}

void removeTag(string& str) {
	string arg1 = ">", arg2 = "</";
	str = str.substr(str.find(arg1)+1);
	str = str.substr(0, str.find(arg2));
}
