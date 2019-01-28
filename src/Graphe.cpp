#include "Graphe.h"
#include "GetData.h"
#include "Pile.h"

using namespace std;

Graphe::Graphe(string file_name)
{
	nbsommets = getNbSommetsFromTxt(file_name);

	capacite = new int*[nbsommets];		//Creer le tableau de capacité des arcs
	for(int i = 0; i < nbsommets; ++i)
	{
    	capacite[i] = new int[nbsommets];
	}	

	flot = new int*[nbsommets];			////Creer le tableau de flot des arcs
	for(int i = 0; i < nbsommets; ++i)
	{
    	flot[i] = new int[nbsommets];
	}
	
	initTab(capacite, flot, nbsommets, file_name);
}

void Graphe::toString() //Renvoie un string dévoilant le contenu de l'objet Graphe
{
	cout << "nbsommets = " << nbsommets << endl;
	cout << "capacite =" << endl;
	for (int i = 0; i < nbsommets; ++i)
	{
	 	for (int j = 0; j < nbsommets; ++j)
	 	{
	 		cout << capacite[i][j] << " ";
	 	}
	 	cout << endl;
	}

	cout << endl << "flot =" << endl;
	for (int i = 0; i < nbsommets; ++i)
	{
	 	for (int j = 0; j < nbsommets; ++j)
	 	{
	 		cout << flot[i][j] << " ";
	 	}
	 	cout << endl;
	}  
}

/*
Rappels c= tab capacitée, f= tab de flot, s = source, t = terminal.
*/
void Graphe::chaineAugment(int source, int terminal, int* ch)
{
	//Initialisation
	bool stop = false;
	bool visite[nbsommets];
	Pile pile;
	int i;
	for (int i = 0; i < nbsommets; ++i)
	{
		visite[i] = false;
	}
	pile.Empiler(source);
	ch[0] = source;

	//Function
	while(!pile.isEmpty() && !stop)
	{
		i = pile.Depiler();
		//cout << i;
		if(i == terminal)
		{
			stop = true;
		}
		else if(!visite[i])
		{
			visite[i] = true;
			for (int j = 0; j < nbsommets; ++j)
			{
				if(!visite[j])
				{
					if ((capacite[i][j] > 0 && capacite[i][j] > flot[i][j]) || (capacite[j][i] > 0 && flot[i][j] > 0))
					{
						pile.Empiler(j);
						ch[j] = i;
						//cout << i << endl;
					}
				}
			}
		}
	}
	/*for (int i = 0; i < nbsommets; ++i)
	{
		cout << ch[i] << endl;
	}*/
}

int Graphe::increment(int* ch, int source, int terminal)
{
	int row = ch[terminal];		//Prend la ligne du précedent
	int min = capacite[row][terminal];	//init min
	int col = row;	//la colone devient le précedent

	while(col != source)
	{
		row = ch[col];
		if(min > capacite[row][col]) {min = capacite[row][col];}
		col = row;
	}
	return min;
}

int Graphe::getNbSommets()
{
	return this->nbsommets;
}