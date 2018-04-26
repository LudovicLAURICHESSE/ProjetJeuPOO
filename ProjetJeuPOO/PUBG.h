#pragma once
#include "stdafx.h"
using namespace std;
class PUBG : 
	public InterfaceJournalisation, 
	public InterfaceLancement
{
public:
	static void gererRequeteInfo(PUBG* pubg, queue<RequeteInfo*>* mesRequetesInfo);		
	static void gererRequete(PUBG* pubg, queue<Requete*>* mesRequetes);
	void journaliser(Requete * requete, ServeurJeu* serveurJeu);
	void lancerRequete(Requete *requete);
	void lancerRequeteInfo(RequeteInfo *requeteInfo);
	ServeurJeu** getServeursJeu()const { return serveursJeu; }
	thread** getMesThreads() { return mesThreads; }	
	static PUBG* getInstance() {  
		if(pubgInstance==nullptr)pubgInstance = new PUBG(); 
		return pubgInstance;
	}
	static InterfaceJournalisation* getInterfaceJournalisationInstance() { return PUBG::getInstance(); }
	static InterfaceLancement* getInterfaceLancementInstance() { return PUBG::getInstance(); }
private:
	PUBG();
	~PUBG();

	static PUBG* pubgInstance;
	thread** mesThreads;					
	ServeurJeu** serveursJeu;				
	queue<Requete*> mesRequetes;
	queue<RequeteInfo*> mesRequetesInfo;
};

