#pragma once

#include "stdafx.h"
using namespace std;
class Jeu1
{
public:
	Jeu1() { 
		this->name = "Jeu1";
		this->info = " Play alone or with your squad to kill everybody with fun!";
	}
	~Jeu1();
	bool isPvp = true;
	string getName()const { return name; }
	string getInfo()const { return info; }
	string getMode() { return isPvp ? " est pvp" : "est pve"; }
	string afficher() {
		return this->getName() + this->getInfo() + this->getMode();
	}
private:
	string name;
	string info;
};

