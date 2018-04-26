#pragma once

#include "stdafx.h"
using namespace std;
class Jeu3
{
public:
	Jeu3() {
		this->name = "Jeu3";
		this->info = " Decouvre le jeu qui s'adapte lui même !";
	};
	~Jeu3();
	bool isPvp = true;
	string getName()const { return name; }
	string getInfo()const { return info; }
	string getMode()const { return isPvp ? " est Pvp, attention PVP difficile !" : "est Pve, bats uniquement des boss!";}
private:
	string name;
	string info;
};

