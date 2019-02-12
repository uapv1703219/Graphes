#include "Pile.h"

using namespace std;

Pile::Pile()
{

}

Pile::~Pile()
{

}

void Pile::Empiler(int number)
{
	pile.push_back(number);
}

int Pile::Depiler()
{
	int ret = pile.back();
	pile.pop_back();
	return ret;
}

bool Pile::isEmpty()
{
	return pile.empty();
}

/*string Pile::toString()
{
	string temp = "";
	int tmp;
	while(!pile.empty())
	{
		tmp = pile.front();
		pile.pop_back();
		temp = temp + to_string(tmp) + " ";
	}
	return temp;
}	*/