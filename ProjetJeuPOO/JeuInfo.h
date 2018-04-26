#pragma once
#include "stdafx.h"
using namespace std;
class JeuInfo
{
public:
	JeuInfo();
	virtual ~JeuInfo();
	virtual string getNomJeu()=0;
	virtual string getMode()=0;
	virtual string getInfo()=0;
	virtual string afficherInfo() = 0;
};

