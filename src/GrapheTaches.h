#pragma once

#include <iostream>

class GrapheTaches
{
	int largeur;
	int profondeur;

	int** taches;
public:
	GrapheTaches(std::string);
	//~GrapheTaches();
	std::string toString();
	
};