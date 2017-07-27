// Decrypts secret message encrypted by the enemy.
#include <iostream>
#include <string>
using namespace std;

string decrypt(const string encrypted_msg, const int key);
// Takes the encrypted message and a given key (1 - 100),
// and attemps to return a decrypted message.

int main() {
	string encrypted_msg = ":mmZ\\dxZmx]Zpgy";
	// Added a \ to supress warning
	for(int i = 1; i <= 100; i++) {
		string decrypted_msg = decrypt(encrypted_msg, i);
		cout << "Key " << i << ":" << decrypted_msg << endl;
	}
	return 0;
}

string decrypt(const string encrypted_msg, const int key) {
	string decrypted_msg;
	for(int i = 0; i < encrypted_msg.length(); i++) {
		int oc = encrypted_msg.at(i) - key;
		if(oc + key > 126) oc += 95;
		decrypted_msg+=static_cast<char>(oc);
	}
	return decrypted_msg;
}
