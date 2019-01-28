#pragma once

#include <vector>
#include <string>

class Pile
{
private:
	std::vector<int> pile;

public:
	Pile();
	~Pile();
	void Empiler(int);
	int Depiler();
	bool isEmpty();
	/*std::string toString();*/
};