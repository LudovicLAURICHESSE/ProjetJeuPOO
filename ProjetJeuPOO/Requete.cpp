#include "stdafx.h"
#include "Requete.h"


Requete::Requete(int* ip, int id, string compte,JeuInfo *jI)
{
	this->compte = compte;
	this->id = id;
	this->jInfo = jI;
	this->ip = ip;

}


ostream & operator<<(ostream & os, const Requete & req)
{
	os << req.toString();
	return os;
}
