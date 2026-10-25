#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

int main() {
	//Plan prices and the included data
	const double PlanA = 39.99;
	const double PlanB = 59.99;
	const double PlanC = 79.99;
	const double PlanAData = 2.0;
	const double PlanBData = 8.0;
	const double ExtraDataCharge = 8.00;

	string name;
	char plan;
	double dataUsed;

	cout << "Enter customer name: ";
	getline(cin, name);

	cout << "Enter plan purchased (A, B, or C): ";
	cin >> plan;
	plan = toupper(plan);

	if (plan != 'A' && plan != 'B' && plan != 'C') {
		cout << "Invalid plan selection. Please enter A, B, or C." << endl;
		return 1;
	}

	cout << "Enter gigabytes of data used: ";
	cin >> dataUsed;

	if (dataUsed < 0) {
		cout << "Data used cannot be negative." << endl;
		return 1;
	}

	//Cost of eah plan for this usage
	double costA = PlanA;
	if (dataUsed > PlanAData)
		costA += (dataUsed - PlanAData) * ExtraDataCharge;
	
	double costB = PlanB;
	if (dataUsed > PlanBData)
		costB += (dataUsed - PlanBData) * ExtraDataCharge;

	double costC = PlanC;

	double total;
	if (plan == 'A') {
		total = costA;
	}
	else if (plan == 'B') {
		total = costB;
	}
	else {
		total = costC;
	}

	cout << fixed << setprecision(2);
	cout << "Customer: " << name << endl;
	cout << "Plan: " << plan << endl;
	cout << "Data Used: " << dataUsed << " GB" << endl;
	cout << "Total Cost: $" << total << endl;

	//Savings messages (only if applicable)
	if (plan == 'A') {
		if (costA - costB > 0)
			cout << "You could have saved $" << (costA - costB) << " by switching to Plan B." << endl;
		if (costA - costC > 0)
			cout << "You could have saved $" << (costA - costC) << " by switching to Plan C." << endl;
	}
	else if (plan == 'B') {
		if (costB - costC > 0)
			cout << "You could have saved $" << (costB - costC) << " by switching to Plan C." << endl;
	}

	return 0;
}