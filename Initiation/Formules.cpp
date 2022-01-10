#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double x(0.0);
	cout << "Entrez x :" << endl;
	cin >> x;

	if (x == 0) {
		cout << "Expression 1 : indéfinie" << endl;
		cout << "Expression 2 : indéfinie" << endl;
	}
	else {
		cout << "Expression 1 : " << (x / 1 - exp(x)) << endl;
		if (x == 1) {
			cout << "Expression 2 : indéfinie" << endl;
		}
		else {
			if (x < 0) {
				cout << "Expression 2 : indéfinie" << endl;
			}
			else {
				cout << "Expression 2 : " << x * log(x) * exp(2 / (x - 1)) << endl;
			}
		}
	}
	if (x == 2) {
		cout << "Expression 3 : indéfinie" << endl;
	}
	else {
		if ((x > 0) and (x < 8)) {
			cout << "Expression 3 : indéfinie" << endl;
		}
		else {
			cout << "Expression 3 : " << (-x - sqrt(x * x - 8 * x)) / (2 - x) << endl;
		}
	}
	if (x < 1) {
		cout << "Expression 4 : indéfinie" << endl;
	}
	else {
		if (x == 0) {
			cout << "Expression 4 : indéfinie" << endl;
		}
		else {
			if ((sin(x) - x / 20) * log(x * x - 1 / x) < 0) {
				cout << "Expression 4 : indéfinie" << endl;
			}
			else {
				cout << "Expression 4 : " << sqrt((sin(x) - (x / 20)) * log(x * x - (1 / x))) << endl;
			}
		}
	}

	return 0;
}