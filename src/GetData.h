#pragma once
#include <string>

int getProfondeurTaches(std::string);
int getLargeurTaches(std::string);
void initTabTaches(int**, int, int, std::string);


int getNbSommetsFromTxt(std::string);
void initTab(int** capacite, int** flot, int nbsommets, std::string file_name);