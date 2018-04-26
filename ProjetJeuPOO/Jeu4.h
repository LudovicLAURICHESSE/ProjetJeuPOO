#pragma once

#include "stdafx.h"
using namespace std;
class Jeu4 :
	public JeuInfo
{
public:
	Jeu4();
	~Jeu4();
	string getMode() 
	{
		return " est PVP et PVE! LEROYYYY JENKIINNS !!!!" ;
	};
	string getNomJeu() { return "Jeu4"; }
	string getInfo() { return " Ce jeu est un MMORPG"; }

	string afficherInfo() {
		return this->getNomJeu() + this->getInfo() + this->getMode();
	}
};

