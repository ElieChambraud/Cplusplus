#include <iostream>
using namespace std;

int main() {
	double n(0.0);
	cout << "Entrez un nombre :" << endl;
	cin >> n;
	if (((not(n < 2)) and (n < 3)) or ((not((n < 0) or (n == 0))) and ((n < 1) or (n == 1))) or ((not(n < -10)) and ((n < -2) or (n == -2)))) {
		cout << "x appartient à I" << endl;
	}
	else {
		cout << "x n'appartient pas à I" << endl;
	}
	return 0;
}