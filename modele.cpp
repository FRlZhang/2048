#include <iostream>
#include <vector>
#include<ctime>
#include<Windows.h>
#include"modele.h"
#include<string>
using namespace std;


Plateau plateauVide() {
	Plateau tab;
	tab = vector<vector<int>>(4);
	for (int i = 0; i <= 3; i++) {
		tab[i] = vector<int>(4);
	}
	return tab;
}



//生成随机数
Plateau nombreGenerer(Plateau plateau) {
	srand((unsigned)time(0));
	int t1, t2;
	t1 = rand() % 16;
	t2 = t1 % 4;
	t1 = t1 / 4;
	while (plateau[t1][t2] != 0) {
		t1 = rand() % 16;
		t2 = t1 % 4;
		t1 = t1 / 4;
	}
	plateau[t1][t2] = tireDeuxOuQuatre();
	return plateau;
}

Plateau plateauInitial() {
	Plateau plateau;
	plateau = plateauVide();
	plateau = nombreGenerer(plateau);
	plateau = nombreGenerer(plateau);
	return plateau;
}

int tireDeuxOuQuatre() {
	int t = 0;
	srand((unsigned)time(0));
	if (rand() % 10 < 9) {
		t = 2;
	}
	else {
		t = 4;
	}
	return t;
}

Plateaupoints deplacementGauche(Plateaupoints plateau){
	for (int i = 0; i <= 3; i++) {
		for (int j = 1, k = 0; j <= 3; j++) {
			if (plateau.plateau[i][j] > 0) {
				if (plateau.plateau[i][k] == plateau.plateau[i][j]) {
					plateau.points += plateau.plateau[i][k] * 2;
					plateau.plateau[i][k] = plateau.plateau[i][k] * 2;
					plateau.plateau[i][j] = 0;
					k++;
				}
				else if (plateau.plateau[i][k] == 0) {
					plateau.plateau[i][k] = plateau.plateau[i][j];
					plateau.plateau[i][j] = 0;
				}
				else {
					plateau.plateau[i][k + 1] = plateau.plateau[i][j];
					if (j != k + 1) {
						plateau.plateau[i][j] = 0;
					}
					k++;
				}
			}
		}
	}
	return plateau;
}

Plateaupoints deplacementDroite(Plateaupoints plateau) {
	for (int i = 0; i <= 3; i++) {
		for (int j = 2, k = 3; j >= 0; j--) {
			if (plateau.plateau[i][j] > 0) {
				if (plateau.plateau[i][k] == plateau.plateau[i][j]) {
					plateau.points += plateau.plateau[i][k] * 2;
					plateau.plateau[i][k] = plateau.plateau[i][k] * 2;
					plateau.plateau[i][j] = 0;
					k--;
				}
				else if (plateau.plateau[i][k] == 0) {
					plateau.plateau[i][k] = plateau.plateau[i][j];
					plateau.plateau[i][j] = 0;
				}
				else {
					plateau.plateau[i][k - 1] = plateau.plateau[i][j];
					if (j != k - 1) {
						plateau.plateau[i][j] = 0;
					}
					k--;
				}
			}
		}
	}
	return plateau;
}

Plateaupoints deplacementHaut(Plateaupoints plateau) {
	for (int j = 0;j <= 3; j++) {
		for (int i = 1, k = 0; i <= 3; i++) {
			if (plateau.plateau[i][j] > 0) {
				if (plateau.plateau[k][j] == plateau.plateau[i][j]) {
					plateau.points += plateau.plateau[k][j] * 2;
					plateau.plateau[k][j] = plateau.plateau[k][j] * 2;
					plateau.plateau[i][j] = 0;
					k++;
				}
				else if (plateau.plateau[k][j] == 0) {
					plateau.plateau[k][j] = plateau.plateau[i][j];
					plateau.plateau[i][j] = 0;
				}
				else {
					plateau.plateau[k + 1][j] = plateau.plateau[i][j];
					if (i != k + 1) {
						plateau.plateau[i][j] = 0;
					}
					k++;
				}
			}
		}
	}
	return plateau;
}

Plateaupoints deplacementBas(Plateaupoints plateau) {
	for (int j = 0; j <= 3; j++) {
		for (int i = 2, k = 3; i >= 0; i--) {
			if (plateau.plateau[i][j] > 0) {
				if (plateau.plateau[k][j] == plateau.plateau[i][j]) {
					plateau.points += plateau.plateau[k][j] * 2;
					plateau.plateau[k][j] = plateau.plateau[k][j] * 2;
					plateau.plateau[i][j] = 0;
					k--;
				}
				else if (plateau.plateau[k][j] == 0) {
					plateau.plateau[k][j] = plateau.plateau[i][j];
					plateau.plateau[i][j] = 0;
				}
				else {
					plateau.plateau[k - 1][j] = plateau.plateau[i][j];
					if (i != k - 1) {
						plateau.plateau[i][j] = 0;
					}
					k--;
				}
			}
		}
	}
	return plateau;
}


Plateaupoints deplacement(Plateaupoints plateau, int direction) {
	if (direction == 1) {
		return deplacementGauche(plateau);
	}
	else if (direction == 2) {
		return deplacementDroite(plateau);
	}
	else if (direction == 3) {
		return deplacementHaut(plateau);
	}
	else if (direction == 4) {
		return deplacementBas(plateau);
	}
}

void dessine(Plateaupoints plateau) {
	string nombre;
	for (int i = 0; i <= 3; i++) {
		cout << "*************************" << endl;
		for (int j = 0; j <= 3; j++) {
			nombre = to_string(plateau.plateau[i][j]);
			if (plateau.plateau[i][j] == 0) {
				cout << "*     ";
			}
			else if (nombre.length() == 1) {
				cout << "*  " << nombre << "  ";
			}
			else if (nombre.length() == 2) {
				cout << "* " << nombre << "  ";
			}
			else if (nombre.length() == 3) {
				cout << "* " << nombre << " ";
			}
			else if (nombre.length() == 4) {
				cout << "*" << nombre << " ";
			}
		}
		cout << "*" << endl;
	}
	cout << "*************************" << endl;
}

bool estTermine(Plateaupoints plateau) {
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (plateau.plateau[i][j] == plateau.plateau[i][j+1]) {
				return false;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j <= 3; j++) {
			if (plateau.plateau[i][j] == plateau.plateau[i+1][j]) {
				return false;
			}
		}
	}
	return true;
}

bool estGagnant(Plateaupoints plateau) {
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			if (plateau.plateau[i][j] == 2048) {
				return true;
			}
			return false;
		}
	}
}