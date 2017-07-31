#include <iostream>
using namespace std;

class Odometer {
public:
	Odometer();
	void zero();
	void setFuelEff(double fuelEff);
	void setMiles(double miles);
	double getGallons();
	// Returns the gallons of gas used.
private:
	double miles, fuelEff;
};

int main() {
	Odometer car1, car2;
	car1.setFuelEff(35);
	car2.setFuelEff(50);
	car1.setMiles(100);
	car2.setMiles(523);

	cout.setf(ios::fixed);
	cout.precision(2);

	cout << "Car 1 has used " << car1.getGallons() << " gallons of gas!" << endl;
	cout << "Car 2 has used " << car2.getGallons() << " gallons of gas!" << endl;

	car2.zero();

	cout << "Since the odometer has been zeroed, car 2 has used "
		 << car2.getGallons() << " gallons of gas!" << endl;
	return 0;
}

Odometer::Odometer() {
	miles = 0;
	fuelEff = 0;
}

void Odometer::zero() {
	miles = 0;
}

void Odometer::setFuelEff(double fuelEff) {
	this->fuelEff = fuelEff;
}

void Odometer::setMiles(double miles) {
	this->miles = miles;
}

double Odometer::getGallons() {
	return miles/fuelEff;
}
