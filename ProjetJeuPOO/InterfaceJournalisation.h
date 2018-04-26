#pragma once
#include "stdafx.h"
using namespace std;
class InterfaceJournalisation
{
public:
	virtual void journaliser(Requete * requete, ServeurJeu* serveurJeu) = 0;
};

