#include <iostream>
#include <ctime>

// pour les nombres aléatoires
#include <random>
#include <cstring> // strlen

using namespace std;

// ======================================================================
// Couleur au hasard
std::uniform_int_distribution<int> distribution;
std::default_random_engine generateur(time(NULL)); /* NOT using std::random_device since not
                                                    * all compilers seems to support it :-( */

char tirer_couleur()
{
  static const char* const couleurs = ".RGBCYM";
  static const int nb = strlen(couleurs) - 1;

  return couleurs[distribution(generateur,
                               std::uniform_int_distribution<int>::param_type {0, nb})];
}

// ======================================================================
char poser_question()
{
  char lu(' ');
  cout << "Entrez une couleur : ";
  cin >> lu;
  return lu;
}

// ---- prototype -------------------------------------------------------
bool couleur_valide(char c);

// ======================================================================
char lire_couleur()
{
  char lu(poser_question());
  while (not couleur_valide(lu)) {
    cout << "'" << lu << "' n'est pas une couleur valide." << endl;
    cout << "Les couleurs possibles sont : ., R, G, B, C, Y ou M." << endl;
    lu = poser_question();
  }
  return lu;
}

// ======================================================================
void afficher_couleurs(char c1, char c2, char c3, char c4)
{
  cout << ' ' << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4;
}

// ======================================================================
void afficher(int nb, char c)
{
  while (nb-- > 0) {
    cout << c;
  }
}

// ---- prototype -------------------------------------------------------
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4);

// ======================================================================
void afficher_coup(char c1, char c2, char c3, char c4,
                   char r1, char r2, char r3, char r4)
{
  afficher_couleurs(c1, c2, c3, c4);
  cout << " : ";
  afficher_reponses(c1, c2, c3, c4,
                    r1, r2, r3, r4);
  cout << endl;
}

// ======================================================================
void message_gagne(int nb_coups)
{
  cout << "Bravo ! Vous avez trouvé en " << nb_coups << " coups." << endl;
}

// ======================================================================
void message_perdu(char c1, char c2, char c3, char c4)
{
  cout << "Perdu :-(" << endl;
  cout << "La bonne combinaison était : ";
  afficher_couleurs(c1, c2, c3, c4);
  cout << endl;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

// ======================================================================
bool couleur_valide(char c) {
    return ((c == '.') or (c == 'R') or (c =='B') or (c == 'Y') or (c == 'G') or (c == 'M') or (c == 'C'));
}

// ======================================================================
bool verifier(char coul1, char& coul2, int &score) {
    if (coul1 == coul2) {
        score++;
        coul2 = 'x';
        return true;
    }
    return false;
}

// ======================================================================
void apparier(char coultest, char &coul1, char &coul2, char &coul3, int &score) {
    if (! verifier(coultest, coul1, score)) {
        if (!verifier(coultest, coul2, score)) {
            verifier(coultest, coul3, score);
        }
    }
}

// ======================================================================
void afficher_reponses(char c1, char c2, char c3, char c4, char r1, char r2, char r3, char r4){
    int corrects(0);
    int malplaces(0);

    bool b1 = verifier(c1, r1, corrects);
    bool b2 = verifier(c2, r2, corrects);
    bool b3 = verifier(c3, r3, corrects);
    bool b4 = verifier(c4, r4, corrects);

    if (! b1) {
        apparier(c1, r2, r3, r4, malplaces);
    }

    if (! b2) {
        apparier(c2, r1, r3, r4, malplaces);
    }

    if (!b3) {
        apparier(c3, r1, r2, r4, malplaces);
    }

    if (!b4) {
        apparier(c4, r1, r2, r3, malplaces);
    }
    afficher(corrects, '#');
    afficher(malplaces, '+');
    afficher(4 - corrects - malplaces, '-');
}

// ======================================================================
bool gagne(char c1, char c2, char c3, char c4,
           char r1, char r2, char r3, char r4) {
    int score(0);
    verifier(c1, r1, score);
    verifier(c2, r2, score);
    verifier(c3, r3, score);
    verifier(c4, r4, score);
    return (score == 4);

}

// ======================================================================
void jouer(int max_coups = 8) {
    char c1 = tirer_couleur();
    char c2 = tirer_couleur();
    char c3 = tirer_couleur();
    char c4 = tirer_couleur();
    bool fin(false);
    int tours(0);

    do {
        char c5 = lire_couleur();
        char c6 = lire_couleur();
        char c7 = lire_couleur();
        char c8 = lire_couleur();
        afficher_coup(c5, c6, c7, c8, c1, c2, c3, c4);
        fin = gagne(c5, c6, c7, c8, c1, c2, c3, c4);
        tours++;
    } while ((tours < max_coups) and ! fin);
    if (fin) {
        message_gagne(tours);
    }
    else {
        message_perdu(c1, c2, c3, c4);
    }
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  jouer();
  return 0;
}
