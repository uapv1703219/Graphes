#include "GetData.h"

#include <fstream>
#include <iostream>

using namespace std;

int getNbSommets(string file_name)
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