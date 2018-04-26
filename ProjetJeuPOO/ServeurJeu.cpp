#include "stdafx.h"
#include "ServeurJeu.h"

ServeurJeu::ServeurJeu()
{
}

ServeurJeu::~ServeurJeu()
{
}
void ServeurJeu::gererRequetes(ServeurJeu * monServeur)
{
	while (true)
	{
		this_thread::sleep_for(1s);
		if (!monServeur->getMesRequetes().empty()) {
			PUBG::getInterfaceJournalisationInstance()->journaliser(monServeur->getMesRequetes().front(), monServeur);
			monServeur->popRequete();
		}
	}
}

void ServeurJeu::lancerRequete(Requete * requete)
{
	this->mesRequetes.push(requete);
}
