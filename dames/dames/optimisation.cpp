

vector<int> mvtmax(vector<vector<int>> tableau,int joueur) {
	int x = 0;
	int y = 0;
	int opti = 0;
	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 10; k++) {
			if (tableau[i][k]%2==joueur){
				if (sizeof(optimisation) > opti) {
					x = i;
					y = k;
					opti = sizeof(optimisation);
				}
			}
		}
	 }
	vector<int> meilleur = [x, y];
	return meilleur;
}

vector<vector<int>> optimisationpion(int x, int y, vector<vector<int>> tableau) {
	vector<vector<int>> chemin= [];
	int max = 0;
	
	if ((max < sizeof(optimisationpion(peutmanger(tableau, 1, 1, x, y)))) && (peutmanger(tableau, 1, 1, x, y) != [-1, -1])) {
		max = sizeof(optimisationpion(peutmanger(tableau, 1, 1, x, y)));
		chemin(0) = peutmanger(tableau, 1, 1, x, y);
	}
	if ((max < sizeof(optimisationpion(peutmanger(tableau, -1, 1, x, y))))&&(peutmanger(tableau, -1, 1, x, y)!=[-1,-1])) {
		max = sizeof(optimisationpion(peutmanger(tableau, -1, 1, x, y));
		chemin(0) = peutmanger(tableau, -1, 1, x, y);
	}
	if ((max < sizeof(optimisationpion(peutmanger(tableau, 1, -1, x, y)))) && (peutmanger(tableau, 1, -1, x, y) != [-1, -1])) {
		max = sizeof(optimisationpion(peutmanger(tableau, 1, -1, x, y));
		chemin(0) = peutmanger(tableau, 1, -1, x, y);
	}
	if ((max < sizeof(optimisationpion(peutmanger(tableau, -1, -1, x, y)))) && (peutmanger(tableau, -1, -1, x, y) != [-1, -1])) {
		max = sizeof(optimisationpion(peutmanger(tableau, 1, -1, x, y));
		chemin(0) = peutmanger(tableau, -1, -1, x, y);
	}
	if (chemin == []) { return chemin; }
	chemin.push_back(optimisationpion(x + chemin[O][O], y + chemin[O][1]));
	tableau[chemin[O][O]][chemin[O][1]] = -1;
}

vector<vector<int>> optimisation(int x, int y) {
	vector<vector<int>> chemin = [];
	int max = 0;
	if ((max < sizeof(optimisation(peutmangerdame(tableau, 1, 1, x, y)))) && (peutmangerdame(tableau, 1, 1, x, y) != [-1, -1])) {
		max = sizeof(optimisation(peutmangerdame(tableau, 1, 1, x, y)));
		chemin(0) = peutmanger(tableau, 1, 1, x, y);
	}
	if ((max < sizeof(optimisation(peutmangerdame(tableau, -1, 1, x, y)))) && (peutmangerdame(tableau, -1, 1, x, y) != [-1, -1])) {
		max = sizeof(optimisationpion(peutmangerdame(tableau, -1, 1, x, y));
		chemin(0) = peutmanger(tableau, -1, 1, x, y);
	}
	if ((max < sizeof(optimisation(peutmangerdame(tableau, 1, -1, x, y)))) && (peutmangerdame(tableau, 1, -1, x, y) != [-1, -1])) {
		max = sizeof(optimisation(peutmangerdame(tableau, 1, -1, x, y));
		chemin(0) = peutmanger(tableau, 1, -1, x, y);
	}
	if ((max < sizeof(optimisation(peutmangerdame(tableau, -1, -1, x, y)))) && (peutmangerdame(tableau, -1, -1, x, y) != [-1, -1])) {
		max = sizeof(optimisation(peutmangerdame(tableau, 1, -1, x, y));
		chemin(0) = peutmanger(tableau, -1, -1, x, y);
	}
	if (chemin == []) { return chemin; }
	chemin.push_back(optimisation(x + chemin[O][O], y + chemin[O][1]));
	tableau[chemin[O][O]][chemin[O][1]] = -1;
}

vector<int> peutmangerdame(vector<vector<int>> tableau, int directionx, int directiony, int positionx, int positiony) {
	vector<int> poscible= [-1, -1];
	int i = 0;
	int tempx = positionx;
	int tempy = positiony;
	bool rep = false;
	while ((rep == false) && (tempx >= 0) && (tempx < 10) && (tempy < 10) && (tempy >= 0)) {
		tempx += directionx;
		tempy += directiony;
		if ((tableau[tempx][tempy] != 0) and (tableau[tempx][tempy] %2 != tableau[positionx][positiony] %2 )) {
			tempx += directionx;
			tempy += directiony;
			if (tableau[tempx][tempy] == 0) {
				poscible = [tempx, tempy];
				rep = true;
			}
			else { return poscible; }
		}
		if ((tableau[tempx][tempy] != 0) and (tableau[tempx][tempy] %2 == tableau[positionx][positiony] %2 )) {
			return poscible;
		}
	}
}

vector<int> peutmanger(vector<vector<int>> tableau, int directionx, int directiony, int positionx, int positiony) {
	vector <int> = [-1, -1];
	int tempx = positionx;
	int tempy = positiony;
	if ((tableau[tempx][tempy] > 0) and (tableau[tempx][tempy] % 2 != tableau[positionx][positiony] % 2)) {
		tempx += directionx;
		tempy += directiony;
		if (tableau[tempx][tempy] == 0) {
			poscible = [tempx, tempy];
			rep = true;
		}
	}
}