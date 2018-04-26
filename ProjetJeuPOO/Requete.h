#pragma once
#include "stdafx.h"

using namespace std;
class Requete
{
public:
	Requete(int* ip,int id,string compte,JeuInfo *jI);
	virtual ~Requete() { delete jInfo; };
	friend ostream& operator<<(ostream& os,const Requete& req);
	int* getIp() { return ip; }
	int getId()const { return id; }
	string getCompte() const{ return compte; }
	JeuInfo* getJeuInfo() const { return jInfo; }
	string toString() const{
		return "ENVOI DE LA REQUETE ID : "+ to_string(id) + " ( " + jInfo->afficherInfo()+ " ) ";
	}
private:
	int* ip;
	int id;
	string compte;
	JeuInfo *jInfo;
};

