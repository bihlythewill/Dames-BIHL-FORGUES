#include "utils.h"
#include <iostream>
#include <gtest/gtest.h>
using namespace std;

/*int main(){

	vector<vector<int>> grille = initialisation();
	affichage(grille);
	int i;
	cin>>i;
	return 0;
}*/

/*class MouvPion : public :: testing :: Test {
	protected :
	virtual void SetUp () {
		grille = initialisation();
		grille[4][7] = 2;
		grille[7][6] = 0;
		grille[9][8] = 1;
		dests.push_back(4);
		dests.push_back(3);
		dests3.push_back(11);
		dests3.push_back(3);
		dests4.push_back(5);
		dests4.push_back(8);
		dests4.push_back(7);
		dests4.push_back(6);
		dests5.push_back(7);
		dests5.push_back(6);
		dests5.push_back(5);
		dests5.push_back(4);
	}
	virtual void TearDown () {
		//
	}
	vector<vector<int>> grille;
	vector<int> dests;
	vector<int> dests2;
	vector<int> dests3;
	vector<int> dests4;
	vector<int> dests5;

};

TEST_F ( MouvPion , RemplissageInitial ) {
	affichage(grille);
EXPECT_EQ (1 , grille[2][5]);
EXPECT_EQ (0 , grille[2][6]);
EXPECT_EQ (false , deplacement_autorise(0, grille, 3, -1, dests));//test origine hors de la grille
EXPECT_EQ (false , deplacement_autorise(0, grille, 3, 1, dests));//test avec case vide
EXPECT_EQ (false , deplacement_autorise(0, grille, 7, 2, dests));//test avec pion de l'adversaire
EXPECT_EQ (false , deplacement_autorise(0, grille, 3, 2, dests2));//test avec vec des dests vide
EXPECT_EQ (false , deplacement_autorise(0, grille, 3, 2, dests3));//test dest hors de la grille
EXPECT_EQ (true , deplacement_autorise(0, grille, 3, 2, dests));//test depl autorise vers gauche
EXPECT_EQ (true , deplacement_autorise(0, grille, 3, 4, dests));//test depl autorise vers droite
EXPECT_EQ (false , deplacement_autorise(0, grille, 3, 6, dests));//test depl non autorise
EXPECT_EQ (true , deplacement_autorise(0, grille, 3, 6, dests4));//test depl autorise avec 2 mangeages
EXPECT_EQ (true , deplacement_autorise(0, grille, 9, 8, dests5));//test depl autorise avec 2 mangeages en arriere
}*/

class MouvDame : public :: testing :: Test {
	protected :
	virtual void SetUp () {
		grille = initialisation();
		grille[3][4] = 3;
		grille[5][6] = 2;
		grille[6][7] = 0;
		grille[7][8] = 0;
		dests.push_back(6);
		dests.push_back(7);
	}
	virtual void TearDown () {
		//
	}
	vector<vector<int>> grille;
	vector<int> dests;
};

TEST_F ( MouvDame , RemplissageInitial ) {
	affichage(grille);
EXPECT_EQ (true , deplacement_autorise(0, grille, 3, 4, dests));//test origine hors de la grille

}