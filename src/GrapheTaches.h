#pragma once

#include <iostream>

class GrapheTaches
{
	int largeur;
	int profondeur;

	int** taches;
	int* tot;
	int* tard;
public:
	GrapheTaches(std::string);
	//~GrapheTaches();
	std::string toString();
	void getPlusTot();
	void getPlusTard();
	
};