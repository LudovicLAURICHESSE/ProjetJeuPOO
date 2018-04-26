#pragma once

#include "stdafx.h"
using namespace std;
class Jeu2Adapter :
	public JeuInfo
{
public:
	Jeu2Adapter() { this->jeu = new Jeu2(); };
	~Jeu2Adapter();
	string getMode() { return this->jeu->isPvp ? "est PVP" : "est PVE"; };
	string getNomJeu()  { return jeu->getName(); }
	string getInfo() { return this->jeu->getInfo(); }
	string afficherInfo() {
		return this->getNomJeu() + this->getInfo() + this->getMode();
	}
private:
	Jeu2* jeu;
};

