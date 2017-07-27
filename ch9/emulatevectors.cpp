#include <iostream>
#include <string>
using namespace std;

// Test Cases:
// Bob Jim
// Sydney Lavender
// Cool Pickle
// Dank Man
// Courageous Bonobo

typedef string* StringArrayPtr;

string* addEntry(string *dynamicArray, int &size, string newEntry);
// Creates a new dynamic array one element larger than
// dynamicArray, copies all the elements from
// dynamicArray into the new array, adds the new
// entry onto the end of the new array, increments
// size, deletes dynamicArray, and returns the new
// dynamic array.

string* deleteEntry(string *dynamicArray, int &size, string entryToDelete);
// Similar process to addEntry, but deletes an entry
// and adjust the dynamicArray appropriately.

int main() {
	int size = 5;
	StringArrayPtr dynamicArray;
	dynamicArray = new string[size];

	cout << "Please enter 5 names (hit enter after each one)" << endl;
	for(int i = 0; i < size; i++) {
		getline(cin, dynamicArray[i]);
	}
	cout << endl;

	cout << "This is the current array of names: " << endl;
	for(int i = 0; i < size; i++) {
		cout << dynamicArray[i] << endl;
	}
	cout << endl;

	cout << "Add a name: " << endl;
	string nameToAdd;
	getline(cin, nameToAdd);
	cout << endl;
	dynamicArray = addEntry(dynamicArray, size, nameToAdd);
	cout << "New size: " << size << endl;
	for(int i = 0; i < size; i++) {
		cout << dynamicArray[i] << endl;
	}
	cout << endl;

	cout << "Delete a name: " << endl;
	string nameToDelete;
	getline(cin, nameToDelete);
	cout << endl;
	dynamicArray = deleteEntry(dynamicArray, size, nameToDelete);
	cout << "New size: " << size << endl;
	for(int i = 0; i < size; i++) {
		cout << dynamicArray[i] << endl;
	}
	cout << endl;

	delete [] dynamicArray;
	cout << "End of simulation!" << endl;
	return 0;
}

string* addEntry(string *dynamicArray, int &size, string newEntry) {
	// New dynamicArray that is one size larger.
	StringArrayPtr newDynamicArray;
	newDynamicArray = new string[size + 1];

	for(int i = 0; i < size; i++) {
		newDynamicArray[i] = dynamicArray[i];
	}

	newDynamicArray[size] = newEntry;
	size++;

	delete [] dynamicArray;
	return newDynamicArray;
}

string* deleteEntry(string *dynamicArray, int &size, string entryToDelete) {
	StringArrayPtr newDynamicArray;
	newDynamicArray = new string[size - 1];
	bool entryFound = false;
	// Looks for the entryToDelete
	for(int i = 0; i < size; i++) {
		if(dynamicArray[i] == entryToDelete) {
			cout << "It was found" << endl;
			entryFound = true;
		}
	}

	if(entryFound) {
		// Maintains the actual position to edit in
		// the newDynamicArray.
		int count = 0;
		for(int i = 0; i < size; i++) {
			if(dynamicArray[i] != entryToDelete) {
				newDynamicArray[count] = dynamicArray[i];
				count++;
			}
		}
		size--;
		delete [] dynamicArray;
		return newDynamicArray;
	} else {
		delete [] newDynamicArray;
		return dynamicArray;
	}
}
