#pragma once

#include "stdafx.h"
using namespace std;
class Jeu3Adapter :
	public JeuInfo
{
public:
	Jeu3Adapter() { this->jeu = new Jeu3(); }
	~Jeu3Adapter();
	string getMode() { return this->jeu->getMode();};
	string getNomJeu()  { return this->jeu->getName(); }
	string getInfo() { return this->jeu->getInfo(); }
	string afficherInfo() { return this->getNomJeu() + this->getInfo() + this->getMode();}
private:
	Jeu3 *jeu;

};

