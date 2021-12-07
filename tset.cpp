#include<iostream>
#include"modele.h"
#define CHECK(test) if(!(test)) cout<< "Test failed in file "\
            <<__FILE__<<"line"<<__LINE__<<": " #test <<endl
void test_plateauVide() {
	Plateau p;
	p = plateauVide();
	Plateau t = { {0, 0, 0, 0}, { 0,0,0,0 }, { 0,0,0,0 }, { 0,0,0,0 } };
	CHECK(p == t);
}

void test_nombreGenerer() {
	Plateau p;
	int m = 0;
	p = { {0,0,0,0},{0,0,0,0},{0,0,2,0},{2,0,0,4} };
	p = nombreGenerer(p);
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			if (p[i][j] > 0) {
				m++;
			}
		}
	}
	CHECK(m == 4);
}

void test_plateauInitial() {
	Plateau p;
	int m = 0;
	p = plateauInitial();
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			if (p[i][j] > 0) {
				m++;
			}
		}
	}
	CHECK(m == 2);
}

void test_tireDeuxOuQuatre() {
	int m;
	m = tireDeuxOuQuatre();
	CHECK((m == 2) or (m == 4));
}

void test_deplacementGauche() {
	Plateaupoints p1;
	p1.points = 0;
	p1.plateau = { {2,2,4,4},{0,0,2,8},{2,4,4,2},{2,2,8,16} };
	p1 = deplacementGauche(p1);
	Plateau t = { {4, 8, 0, 0}, { 2,8,0,0 }, { 2,8,2,0 }, { 4,8,16,0 } };
	CHECK(p1.plateau == t);
	CHECK(p1.points == 24);
}

void test_deplacementDroite() {
	Plateaupoints p2;
	p2.points = 0;
	p2.plateau = { {2,2,4,4},{0,0,2,8},{2,4,4,2},{2,2,8,16} };
	p2 = deplacementDroite(p2);
	Plateau t = { {0, 0, 4, 8}, { 0,0,2,8 }, { 0,2,8,2 }, { 0,4,8,16 } };
	CHECK(p2.plateau == t);
	CHECK(p2.points == 24);
}

void test_deplacementHaut() {
	Plateaupoints p3;
	p3.points = 0;
	p3.plateau = { {2,2,4,4},{0,0,2,8},{2,4,4,2},{2,2,8,16} };
	p3 = deplacementHaut(p3);
	Plateau t = { {4, 2, 4, 4}, { 2,4,2,8 }, { 0,2,4,2 }, { 0,0,8,16 } };
	CHECK(p3.plateau == t);
	CHECK(p3.points == 4);
}

void test_deplacementBas() {
	Plateaupoints p4;
	p4.points = 0;
	p4.plateau = { {2,0,4,4},{4,4,0,4},{16,4,8,8},{2,4,8,16} };
	p4 = deplacementBas(p4);
	Plateau t = { {2, 0, 0, 0 }, { 4,0,0,8 }, { 16,4,4,8 }, { 2,8,16,16 } };
	CHECK(p4.plateau == t);
	CHECK(p4.points == 32);
}

void test_deplacement() {
	Plateaupoints p;
	p.points = 0;
	p.plateau = { {2,2,4,4},{0,0,2,8},{2,4,4,2},{2,2,8,16} };
	p = deplacement(p, 1);
	Plateau t = { {4, 8, 0, 0}, { 2,8,0,0 }, { 2,8,2,0 }, { 4,8,16,0 } };
	CHECK(p.plateau == t);
	CHECK(p.points == 24);
}

void test_estTermine() {
	Plateaupoints p;
	p.points = 0;
	p.plateau = { {2,4,8,16},{4,8,16,32},{8,16,32,64},{16,32,64,2} };
	CHECK(estTermine(p));
}

void test_estGagnant() {
	Plateaupoints p;
	p.points = 0;
	p.plateau = { {0,0,0,0},{0,0,2048,0},{0,0,0,0},{0,0,0,0} };
	CHECK(estGagnant(p));
}

int main() {
	test_nombreGenerer();
	test_nombreGenerer();
	test_plateauInitial();
	test_tireDeuxOuQuatre();
	test_deplacementGauche();
	test_deplacementDroite();
	test_deplacementHaut();
	test_deplacementBas();
	test_deplacement();
	test_estTermine();
	test_estGagnant();
}
