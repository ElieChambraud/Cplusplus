#include <iostream>
using namespace std;

int demander_annee() {
	int annee(0);
	do {
		cout << "Entrez une annee (1583-4000) : ";
		cin >> annee;
	} while (annee < 1583 or annee > 4000);

	return annee;
}

void affiche_date(int annee, int jours) {
	char date;
	if (jours <= 31) {
		cout << "Date de Paques en " << annee << " : " << jours << " mars" << endl;
	}
	else {
		cout << "Date de Paques en " << annee << " : " << (jours - 31) << " avril" << endl;
	}

}

int date_Paques(int annee) {
	int siecle = annee / 100;
	int p = (13 + 8 * siecle) / 25;
	int q = siecle / 4;
	int M = (15 - p + siecle - q) % 30;
	int N = (4 + siecle - q) % 7;
	int d = (M + 19 * (annee % 19)) % 30;
	int e = (2 * (annee % 4) + 4 * (annee % 7) + 6 * d + N) % 7;
	
	int jour = e + d + 22;
	if (e == 6 and (d == 29 or (d == 28 and (11 * (M+1)) % 30 < 19))) {
		jour -= 7;
	}
	return jour;
}

int main() {
	int annee = demander_annee();
	affiche_date(annee, date_Paques(annee));
}