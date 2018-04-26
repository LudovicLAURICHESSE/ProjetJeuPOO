#pragma once
#include "stdafx.h"
using namespace std;
class Jeu1Adapter : 
	public JeuInfo
{
public:
	Jeu1Adapter() { this->jeu = new Jeu1(); };
	~Jeu1Adapter();
	string getMode() {return this->jeu->isPvp ? "est PVP" : "est PVE";};
	string getNomJeu()  { return jeu->getName(); }
	string getInfo() { return this->jeu->getInfo(); }
	string afficherInfo() {
		return this->getNomJeu() + this->getInfo() + this->getMode();
	}
private :
	Jeu1* jeu;
};

