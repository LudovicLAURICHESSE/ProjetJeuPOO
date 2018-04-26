#pragma once
#include "stdafx.h"
using namespace std;
class RequeteFactory
{
public:
	RequeteFactory();
	~RequeteFactory();
	Requete* createRequete(int* ip,string compte);
	RequeteInfo* createRequeteInfo(int* ip);
private :
	JeuInfo* generateJeu();
	int requeteIndex = 0;

};

