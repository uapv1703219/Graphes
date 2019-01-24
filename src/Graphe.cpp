#include "Graphe.h"
#include "GetData.h"

using namespace std;

Graphe::Graphe(string file_name)
{
	nbsommets = getNbSommets(file_name);
	cout << nbsommets;
}