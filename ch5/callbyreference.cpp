// Demonstrates call-by-reference parameters.

// Call-by-value parameters are simply compies of
// there original parameters; therefore, editing 
// those parameters results in a new copy or set of
// parameters distinct from the original parameters.

// However, call-by-reference parameters represent
// the actual value of the parameter; therefore, any
// edits to the parameter result in the variable being
// called to change. Furthermore, in order to 
// distinguish a call-by-reference from 
// a call-by-value, C++ uses var_type& var_name.

#include <iostream>

void get_numbers(int&, int&);
// Reads two integers from the keyboard.

void swap_values(int& variable1, int& variable2);
// Interchanges the values of variable1 and variable2.

void show_results(int output1, int output2);
// Shows the values of variable1 and variable2, in that order.

int main() {
	using namespace std;
	int first_num = 0, second_num = 0;

	get_numbers(first_num, second_num);
	swap_values(first_num, second_num);
	show_results(first_num, second_num);
	return 0;
}

void get_numbers(int& input1, int& input2) {
	using namespace std;
	cout << "Enter two integers: ";
	cin >> input1
	    >> input2; 
}

void swap_values(int& variable1, int& variable2) {
	int temp;
	temp = variable1;
	variable1 = variable2;
	variable2 = temp;
}

void show_results(int output1, int output2) {
	using namespace std;
	cout << "In reverse order the numbers are: " << output1 << " " << output2 << endl;
}