/*------------------------------------------------
Author: Ankush Patel
Program: enums.cpp
Description: About enums
------------------------------------------------*/

// Enums are used to group together related constants.
// There are two types of enums: enums and strongly typed
// enums. Look here https://stackoverflow.com/questions/12581064/enum-vs-strongly-typed-enum

#include <iostream>
using namespace std;

int main() {
	enum Direction {N, S, E, W};

	cout << W << " " << E << " " << S << " " << N << endl;
}