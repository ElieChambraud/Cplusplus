#include <iostream>
#include <vector>
using namespace std;

int somme_consecutifs_max(vector<int> tab) {
	int max(0);
	int buff(0);
	for (auto elt : tab) {
		if (elt == 0) {
			max = 0;
		}
		else {
			max += elt;
			if (max > buff) {
				buff = max;
			}
		}
	}
	return buff;
}

vector<size_t> lignes_max(vector< vector<int> > tab) {
	int max(0);
	int tmp;
	vector<size_t> res;
	for (auto elt : tab) {
		tmp = somme_consecutifs_max(elt);
		if (max < tmp) {
			max = tmp;
		}
	}

	for (int i(0); i < tab.size(); ++i) {
		if (somme_consecutifs_max(tab[i]) == max) {
			res.push_back(i);
		}
	}
	return res;
}

vector< vector <int> > tranches_max(vector <vector <int> > tab) {
	vector< vector <int> > res;
	vector<size_t> l(lignes_max(tab));
	for (auto elt : l) {
		res.push_back(tab[elt]);
	}
	return res;
}

int main() {
	return 0;
}