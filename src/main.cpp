#include <string>

#include "Graphe.h"
#include "GetData.h"

using namespace std;

int main(int argc, char const *argv[])
{
	Graphe graphe = Graphe("graphe.txt");
	int pere[graphe.getNbSommets()];
	graphe.MooreDijkstra(0, pere);
	for (int i = 0; i < graphe.getNbSommets(); ++i)		//Affichage chaine augmentante
	{
		cout << "pere[" <<  i << "] = " << pere[i] << endl;
	}
	graphe.displayShortestPaths(pere);









	/*----------------TP1-------------------------*/
	// //graphe.toString();
	// int ch[graphe.getNbSommets()];
	// graphe.chaineAugment(0, 5, ch);

/*	for (int i = 0; i < graphe.getNbSommets(); ++i)		//Affichage chaine augmentante
	{
		cout << "ch[" <<  i << "] = " << ch[i] << endl;
	}*/

	// cout << "Max augment = " << graphe.increment(0, 5, ch) << endl;


	/*cout << "flot max = " << graphe.flotMax(0, 3) << endl;
	graphe.toString();*/
	//graphe.toString();

	return 0;
}