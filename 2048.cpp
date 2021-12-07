#include<vector>
#include<iostream>
#include<stdio.h>
#include "modele.h"
using namespace std;

int main() {
	Plateaupoints plateau;
	plateau.plateau = plateauInitial();
	plateau.points = 0;
	cout << "Game Start.W=Haut,S=BAS,A=GAUCHE,D=DROIT" << endl;
	cout << "Saisir q pour quitter: " << endl;
	dessine(plateau);
	cout << "VOTRE POINTS MAINTENANT:" << plateau.points << endl;
	bool jeu = true;
	system("stty -icanon");
	while ((not estTermine(plateau)) and (not estGagnant(plateau)) and jeu == true) {
		Plateaupoints plateau0;
		plateau0 = plateau;
		char a;
		a = getchar();
		if ((a == 'w') or (a == 'W')) {
			plateau = deplacement(plateau, 3);
		}
		else if ((a == 'q') or (a == 'Q')) {
			jeu = false;
		}
		else if ((a == 'a') or (a == 'A')) {
			plateau = deplacement(plateau, 1);
		}
		else if ((a == 's') or (a == 'S')) {
			plateau = deplacement(plateau, 4);
		}
		else if ((a == 'd') or (a == 'D')) {
			plateau = deplacement(plateau, 2);
		}
		if (plateau0.plateau != plateau.plateau) {
			plateau.plateau = nombreGenerer(plateau.plateau);
			dessine(plateau);
			cout << "VOTRE POINTS MAINTENANT:" << plateau.points << endl;
		}
	}
	if (estTermine(plateau)) {
		cout << "DEFEAT" << endl;
	}
	else if (estGagnant(plateau)) {
		cout << "VICTORY" << endl;
	}
}