#include <string>

#include "Graphe.h"
#include "GetData.h"

using namespace std;

int main(int argc, char const *argv[])
{
	Graphe graphe = Graphe("graphe.txt");
	// //graphe.toString();
	// int ch[graphe.getNbSommets()];
	// graphe.chaineAugment(0, 5, ch);

	// for (int i = 0; i < graphe.getNbSommets(); ++i)		//Affichage chaine augmentante
	// {
	// 	cout << "ch[" <<  i << "] = " << ch[i] << endl;
	// }

	// cout << "Max augment = " << graphe.increment(0, 5, ch) << endl;

	cout << "flot max = " << graphe.flotMax(0, 5) << endl;
	//graphe.toString();

	return 0;
}