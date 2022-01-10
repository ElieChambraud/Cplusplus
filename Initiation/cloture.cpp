#include <iostream>
#include <vector>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/

typedef vector< vector <int> > Carte;

struct Position {
    int i;
    int j;
};

bool binaire(Carte const& carte) {
    for (auto ligne : carte) {
        for (auto elt : ligne) {
            if ((elt != 0) and (elt != 1)) {
                return false;
            }
        }
    }
    return true;
}

void affiche(Carte const& carte) {
    for (auto ligne : carte) {
        for (auto elt : ligne) {

            cout << elt;
        }
        cout << endl;
    }
    cout << "----" << endl;
}

bool verifie_etang(Carte const& carte, struct Position coord) {
    vector<int> ligne = carte[coord.i];
    bool drap1(false);
    bool drap2(false);
    for (int iter(coord.j); iter >= 0; --iter) {
        if (ligne[iter] == 1) {
            drap1 = true;
        }
    }
    for (int iter(coord.j); iter < ligne.size(); ++iter) {
        if (ligne[iter] == 1) {
            drap2 = true;
        }
    }
    return (drap1 and drap2);
}

bool verifie_et_modifie(Carte& carte) {
    if (!binaire(carte)) {
        cout << "Votre carte du terrain ne contient pas que des 0 et des 1." << endl;
        return false;
    }
    for (int i(0); i < carte.size(); ++i) {
        for (int j(0); j < carte[0].size(); ++j) {
            if (carte[i][j] == 0) {
                struct Position coord({ i,j });
                if (verifie_etang(carte, coord)) {
                    carte[i][j] = 1;
                }
            }
        }
    }
    return true;
}

int cloture(Carte const& carte, struct Position coord) {
    int c(0);
    if (coord.i == 0) {
        if (coord.j == 0) {
            if (carte[coord.i][coord.j + 1] == 0) {
                c++;
            }
            if (carte[coord.i + 1][coord.j] == 0) {
                c++;
            }
        }
        else if (coord.j == carte[0].size() - 1) {
            if (carte[coord.i][coord.j - 1] == 0) {
                c++;
            }
            if (carte[coord.i + 1][coord.j] == 0) {
                c++;
            }
        }
        else {
            if (carte[coord.i][coord.j - 1] == 0) {
                c++;
            }
            if (carte[coord.i + 1][coord.j] == 0) {
                c++;
            }
            if (carte[coord.i][coord.j + 1] == 0) {
                c++;
            }
        }
    }
    else if (coord.i == carte.size() - 1) {
        if (coord.j == 0) {
            if (carte[coord.i][coord.j + 1] == 0) {
                c++;
            }
            if (carte[coord.i - 1][coord.j] == 0) {
                c++;
            }
        }
        else if (coord.j == carte[0].size() - 1) {
            if (carte[coord.i][coord.j - 1] == 0) {
                c++;
            }
            if (carte[coord.i - 1][coord.j] == 0) {
                c++;
            }
        }
        else {
            if (carte[coord.i][coord.j - 1] == 0) {
                c++;
            }
            if (carte[coord.i - 1][coord.j] == 0) {
                c++;
            }
            if (carte[coord.i][coord.j + 1] == 0) {
                c++;
            }
        }
    }
    else if (coord.j == 0) {
        if (carte[coord.i - 1][coord.j] == 0) {
            c++;
        }
        if (carte[coord.i][coord.j + 1] == 0) {
            c++;
        }
        if (carte[coord.i + 1][coord.j] == 0) {
            c++;
        }
    }
    else if (coord.j == carte[0].size() - 1) {
        if (carte[coord.i - 1][coord.j] == 0) {
            c++;
        }
        if (carte[coord.i][coord.j - 1] == 0) {
            c++;
        }
        if (carte[coord.i + 1][coord.j] == 0) {
            c++;
        }
    }
    else {
        if (carte[coord.i - 1][coord.j] == 0) {
            c++;
        }
        if (carte[coord.i][coord.j - 1] == 0) {
            c++;
        }
        if (carte[coord.i][coord.j + 1] == 0) {
            c++;
        }
        if (carte[coord.i + 1][coord.j] == 0) {
            c++;
        }
    }
    return c;
}

double longueur_cloture(Carte& carte, double echelle = 2.5) {
    double longueur(0.0);
    if (carte.size() != 1) {
        for (int i(0); i < carte.size(); ++i) {
            for (int j(0); j < carte[0].size(); ++j) {
                if (carte[i][j] == 1) {
                    struct Position coord({ i,j });
                    longueur += cloture(carte, coord) * echelle;

                }
            }
        }
    }
    
    for (int i(0); i < carte.size(); ++i) {
        if (carte[i][0] == 1) {
            longueur += echelle;
        }
        if (carte[i][carte[0].size() - 1] == 1) {
            longueur += echelle;
        }
    }

    for (int j(0); j < carte[0].size(); ++j) {
        if (carte[0][j] == 1) {
            longueur += echelle;
        }
        if (carte[carte.size() - 1][j] == 1) {
            longueur += echelle;
        }
    }
    return longueur;
}

void ajoute_unique(vector<int>& ensemble, int valeur)
{
}
bool convexite_lignes(Carte& carte, vector<int> const& labels_bords)
{
    return true;
}
bool convexite_lignes(Carte& carte)
{
    return true;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Carte carte = {
      {0,1,1,1,1,0,0,0},
      {0,1,1,1,0,0,0,0},
      {1,1,1,1,1,1,0,0},
      {1,1,1,1,1,1,1,0},
      {0,0,1,1,1,1,1,0},
      {1,1,1,1,1,1,1,0},
      {0,1,1,1,1,1,0,0},
      {0,1,1,1,1,0,0,0},
      {1,1,1,1,1,0,0,0},
      {1,1,1,1,1,0,0,0}
  };

  cout << "Carte au départ :" << endl;
  affiche(carte);
  if (verifie_et_modifie(carte)) {
    cout << "Carte après modification :" << endl;
    affiche(carte);
    cout << "Il vous faut " << longueur_cloture(carte)
         << " mètres de clôture pour votre terrain."
         << endl;
  }

  return 0;
}
