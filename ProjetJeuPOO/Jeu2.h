#pragma once

#include "stdafx.h"
using namespace std;
class Jeu2
{
public:
	Jeu2() {
		this->name = "Jeu2";
		this->info = " Be Gerald de Rive and kill tones of monster";
	}
	~Jeu2();
	bool isPvp = false;
	string getName()const { return name; }
	string getInfo()const { return info; }
	string getMode()const { return isPvp ? " est PVP" :"est Solo PVE"; }
private:
	string name;
	string info;
};

