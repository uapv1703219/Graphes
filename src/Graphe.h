#pragma once
#include "Pile.h"

#include <iostream>

class Graphe {

private:
	int nbsommets;
	int** capacite;
	int** flot;

public:
	Graphe(std::string);
	void toString();
	int* chaineAugment(int, int);
};