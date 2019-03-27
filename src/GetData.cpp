#include "GetData.h"

#include <fstream>
#include <iostream>

using namespace std;

int getProfondeurTaches(string file_name)
{
	int cpt = 0;
	file_name = "../ressources/" + file_name;
	ifstream fichier (file_name, ios::in);
	string temp;

	while(getline(fichier, temp))
	{
		cpt++;
	}

	fichier.close();

	return cpt;
}

int getLargeurTaches(string file_name)
{
	int max = 0;
	int maxtmp;

	file_name = "../ressources/" + file_name;
	ifstream fichier (file_name, ios::in);
	string temp;

	while(getline(fichier, temp))
	{
		maxtmp = 1;		//Les premiers membres et seconds sont inclus
		for(int i = 0; i <= temp.length(); i++)
		{
			if(temp[i] == ' ') { maxtmp++; }
		}
		if(maxtmp > max) { max = maxtmp; }
	}

	fichier.close();
	return max;
}

void initTabTaches(int** taches, int largeur, int profondeur, string file_name)
{
	string tmp;
	int cpt;

	file_name = "../ressources/" + file_name;
	ifstream fichier (file_name, ios::in);
	string ligne;

	for (int i = 0; i < profondeur; i++)
	{
		tmp = "";
		cpt = 0;
		getline(fichier, ligne);

		for (int j = 0; j < ligne.length(); j++)
		{
			if(ligne[j] != ' ')
			{
				tmp += ligne[j];
			}
			else
			{
				taches[i][cpt] = atoi(tmp.c_str());
				cpt++;
				tmp = "";
			}
		}
		taches[i][cpt] = atoi(tmp.c_str());

		for (int j = cpt+1; j < largeur; ++j)
		{
			taches[i][j] = 0;
		}
	}
}

int getNbSommetsFromTxt(string file_name)
{	
	int cpt = 1;
	file_name = "../ressources/" + file_name;
	ifstream fichier (file_name, ios::in);

	if (fichier)
	{
		string temp;
		int i = 0;
		getline(fichier, temp);
		while(temp[i] != '\0')
		{
			i++;
			if (temp[i] == ' ')
			{
				cpt++;
			}
		}
		fichier.close();
	}
	else cerr << "Impossible d'ouvrir le fichier !";

	return cpt;
}

void initTab(int** capacite, int** flot, int nbsommets, string file_name)
{
	file_name = "../ressources/" + file_name;
	ifstream fichier (file_name, ios::in);

	if (fichier)
	{	
		string number;
		string ligne;
		int col;
		int i;

		for (int row = 0; row < nbsommets; ++row)	//Ne prend que le tableau capacité
		{
			getline(fichier, ligne);
			i = 0;
			col = 0;
			number ="";
			while (ligne[i] != '\0')
			{
				if(ligne[i] != ' ')
				{
					//cout << ligne[i] << endl;
					number = number + ligne[i];
				}
				else
				{
					//cout << number << endl;
					capacite[row][col] = atoi(number.c_str());
					//cout << number << " ";
					number = "";
					col++;
				}
				i++;
			}
			capacite[row][col] = atoi(number.c_str());
		}

		getline(fichier, ligne); //passe la ligne de tampons

		for (int row = 0; row < nbsommets; ++row)	//Ne prend que le tableau flot a la suite
		{
			getline(fichier, ligne);
			i = 0;
			col = 0;
			number ="";
			while (ligne[i] != '\0')
			{
				if(ligne[i] != ' ')
				{
					//cout << ligne[i] << endl;
					number = number + ligne[i];
				}
				else
				{
					//cout << number << endl;
					flot[row][col] = atoi(number.c_str());
					//cout << number << " ";
					number = "";
					col++;
				}
				i++;
			}
			flot[row][col] = atoi(number.c_str());
		}
	}
	else cerr << "Impossible d'ouvrir le fichier !";
}