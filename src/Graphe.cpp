#include "Graphe.h"
#include "GetData.h"
#include "Pile.h"

#include <algorithm>

using namespace std;

int d[6];

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
					if ((capacite[i][j] > 0 && capacite[i][j] > flot[i][j]) || (capacite[j][i] > 0 && flot[j][i] > 0))
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

int Graphe::increment(int source, int terminal, int* ch)
{
	int row = ch[terminal];		//Prend la ligne du précedent
	int min = capacite[row][terminal];	//init min
	int col = row;	//la colone devient le précedent

	while(col != source)
	{
		row = ch[col];	//row devient le précédent
		if(min > capacite[row][col] - flot[row][col]) {min = capacite[row][col] - flot[row][col];}	//Si min est le min
		col = row;		//col deviens le précédent
	}
	return min;
}

int Graphe::flotMax(int source, int terminal)
{
	//init
	int ch[nbsommets];
	int tot = 0;
	int inc;
	int i = 0;

	//fonction
	while(true)
	{
		chaineAugment(source, terminal, ch);	//Ecrit le rés dans ch
		for (int i = 0; i < nbsommets; ++i)
		{
			cout << ch[i] << endl;
			
		}
		inc = increment(source, terminal, ch);

		//cerr << inc << endl;
		toString();

		if (inc == 0) {break;}

		augment(source, terminal, ch, inc);
		tot += inc;
		i++;
	}
	return tot;
}

void Graphe::augment(int source, int terminal, int* ch, int inc)
{
	int row = ch[terminal];		//Prend la ligne du précedent
	flot[row][terminal] += inc;
	int col = row;	//la colone devient le précedent

	while(col != source)
	{
		row = ch[col];	//row devient le précédent
		flot[row][col] += inc;	
		col = row;		//col deviens le précédent
	}
}

void Graphe::MooreDijkstra(int source, int* pere)
{
	vector<int> C;
	C.push_back(source);


	int d[nbsommets];
	d[0] = 0;
	pere[0] = 0;
	for(int i = 1; i < nbsommets; i++) { d[i] = 99999; pere[i] = 0; }
	int j = 0;
	
	for (int I = 0; I < nbsommets; ++I)
	{
		for (int i = 0; i < nbsommets; ++i)
		{
			/*for (vector<int>::const_iterator p = C.begin(); p != C.end(); ++p) cout << *p << ' ';
				cout << "i = " << i << " and capacite[j][i] = " << capacite[j][i] <<endl;
				cout <<endl;*/
			
			if (capacite[j][i] != 0 && !(find(C.begin(), C.end(), i) != C.end()))
			{
				//cout << "j = " << j <<"and d[j] = " << d[j] << " and d[j] + capacite[j][i] = " << d[j] + capacite[j][i] << " and d[i] = " << d[i] << endl;
				if(d[j] + capacite[j][i] < d[i])
				{
					d[i] = d[j] + capacite[j][i];
					pere[i] = j;
				}
			}
		}
		int min = 99999;
		int cur = 0;

		for (int i = 0; i < nbsommets; i++)
        {
        	//cerr << i <<" " <<d[i] << endl;
            if (!(find(C.begin(), C.end(), i) != C.end()) && d[i] < min)
            {
                min = d[i];
                cur = i;
            }
        }

		j = cur;
		C.push_back(j);
	}
}

void Graphe::Bellman(int source, int* pere)
{
	vector<int> C;
	C.push_back(source);


	int d[nbsommets];
	d[0] = 0;
	pere[0] = 0;
	for(int i = 1; i < nbsommets; i++) { d[i] = 99999; pere[i] = 0; }
	int j = 0;
	
	for (int I = 0; I < nbsommets; ++I)
	{
		for (int i = 0; i < nbsommets; ++i)
		{
			/*for (vector<int>::const_iterator p = C.begin(); p != C.end(); ++p) cout << *p << ' ';
				cout << "i = " << i << " and capacite[j][i] = " << capacite[j][i] <<endl;
				cout <<endl;*/
			
			if (capacite[j][i] != 0 && !(find(C.begin(), C.end(), i) != C.end()))
			{
				//cout << "j = " << j <<"and d[j] = " << d[j] << " and d[j] + capacite[j][i] = " << d[j] + capacite[j][i] << " and d[i] = " << d[i] << endl;
				if(d[j] + capacite[j][i] < d[i])
				{
					d[i] = d[j] + capacite[j][i];
					pere[i] = j;
				}
			}
		}
		int min = 99999;
		int cur = 0;

		for (int i = 0; i < nbsommets; i++)
        {
        	//cerr << i <<" " <<d[i] << endl;
            if (!(find(C.begin(), C.end(), i) != C.end()) && d[i] < min)
            {
                min = d[i];
                cur = i;
            }
        }

		j = cur;
		C.push_back(j);
	}
}

void Graphe::displayShortestPaths(int* pere)
{
	Pile pile;
	int tmp;
	for (int i = 0; i < nbsommets; ++i)
	{
		pile.Empiler(i);
		tmp = pere[i];
		pile.Empiler(tmp);
		while(tmp != 0)
		{
			tmp = pere[tmp];
			pile.Empiler(tmp);
		}

		cout << "Le plus cours chemin pour " << i << "est : [";
		while(true)
		{
			cout << pile.Depiler();
			if(!pile.isEmpty()) { cout << " , ";}
			else break;
		}
		cout << "]" << endl;
	}

}

void display(vector<int> & v)
{
	int n = v.size();

	for(int i = 0; i < (n-1); i++)
		cout << v[i] << " - ";

	cout << v[n-1] << endl;
}

bool cmp(const int & i, const int & j)
{
	return(d[i] > d[j]); 
}

void Graphe::MooreDijkstraTas(int source, int* pere)
{
	bool C[nbsommets];
	vector<int> tas;
	d[0] = 0;
	pere[0] = 0;
	tas.push_back(0);
	C[0] = true;

	for(int i = 1; i < nbsommets; i++) { d[i] = 99999; pere[i] = 0; tas.push_back(i); C[i] = false;}
	make_heap(tas.begin(), tas.end(), cmp);
	display(tas);
	pop_heap(tas.begin(), tas.end(), cmp);
	int j = tas.back();
	tas.pop_back();
	display(tas);

	for(int I = 0; I < nbsommets; I++)
	{
		for (int i = 1; i < nbsommets; ++i)
		{
				if(d[j] + capacite[j][i] < d[i] && C[i] == false)
				{
					//cout << j << endl;
					d[i] = d[j] + capacite[j][i];
					//cout << d[i] << endl;
					pere[i] = j;
				}
		}
		make_heap(tas.begin(), tas.end(), cmp);
		pop_heap(tas.begin(), tas.end(), cmp);
		for (int i = 0; i < nbsommets; ++i)
		{
			cout << d[i] << endl;
		}
		j = tas.back();
		tas.pop_back();
		C[j] = true;
	}

}

void Graphe::Bellman_(int source, int* pere)
{
	int k = 0;
	int d[nbsommets][nbsommets];
	bool stop = false;

	pere[0] = 0;
	d[0][0] = 0;
	for(int i = 1; i < nbsommets; i++) { d[0][i] = 99999; pere[i] = 0; }

	while(k < nbsommets && !stop)
	{
		for (int i = 1; i < nbsommets; ++i)
		{
			d[k+1][i] = d[i][k];
			for (int j = 0; j < nbsommets; ++j)
			{
				if (capacite[i][k] != 0)
				{
					if (d[k][j] + capacite[j][i] < d[k+1][i])
					{
						d[k+1][i] = d[k][j] + capacite[j][i];
						pere[i] = j;
					}
				}
			}
		}
		k++;
		for (int i = 0; i < nbsommets; ++i)
		{
			if (d[k][i] == d[k-1][i])
			{
				stop = true;
				break;
			}
		}
	}

}


int Graphe::getNbSommets()
{
	return this->nbsommets;
}