#include <vector>
using namespace std;



vector<int> peutmanger(vector<vector<int>> tableau, int directionx, int directiony, int positionx, int positiony) {
	vector <int> poscible(2, -1);
	int tempx = positionx;
	int tempy = positiony;
	if ((tableau[tempx][tempy] > 0) && (tableau[tempx][tempy] % 2 != tableau[positionx][positiony] % 2)) {
		tempx += directionx;
		tempy += directiony;
		if (tableau[tempx][tempy] == 0) {
			poscible[0] = tempx;
			poscible[1] = tempy;
			bool rep = true;
		}
	}
	return poscible;
}

vector<vector<int>> optimisationpion(int x, int y, vector<vector<int>> tableau) {
	vector<vector<int>> chemin;
	vector<int> poscible(2, -1);
	unsigned int max = 0;
	
	if ((max < (optimisationpion(peutmanger(tableau, 1, 1, x, y)[0], peutmanger(tableau, 1, 1, x, y)[1], tableau)).size()) && (peutmanger(tableau, 1, 1, x, y) != poscible)) {
		max = (optimisationpion(peutmanger(tableau, 1, 1, x, y)[0], peutmanger(tableau, 1, 1, x, y)[1], tableau)).size();
		chemin[0] = peutmanger(tableau, 1, 1, x, y);
	}
	if ((max < (optimisationpion(peutmanger(tableau, -1, 1, x, y)[0], peutmanger(tableau, -1, 1, x, y)[1], tableau)).size())&&(peutmanger(tableau, -1, 1, x, y)!=poscible)) {
		max = (optimisationpion(peutmanger(tableau, -1, 1, x, y)[0], peutmanger(tableau, -1, 1, x, y)[1], tableau)).size();
		chemin[0] = peutmanger(tableau, -1, 1, x, y);
	}
	if ((max < (optimisationpion(peutmanger(tableau, 1, -1, x, y)[0], peutmanger(tableau, 1, -1, x, y)[1], tableau)).size()) && (peutmanger(tableau, 1, -1, x, y) != poscible)) {
		max = (optimisationpion(peutmanger(tableau, 1, -1, x, y)[0], peutmanger(tableau, 1, -1, x, y)[1], tableau)).size();
		chemin[0] = peutmanger(tableau, 1, -1, x, y);
	}
	if ((max < (optimisationpion(peutmanger(tableau, -1, -1, x, y)[0], peutmanger(tableau, -1, -1, x, y)[1], tableau)).size()) && (peutmanger(tableau, -1, -1, x, y) != poscible)) {
		max = (optimisationpion(peutmanger(tableau, -1, -1, x, y)[0], peutmanger(tableau, -1, -1, x, y)[1], tableau)).size();
		chemin[0] = peutmanger(tableau, -1, -1, x, y);
	}
	if (chemin.size()==0) { return chemin; }
	vector<vector<int>> a = optimisationpion(x + chemin[0][0], y + chemin[0][1], tableau);
	chemin.insert(chemin.end(), a.begin(), a.end());
	tableau[chemin[0][0]][chemin[0][1]] = -1;
	return chemin;
}

vector<int> peutmangerdame(vector<vector<int>> tableau, int directionx, int directiony, int positionx, int positiony) {
	vector<int> poscible(2, -1);
	int i = 0;
	int tempx = positionx;
	int tempy = positiony;
	bool rep = false;
	while ((rep == false) && (tempx >= 0) && (tempx < 10) && (tempy < 10) && (tempy >= 0)) {
		tempx += directionx;
		tempy += directiony;
		if ((tableau[tempx][tempy] != 0) && (tableau[tempx][tempy] %2 != tableau[positionx][positiony] %2 )) {
			tempx += directionx;
			tempy += directiony;
			if (tableau[tempx][tempy] == 0) {
				poscible[0] = tempx;
				poscible[1] = tempy;
				rep = true;
			}
			else { return poscible; }
		}
		if ((tableau[tempx][tempy] != 0) && (tableau[tempx][tempy] %2 == tableau[positionx][positiony] %2 )) {
			return poscible;
		}
	}
}

vector<vector<int>> optimisation(int x, int y, vector<vector<int>> tableau) {
	vector<vector<int>> chemin;
	vector<int> poscible(2, -1);
	unsigned int max = 0;
	if ((max < (optimisation(peutmangerdame(tableau, 1, 1, x, y)[0], peutmangerdame(tableau, 1, 1, x, y)[1], tableau)).size()) && (peutmangerdame(tableau, 1, 1, x, y) != poscible)) {
		max = (optimisation(peutmangerdame(tableau, 1, 1, x, y)[0], peutmangerdame(tableau, 1, 1, x, y)[1], tableau)).size();
		chemin[0] = peutmanger(tableau, 1, 1, x, y);
	}
	if ((max < (optimisation(peutmangerdame(tableau, -1, 1, x, y)[0], peutmangerdame(tableau, -1, 1, x, y)[1], tableau)).size()) && (peutmangerdame(tableau, -1, 1, x, y) != poscible)) {
		max = (optimisationpion(peutmangerdame(tableau, -1, 1, x, y)[0], peutmangerdame(tableau, -1, 1, x, y)[1], tableau)).size();
		chemin[0] = peutmanger(tableau, -1, 1, x, y);
	}
	if ((max < (optimisation(peutmangerdame(tableau, 1, -1, x, y)[0], peutmangerdame(tableau, 1, -1, x, y)[1], tableau)).size()) && (peutmangerdame(tableau, 1, -1, x, y) != poscible)) {
		max = (optimisation(peutmangerdame(tableau, 1, -1, x, y)[0], peutmangerdame(tableau, 1, -1, x, y)[1], tableau)).size();
		chemin[0] = peutmanger(tableau, 1, -1, x, y);
	}
	if ((max < (optimisation(peutmangerdame(tableau, -1, -1, x, y)[0], peutmangerdame(tableau, -1, -1, x, y)[1], tableau)).size()) && (peutmangerdame(tableau, -1, -1, x, y) != poscible)) {
		max = (optimisation(peutmangerdame(tableau, -1, -1, x, y)[0], peutmangerdame(tableau, -1, -1, x, y)[1], tableau)).size();
		chemin[0] = peutmanger(tableau, -1, -1, x, y);
	}
	if (chemin.size()==0) { return chemin; }
	vector<vector<int>> a = optimisation(x + chemin[0][0], y + chemin[0][1], tableau);
	chemin.insert(chemin.end(), a.begin(), a.end());
	tableau[chemin[0][0]][chemin[0][1]] = -1;
	return chemin;
}



vector<int> mvtmax(vector<vector<int>> tableau,int joueur) {
	int x = 0;
	int y = 0;
	unsigned int opti = 0;
	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 10; k++) {
			if (tableau[i][k]%2==joueur){
				if (optimisation(i, k, tableau).size() > opti) {
					x = i;
					y = k;
					opti = optimisation(i, k, tableau).size();
				}
			}
		}
	 }
	vector<int> meilleur;
	meilleur.push_back(x);
	meilleur.push_back(y);
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(tableau[i][j]==-1){
				tableau[i][j]=0;
			}
		}
	}
	return meilleur;
}