#include <vector>
#include <iostream>
#include <string>
using namespace std;

vector<string> split(string target, string delimiter);
// Returns a vector of the strings in target that are
// separated by the string delimiter.

int main() {
	string nums = "10,20,30", numsd = ",";
	string notes = "do re mi fa sa la ti do", notesd = " ";
	vector<string> num = split(nums, numsd);
	vector<string> note = split(notes, notesd);

	for(auto i : num) cout << i << " ";
	cout << endl;
	for(auto i : note) cout << i << " ";

	return 0;
}

vector<string> split(string target, string delimiter) {
	vector<string> str;
	do {
		int match = target.find(delimiter);
		if(match != -1) {
			str.push_back(target.substr(0, match));
			target = target.substr(match + 1);
		} else {
			str.push_back(target);
			target = target.substr(target.length());
		}
	} while(target.length() != 0);
	return str;
}
