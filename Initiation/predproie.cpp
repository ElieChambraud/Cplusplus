#include <iostream>
#include <iomanip> // pour setprecision()
using namespace std;

int main()
{
  // Réduire le format d'affichage
  cout << setprecision(4);

  // Paramètres
  double taux_croissance_lapins(0.3);
  double taux_attaque(0.01);
  double taux_croissance_renards(0.008);
  double taux_mortalite(0.1);
  int duree(50);

  double renards_i(0.0);
  double lapins_i(0.0);

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/

  // ===== PARTIE 1 =====
  // Saisie des populations initiales
  double renards(0.0);
  do {
	  cout << "Combien de renards au départ (>= 2) ? ";
	  cin >> renards;
  } while (renards < 2);

  double lapins(0.0);
  do {
	  cout << "Combien de lapins au départ  (>= 5) ? ";
	  cin >> lapins;
  } while (lapins < 5);


  // ===== PARTIE 2 =====
  // Première simulation
  cout <<  endl << "***** Le taux d'attaque vaut "<< taux_attaque * 100 << "%" <<  endl;

  renards_i = renards;
  lapins_i = lapins;
  for (int i(0); i < duree; ++i) {
	  double tmp(lapins_i);
	  lapins_i *= (1.0 + taux_croissance_lapins - taux_attaque * renards_i);
	  renards_i *= (1.0 + taux_attaque * tmp * taux_croissance_renards - taux_mortalite);
	  if (lapins_i < 0) {
		  lapins_i = 0;
	  }
	  if (renards_i < 0) {
		  renards_i = 0;
	  }
	  cout << "Après " << i+1 << " mois, il y a " << lapins_i << " lapins et " << renards_i << " renards" << endl;
  }



  // ===== PARTIE 3 =====
  // Variation du taux d'attaque
  

  double taux_attaque_depart(0.0);
  double taux_attaque_fin(0.0);

  do {
	  cout << "taux d’attaque au départ en % (entre 0.5 et 6) ? ";
	  cin >> taux_attaque_depart;
  } while ((taux_attaque_depart < 0.5) or (taux_attaque_depart > 6));

  do {
	  cout << "taux d’attaque à la fin en % (entre " << taux_attaque_depart << " et 6) ? ";
	  cin >> taux_attaque_fin;
  } while ((taux_attaque_fin < taux_attaque_depart) or (taux_attaque_fin > 6));






  do {
	  taux_attaque = taux_attaque_depart/100;
	  ++taux_attaque_depart;
	  bool extinction_renards(false);
	  bool extinction_lapins(false);
	  bool retour_renards(false);
	  bool retour_lapins(false);
	  bool stable(true);
	  bool disparition_renards(false);
	  bool disparition_lapins(false);
	  int i(0);

	  cout << endl;
	  cout << endl << "***** Le taux d'attaque vaut " << taux_attaque * 100 << "%" << endl;
	  lapins_i = lapins;
	  renards_i = renards;
	  while ((i < duree) and ((renards_i != 0) or (lapins_i != 0))) {
		  ++i;
		  double tmp(lapins_i);
		  lapins_i *= (1.0 + taux_croissance_lapins - taux_attaque * renards_i);
		  renards_i *= (1.0 + taux_attaque * tmp * taux_croissance_renards - taux_mortalite);
		  if (not(extinction_lapins) and (lapins_i < 5)) {
			  extinction_lapins = true;
			  stable = false;
		  }
		  if (not(retour_lapins) and extinction_lapins and (lapins_i >= 5)) {
			  retour_lapins = true;
			  stable = false;
		  }
		  if (not(extinction_renards) and (renards_i < 5)) {
			  extinction_renards = true;
			  stable = false;
		  }
		  if (not(retour_renards) and extinction_renards and (renards_i >= 5)) {
			  retour_renards = true;
			  stable = false;
		  }
		  if ((lapins_i < 2) and not(disparition_lapins)) {
			  disparition_lapins = true;
			  lapins_i = 0;
			  stable = false;
		  }
		  if ((renards_i < 2) and not(disparition_renards)) {
			  disparition_renards = true;
			  renards_i = 0;
			  stable = false;
		  }

	  }
	  cout << "Après " << i << " mois, il y a " << lapins_i << " lapins et " << renards_i << " renards" << endl;
	  if (extinction_lapins) {
		  cout << "Les lapins ont été en voie d'extinction" << endl;
	  }
	  if (retour_lapins) {
		  cout << "mais la population est remontée ! Ouf !" << endl;
	  }
	  if (disparition_lapins) {
		  cout << "et les lapins ont disparu :-(" << endl;
	  }
	  if (extinction_renards) {
		  cout << "Les renards ont été en voie d'extinction" << endl;
	  }
	  if (retour_renards) {
		  cout << "mais la population est remontée ! Ouf !" << endl;
	  }
	  if (disparition_renards) {
		  cout << "et les renards ont disparu :-(" << endl;
	  }
	  if (stable) {
		  cout << "Les lapins et les renards ont des populations stables." << endl;
	  }

  } while (taux_attaque_depart < taux_attaque_fin);



  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
