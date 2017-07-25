// Test for palindrom property.
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void swap(char& v1, char& v2);
// Interchanges the values of v1 and v2.

string reverse(const string& s);
// Returns a copy of s but with characters in reverse order.

string remove_punct(const string& s, const string& punct);
// Returns a copy of s with any occurrences of characters
// in the string punct removed.

string make_lower(const string& s);
// Returns a copy os s that has all uppercase
// character changed to lowercase, other character unchanged.

bool is_pal(const string& s);
// Returns true if s is a palindrome, false otherwise.

int main() {
	string str;
	cout << "Enter a candidate for palindrome test\n"
		 << "followed by pressing Return.\n";
	getline(cin, str);
	if(is_pal(str))
		cout << "\"" << str + "\" is a palindrome.";
	else
		cout << "\"" << str + "\" is not a palindrome.";
	cout << endl;
	return 0;
}

void swap(char& v1, char& v2) {
	char temp = v1;
	v1 = v2;
	v2 = temp;
}

string reverse(const string& s) {
	int start = 0;
	int end = s.length();
	string temp(s);

	while(start < end) {
		end--;
		swap(temp[start], temp[end]);
		start++;
	}
	return temp;
}

string make_lower(const string& s) {
	string temp(s);
	for(int i = 0; i < s.length(); i++) {
		temp[i] = tolower(s[i]);
	}
	return temp;
}

string remove_punct(const string& s, const string& punct) {
	string no_punct;
	int s_length = s.length();
	int punct_length = punct.length();
	for(int i = 0; i < s_length; i++) {
		string a_char = s.substr(i, 1);
		int location = punct.find(a_char, 0);
		if(location < 0 || location >= punct_length)
			no_punct = no_punct + a_char;
	}
	return no_punct;
}

bool is_pal(const string& s) {
	string punct(",;:.?!'\" ");
	string str(s);
	str = make_lower(str);
	string lower_str = remove_punct(str, punct);
	return(lower_str == reverse(lower_str));
}
