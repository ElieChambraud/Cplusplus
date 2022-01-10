#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/
// Chaines de caractères à utiliser pour les affichages:
/*

été jeté

d'un

n'est

L'oeuvre

bibliothèque

détruit

*/

class Auteur {

private :

    string nom;
    bool prime;

public :
    Auteur(string nom, bool prime = false) : nom(nom), prime(prime) {}
    Auteur(Auteur const&) = delete;
    string getNom() const { return nom; }
    bool getPrix() const { return prime; }

};

class Oeuvre {

private:

    string titre;
    class Auteur const& auteur;
    string langue;

public:
    Oeuvre(string titre, class Auteur const& auteur, string langue) : titre(titre), auteur(auteur), langue(langue) {}
    Oeuvre(Oeuvre const&) = delete;
    string getTitre() const { return titre; }
    class Auteur const& getAuteur() const { return auteur; }
    string getLangue() const { return langue; }
    void affiche() {
        cout << titre << ", " << auteur.getNom() << ", en " << langue;
    }
    ~Oeuvre(){
        cout << "L'oeuvre \"" << titre << ", " << auteur.getNom() << ", en " << langue << "\" n'est plus disponible." << endl;
    }
};

class Exemplaire {

private:

    class Oeuvre& oeuvre;

public:

    Exemplaire(class Oeuvre& oeuvre) : oeuvre(oeuvre) {
        cout << "Nouvel exemplaire de : " << oeuvre.getTitre() << ", " << oeuvre.getAuteur().getNom() << ", en " << oeuvre.getLangue() << endl;
    }

    Exemplaire(class Exemplaire const& orig) : oeuvre(orig.oeuvre) {
        cout << "Copie d'un exemplaire de : " << oeuvre.getTitre() << ", " << oeuvre.getAuteur().getNom() << " en " << oeuvre.getLangue() << endl;
    }

    ~Exemplaire() {
        cout << "Un exemplaire de \"" << oeuvre.getTitre() << ", " << oeuvre.getAuteur().getNom() << ", en " << oeuvre.getLangue() << "\" a été jeté !" << endl;
    }

    class Oeuvre& getOeuvre() const { return oeuvre; }

    void affiche(){
        cout << "Exemplaire de : " << oeuvre.getTitre() << ", " << oeuvre.getAuteur().getNom() << ", en " << oeuvre.getLangue();
    }
};

class Bibliotheque {

private:

    string nom;
    vector< class Exemplaire*> exemplaires;

public:

    Bibliotheque(string nom) : nom(nom), exemplaires({}) {
        cout << "La bibliothèque " << nom << " est ouverte !" << endl;
    }

    Bibliotheque(string nom, vector< class Exemplaire*> exemplaires) : nom(nom), exemplaires(exemplaires) {
        cout << "La bibliothèque " << nom << " est ouverte !" << endl;
    }

    string getNom() const { return nom; }

    void stocker(class Oeuvre& oeuvre, int n = 1) {
        while (n > 0) {
            class Exemplaire* ex = new Exemplaire(oeuvre);
            exemplaires.push_back(ex);
            --n;
        }
    }
    void lister_exemplaires(string langue = "") {
        for (auto elt : exemplaires) {
            if (langue == "") {
                elt->affiche();
                cout << endl;
            }
            else {
                if (elt->getOeuvre().getLangue() == langue) {
                    elt->affiche();
                    cout << endl;
                }
            }
        }
    }

    int compter_exemplaires(class Oeuvre& oeuvre) {
        int compteur(0);
        for (auto elt : exemplaires) {
            if (oeuvre.getTitre() == elt->getOeuvre().getTitre()) {
                compteur++;
            }
        }
        return compteur;
    }

    void afficher_auteurs(bool prises = false) {
        for (auto elt : exemplaires) {
            if (prises) {
                if (elt->getOeuvre().getAuteur().getPrix()) {
                    cout << elt->getOeuvre().getAuteur().getNom() << endl;
                }
            }
            else {
                cout << elt->getOeuvre().getAuteur().getNom() << endl;
            }
        }
    }

    ~Bibliotheque() {
        cout << "La bibliothèque " << nom << " ferme ses portes," << endl;
        cout << "et détruit ses exemplaires :" << endl;
        for (auto elt : exemplaires) {
            delete elt;
        }
    }
};


/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/

int main()
{
  Auteur a1("Victor Hugo"),
         a2("Alexandre Dumas"),
         a3("Raymond Queneau", true);

  Oeuvre o1("Les Misérables"           , a1, "français" ),
         o2("L'Homme qui rit"          , a1, "français" ),
         o3("Le Comte de Monte-Cristo" , a2, "français" ),
         o4("Zazie dans le métro"      , a3, "français" ),
         o5("The Count of Monte-Cristo", a2, "anglais" );

  Bibliotheque biblio("municipale");
  biblio.stocker(o1, 2);
  biblio.stocker(o2);
  biblio.stocker(o3, 3);
  biblio.stocker(o4);
  biblio.stocker(o5);

  cout << "La bibliothèque " << biblio.getNom()
       << " offre les exemplaires suivants :" << endl;
  biblio.lister_exemplaires();

  const string langue("anglais");
  cout << " Les exemplaires en "<< langue << " sont :" << endl;
  biblio.lister_exemplaires(langue);

  cout << " Les auteurs à succès sont :" << endl;
  biblio.afficher_auteurs(true);

  cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
       << o3.getTitre() << endl;

  return 0;
}
