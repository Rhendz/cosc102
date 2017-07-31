#include <iostream>
using namespace std;

struct ShoeType {
	char style;
	double price;
};

ShoeType discount(ShoeType old_record);
// Returns a structure that is the same as its argument,
// but with the price reduce by 10%.

int main() {
	ShoeType shoe1;
	shoe1.style = 'A';
	shoe1.price = 25.00;

	cout.setf(ios::fixed);
	cout.precision(2);

	cout << shoe1.style << " $" << shoe1.price << endl;

	shoe1 = discount(shoe1);
	cout << "After applying a 10% discount, the price "
	<< "of shoe 1 is $" << shoe1.price << endl;
	return 0;
}

ShoeType discount(ShoeType old_record) {
	old_record.price-=old_record.price*0.1;
	return old_record;
}
