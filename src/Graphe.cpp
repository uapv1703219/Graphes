#include "Graphe.h"
#include "GetData.h"

using namespace std;

Graphe::Graphe(string file_name)
{
	nbsommets = getNbSommets(file_name);

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
	toString();

}

void Graphe::toString()
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