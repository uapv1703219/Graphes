#include <string>

#include "Graphe.h"
#include "GetData.h"

using namespace std;

int main(int argc, char const *argv[])
{
	Graphe graphe = Graphe("graphe.txt");
	//graphe.toString();
	int ch[graphe.getNbSommets()];
	graphe.chaineAugment(0, 5, ch);

	for (int i = 0; i < graphe.getNbSommets(); ++i)		//Affichage chaine augmentante
	{
		cout << "ch[" <<  i << "] = " << ch[i] << endl;
	}

	cout << "Max augment = " << graphe.increment(ch, 0, 5) << endl;

	return 0;
}