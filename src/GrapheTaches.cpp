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

	tot = new int[profondeur];
	tard = new int[profondeur];

	for (int i = 0; i < profondeur; ++i)
	{
		tot[i] = 0;
		tard[i] = -1;
	}
}

void GrapheTaches::getPlusTot()
{
	int pred;
	for (int current_prof = 0; current_prof < profondeur; ++current_prof)
	{
		for (int current_larg = 2; current_larg < largeur; ++current_larg)
		{
			pred = taches[current_prof][current_larg];
			if (pred != 0)
			{
				//cout << pred << " " << taches[pred - 1][1] << endl;
				if (tot[pred - 1] + taches[pred][1] > tot[current_prof])
				{
					tot[current_prof] = tot[pred - 1] + taches[pred - 1][1];
				}
			}
		}
	}
}

void GrapheTaches::getPlusTard()
{
	int pred;
	tard[profondeur-1] = tot[profondeur-1];
	for (int current_prof = profondeur - 1; current_prof >= 0; current_prof--)
	{
		for (int current_larg = 2; current_larg < largeur; ++current_larg)
		{
			pred = taches[current_prof][current_larg];
			if(pred != 0)
			{
				//cout << current_prof << " " << tard[pred - 1] << " " << tard[current_prof] - taches[pred - 1][1] << " " << tard[current_prof] << endl;
				if (tard[pred-1] == -1 || tard[pred - 1] > tard[current_prof] - taches[pred - 1][1]) { tard[pred - 1] = tard[current_prof] - taches[pred - 1][1]; }
			} 
		}
	}
}

void GrapheTaches::criticalPath()
{

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
	cout << "Tot = " << endl;
	for (int i = 0; i < profondeur; ++i)
	{
		cout << tot[i] << " ";
	}
	cout << endl;
	cout << "Tard = " << endl;
	for (int i = 0; i < profondeur; ++i)
	{
		cout << tard[i] << " ";
	}
	cout << endl;
}