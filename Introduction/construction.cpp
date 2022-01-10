#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Pour simplifier
typedef string Forme   ;
typedef string Couleur ;

class Brique
{
private:
  Forme   forme   ;
  Couleur couleur ;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
    Forme getForme() const { return forme; }
    Couleur getCouleur() const { return couleur; }

    Brique(Forme forme, Couleur couleur) : forme(forme), couleur(couleur) {}

    ostream& afficher(ostream& sortie) const {
        if (this->couleur != "") {
            sortie << "(" << this->getForme() << ", " << this->getCouleur() << ")";
            return sortie;
        }
        else {
            sortie << this->getForme();
            return sortie;
        }
    }

    ostream& operator<<(ostream& sortie) const {
        return this->afficher(sortie);
    }
};

class Construction
{
  friend class Grader;
  vector< vector< vector< Brique> > > contenu;

public:

    Construction(Brique brique) : contenu({ {{brique}} }) {}

    ostream& afficher(ostream& sortie) const {
        vector< vector< vector< Brique> > > vect= this->contenu;
        int c(0);
        for (auto i : vect) {
            c++;
            cout << "Couche numéro : " << c << endl;
            for (auto j : i) {
                for (auto k : j) {
                    k.afficher(sortie);
                }
            }
        }
    }

    ostream& operator<<(ostream& sortie) const {
        return this->afficher(sortie);
    }

private:
    const Construction& operator^=(const Construction) const {
        Construction *c = 
        return *f;
    }


};

const Construction operator*(unsigned int n, Construction const& a)
{
}

const Construction operator/(unsigned int n, Construction const& a)
{
}

const Construction operator%(unsigned int n, Construction const& a)
{
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  // Modèles de briques
  Brique toitD("obliqueD", "rouge");
  Brique toitG("obliqueG", "rouge");
  Brique toitM(" pleine ", "rouge");
  Brique mur  (" pleine ", "blanc");
  Brique vide ("                 ", "");

  unsigned int largeur(4);
  unsigned int profondeur(3);
  unsigned int hauteur(3); // sans le toit

  // on construit les murs
  Construction maison( hauteur / ( profondeur % (largeur * mur) ) );

  // on construit le toit
  Construction toit(profondeur % ( toitG + 2*toitM + toitD ));
  toit ^= profondeur % (vide + toitG + toitD);

  // on pose le toit sur les murs
  maison ^= toit;

  // on admire notre construction
  cout << maison << endl;

  return 0;
}
