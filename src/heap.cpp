/************************************************/
/* Auteur : S. Gueye 				*/
/* Date : 3/02/2019  				*/
/* Objet : Indications sur les tas pour TP 2	*/
/************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d[6] = {3,7,10,7,9,1};

// Affiche d'un vecteur v quelconque
void display(vector<int> & v)
{
	int n = v.size();

	for(int i = 0; i < (n-1); i++)
		cout << v[i] << " - ";

	cout << v[n-1] << endl;
}

// Méthode de comparaison de deux indices i et j utilisée dans la création du tas
// Soient i et j deux indices contenus dans le tas. i "<" j ssi d[i] < d[j].
bool cmp(const int & i, const int & j)
{
	return(d[i] < d[j]); 
}


int main()
{
	vector<int> v;

	// Insertion des indices du tableau d
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	cout << "Vecteur v avant la transformation en un tas" << endl;
	display(v);

	cout << "Transformation de v en un tas " << endl;
	make_heap(v.begin(),v.end(),cmp);

	cout << "Vecteur v après la transformation en un tas" << endl;
	cout << "Notez que l'indice du plus grand élément de d est indiqué en premier" << endl;
	display(v);

	cout << "Suppression du premier élément de v (la plus grande valeur)" << endl;
	pop_heap(v.begin(),v.end(),cmp);
	display(v);

	cout << "Comme le plus grand élément, " << v.back() << ", est placé à la fin de v on le récupère avec back" << endl;
	cout << "Pour le supprimer, définitivement, il faut toutefois rajouter pop_back" << endl;
	v.pop_back();
	display(v);

	return(1);
}
