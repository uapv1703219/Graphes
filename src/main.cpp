#include <string>

#include "Graphe.h"
#include "GetData.h"

using namespace std;

int main(int argc, char const *argv[])
{
	Graphe graphe = Graphe("graphe.txt");
	graphe.toString();
	graphe.chaineAugment(0, 5);
	//cout << graphe.chaineAugment(0, 5) << endl;
	return 0;
}