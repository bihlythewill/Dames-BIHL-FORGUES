#include <vector>
#include <iostream>
using namespace std;


vector<vector<int>> initialisation(){
	vector<vector<int>> grille;
	for(int i=0; i<10; i++){
		grille.push_back(vector<int>(10));
		for(int j=0; j<10; j++){
			if((i+j)%2==1 && i<=3){
				grille[i][j] = 1;//pion noir
			}else{
				if((i+j)%2==1 && i>=6){
					grille[i][j] = 2;//pion blanc
				}else{
					grille[i][j] = 0;//vide
				}
			}
		}
	}
	return grille;
}

void affichage(vector<vector<int>> grille){
	cout<<"  |  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |"<<endl<<"-----------------------------------------------------"<<endl;
	for(int i=0; i<10; i++){
		cout<<" "<<i<<"|";
		for(int j=0; j<10; j++){
			switch (grille[i][j]){
			case 0:
				cout<<"    |";
				break;
			case 1:
				cout<<" pn |";
				break;
			case 2:
				cout<<" pb |";
				break;
			case 3:
				cout<<" dn |";
				break;
			case 4:
				cout<<" db |";
				break;
			default:
				break;
			}
		}
		cout<<endl<<"-----------------------------------------------------"<<endl;
	}
}

bool deplacement_autorise(int joueur_en_cours, vector<vector<int>> grille, int x, int y, vector<int> dests){
	bool retour=true;
	int sens=-1;//joueur en cours=1 => blancs
	int taille = dests.size();
	int compteur = 0;
	if(joueur_en_cours==0){//joueur en cours=0 => noirs
		sens=1;
	}
	if(x<0 || x>9 || y<0 || y>9){//cas pion a deplacer hors de la grille
		cout<<"origine foireuse"<<endl;
		retour = false;
	}
	if(retour && (grille[x][y]==0 || grille[x][y]%2==joueur_en_cours)){//cas mauvais pion sélectionne
		cout<<"c'est pas un de vos pions!!"<<endl;
		retour = false;
	}
	if(retour && (taille%2!=0 || taille==0)){//cas vect des dests absurde
		cout<<"qeuwah?"<<endl;
		retour=false;
	}
	for(int i=0; i<taille; i++){
		if(retour && (dests[i]<0 || dests[i]>9)){
			retour = false;
			cout<<"une case hors de la grille"<<endl;
		}
	}
	if(retour && (grille[x][y]<=2)){//cas pion
		if(taille==2){//cas simple, une seule case de dest
			bool essaie_de_marcher_sur_qqun = (grille[dests[0]][dests[1]]!=0);//si on veut se poser sur une case occupée
			bool deplace_sans_manger_correct = (dests[0]==x+sens && ( dests[1]==y+1 || dests[1]==y-1 ));//si on fait un deplacement d'une case dans chaque dir
			bool deplace_en_mangeant_correct = ((dests[0]==x+2 || dests[0]==x-2) && (dests[1]==y+2 || dests[1]==y-2) && grille[x+(dests[0]-x)/2][y+(dests[1]-y)/2])%2!=joueur_en_cours;//si on saute une piece
			if(essaie_de_marcher_sur_qqun || (!deplace_sans_manger_correct && !deplace_en_mangeant_correct)){
				retour = false;
			}
		}else{//cas plusieurs dests intermediaires
			int xprec = x;
			int yprec = y;
			while(retour && compteur<taille){
				bool essaie_de_marcher_sur_qqun = (grille[dests[compteur]][dests[compteur+1]]!=0);//si on veut se poser sur une case occupée
				bool deplace_en_mangeant_correct = ((dests[compteur]==xprec+2 || dests[compteur]==xprec-2) && (dests[compteur+1]==yprec+2 || dests[compteur+1]==yprec-2) && (grille[xprec+(dests[compteur]-xprec)/2][yprec+(dests[compteur+1]-yprec)/2]%2==joueur_en_cours));
				if(essaie_de_marcher_sur_qqun || !deplace_en_mangeant_correct){
					retour = false;
				}
				xprec = dests[compteur];
				yprec = dests[compteur+1];
				compteur=compteur+2;
			}
		}
	}else{//cas dame
		int xprec = x;
		int yprec = y;
		while(retour && compteur<taille){
			bool essaie_de_marcher_sur_qqun = (grille[dests[compteur]][dests[compteur+1]]!=0);//si on veut se poser sur une case occupée
			bool deplace_en_mangeant_correct=true;

			int i = dests[compteur]-xprec;
			int j = dests[compteur+1]-yprec;
			if(i!=j && i!=-j){
				deplace_en_mangeant_correct=false;
			}
			for(int k = min(xprec, dests[compteur]); k<max(xprec, dests[compteur])-1; k++){
				if(grille[min(xprec, dests[compteur])+k][min(yprec, dests[compteur+1])+k]!=0){
					deplace_en_mangeant_correct=false;
				}
			}

			if(essaie_de_marcher_sur_qqun || !deplace_en_mangeant_correct){
				retour = false;
			}
			xprec = dests[compteur];
			yprec = dests[compteur+1];
			compteur=compteur+2;
		}
	}
	return retour;
}