#pragma once
#include "stdafx.h"
using namespace std;
class ServeurJeu
{
public:
	ServeurJeu();
	virtual ~ServeurJeu();
	static void gererRequetes(ServeurJeu* monServeur);
	void lancerRequete(Requete *requete);
	queue<Requete*> getMesRequetes()const { return this->mesRequetes; }
	void popRequete() { mesRequetes.pop(); }

private:
	queue<Requete*> mesRequetes;
};

