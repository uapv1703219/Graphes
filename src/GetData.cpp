#include "GetData.h"

#include <fstream>
#include <iostream>

using namespace std;

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