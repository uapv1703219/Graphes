#include "GrapheTaches.h"
#include "GetData.h"

using namespace std;

GrapheTaches::GrapheTaches(string file_name)
{
	largeur = getLargeurTaches(file_name);
	profondeur = getProfondeurTaches(file_name);

	taches = new int*[profondeur];
	for(int i = 0; i < profondeur; ++i)
	{
    	taches[i] = new int[largeur];
	}

	initTabTaches(taches,largeur, profondeur, file_name);
}

string GrapheTaches::toString()
{
	cout << "largeur = " << largeur << endl;
	cout << "profondeur = " << profondeur << endl;
	cout << "taches =" << endl;
	for (int i = 0; i < profondeur; ++i)
	{
	 	for (int j = 0; j < largeur; ++j)
	 	{
	 		cout << taches[i][j] << " ";
	 	}
	 	cout << endl;
	}
}