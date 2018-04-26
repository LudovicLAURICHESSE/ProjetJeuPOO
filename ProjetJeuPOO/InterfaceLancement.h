#pragma once
#include "stdafx.h"
using namespace std;
class InterfaceLancement
{
public:
	virtual void lancerRequete(Requete *requete) = 0;
	virtual void lancerRequeteInfo(RequeteInfo *requeteInfo) = 0;
	virtual thread** getMesThreads() = 0;
};

