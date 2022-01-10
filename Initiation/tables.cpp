#include <iostream>
using namespace std;

int main() {
	cout << "Tables de multiplications :" << endl << endl;
	for (int i(2); i <= 10; ++i) {
		cout << endl <<"Table de " << i << " :" << endl << endl;
		for (int j(1); j <= 10; ++j) {
			cout << j << " * " << i << " = " << i * j << endl;
		}
	}


	return 0;
}