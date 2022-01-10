#include <iostream>
using namespace std;

int main()
{
  cout << "Donnez l'heure de début de la location (un entier) : ";
  int debut;
  cin >> debut;

  cout << "Donnez l'heure de fin de la location (un entier) : ";
  int fin;
  cin >> fin;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/

  int duree1(0), duree2(0);

  if ((debut < 0) or (debut > 24) or (fin < 0) or (fin > 24)) {
      cout << "Les heures doivent être comprises entre 0 et 24 !" << endl;
  }
  else {
      if (debut == fin) {
          cout << "Bizarre, vous n'avez pas loué votre vélo bien longtemps !" << endl;
      }
      else {
          if (debut > fin) {
              cout << "Bizarre, le début de la location est après la fin ..." << endl;
          }
          else {
              if (debut <= 7) {
                  if (fin <= 7) {
                      duree1 = fin - debut;
                      duree2 = 0;
                  }
                  else {
                      if (fin <= 17) {
                          duree2 = fin - 7;
                          duree1 = 7 - debut;
                      }
                      else {
                          if (fin <= 24) {
                              duree2 = 10;
                              duree1 = (7 - debut) + (fin - 17);
                          }
                      }

                  }
              }
              else {
                  if (debut <= 17) {
                      if (fin <= 17) {
                          duree2 = fin - debut;
                          duree1 = 0;
                      }
                      else {
                          duree1 = fin - 17;
                          duree2 = 17 - debut;
                      }
                  }
                  else {
                      duree1 = fin - debut;
                      duree2 = 0;
                  }
              }

              cout << "Vous avez loué votre vélo pendant" << endl;

              if (duree1 != 0) {
                  cout << duree1 << " heure(s) au tarif horaire de " << 1 << " franc(s)" << endl;
              }
              if (duree2 != 0) {
                  cout << duree2 << " heure(s) au tarif horaire de " << 2 << " franc(s)" << endl;
              }
              cout << "Le montant total à payer est de " << duree1 + (2 * duree2) << " franc(s)." << endl;
          }
      }
  }


  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
