#include "stdafx.h"
#include "RequeteFactory.h"


RequeteFactory::RequeteFactory()
{
}


RequeteFactory::~RequeteFactory()
{
}

Requete* RequeteFactory::createRequete(int* ip, string compte)
{
	requeteIndex++;
	return new Requete(ip,requeteIndex,compte,generateJeu());
}

RequeteInfo* RequeteFactory::createRequeteInfo(int* ip)
{
	return new RequeteInfo(ip,generateJeu());
}

JeuInfo* RequeteFactory::generateJeu()
{
	int nbgen = rand() % 4 + 1;
	switch (nbgen)
	{
		case 1 :
			return new Jeu1Adapter();
			break;
		case 2 :
			return new Jeu2Adapter();
			break;
		case 3 :
			return new Jeu3Adapter();
			break;
		case 4 :
			return new Jeu4();
			break;
	}
	return nullptr;
}


