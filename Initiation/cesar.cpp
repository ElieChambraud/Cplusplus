#include <iostream>
#include <string>
using namespace std;


char decale(char c, char debut, int decalage) {
	while (decalage < 0) {
		decalage += 26;
	}
	return debut + (((c - debut) + decalage) % 26);
}

char code(char c, int decalage) {
	if (c >= 'a' and c <= 'z') {
		return decale(c, 'a', decalage);
	}
	if (c >= 'A' and c <= 'Z') {
		return decale(c, 'A', decalage);
	}
	return c;
}

string code(string s, int decalage) {
	string res = "";
	for (int i(0); i < s.size(); ++i) {
		res = res + code(s[i], decalage);
	}
	return res;
}

string decode(string s, int decalage) {
	return code(s, -1 * decalage);
}


int main() {
	cout << code("Fuyez manants", 4) << endl;
	return 0;
}