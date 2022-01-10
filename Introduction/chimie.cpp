#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Flacon
{
private:
  string nom;
  double volume;
  double pH;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
    Flacon(string nom, double volume, double pH) : nom(nom), volume(volume), pH(pH) {}
    string getNom() const { return nom; }
    double getVolume() const { return volume; }
    double getPH() const { return pH; }

    ostream& etiquette(ostream& sortie) const {
        sortie << this->getNom() << " : " << this->getVolume() << " ml, pH " << this->getPH();
        return sortie;
    }

    ostream& operator<<(ostream& sortie) const {
        return this->etiquette(sortie);
    }

    const Flacon& operator+(const Flacon&) const;

    
};

const Flacon& Flacon::operator+(const Flacon& f2) const {
    Flacon* f = new Flacon(this->getNom() + " + " + f2.getNom(), this->getVolume() + f2.getVolume(), -log10((this->getVolume() * pow(10.0, -1 * this->getPH()) + f2.getVolume() * pow(10.0, -1 * f2.getPH())) / (this->getVolume() + f2.getVolume())));
    return *f;
}

ostream& operator<<(ostream& out, const Flacon& f) {
    return f.operator<<(out);
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void afficher_melange(Flacon const& f1, Flacon const& f2)
{
  cout << "Si je mélange " << endl;
  cout << "\t\"" << f1 << "\"" << endl;
  cout << "avec" << endl;
  cout << "\t\"" << f2 << "\"" << endl;
  cout << "j'obtiens :" << endl;
  cout << "\t\"" << (f1 + f2) << "\"" << endl;
}

int main()
{
  Flacon flacon1("Eau", 600.0, 7.0);
  Flacon flacon2("Acide chlorhydrique", 500.0, 2.0);
  Flacon flacon3("Acide perchlorique",  800.0, 1.5);

  afficher_melange(flacon1, flacon2);
  afficher_melange(flacon2, flacon3);

  return 0;

}
