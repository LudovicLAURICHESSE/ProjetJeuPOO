#include "stdafx.h"
#include "PUBG.h"

PUBG *PUBG::pubgInstance = nullptr;
PUBG::PUBG()
{
	mesThreads = new thread*[5];		
	serveursJeu = new ServeurJeu*[3];
	serveursJeu[0] = new ServeurJeu();	
	serveursJeu[1] = new ServeurJeu();	
	serveursJeu[2] = new ServeurJeu();	
										
	mesThreads[0] = new thread(&PUBG::gererRequete, this, &mesRequetes);			
	mesThreads[1] = new thread(&PUBG::gererRequeteInfo, this, &mesRequetesInfo);	
	mesThreads[2] = new thread(&ServeurJeu::gererRequetes, serveursJeu[0]);			
	mesThreads[3] = new thread(&ServeurJeu::gererRequetes, serveursJeu[1]);			
	mesThreads[4] = new thread(&ServeurJeu::gererRequetes, serveursJeu[2]);
}

PUBG::~PUBG()
{
	delete pubgInstance;
	for (int i = 0; i < 3; i++) {
		delete serveursJeu[i];
	}
	for (int i = 0; i < 5;i++) {
		delete mesThreads[i];
	}
	while (!this->mesRequetes.empty()) {
		delete this->mesRequetes.front();
		this->mesRequetes.pop();
	}
	while (!this->mesRequetesInfo.empty()) {
		delete this->mesRequetesInfo.front();
		this->mesRequetesInfo.pop();
	}

}
void PUBG::gererRequeteInfo(PUBG * pubg, queue<RequeteInfo*>* mesRequetesInfo)
{
	
	while (true)
	{
		if (!mesRequetesInfo->empty())
		{
			this_thread::sleep_for(5s);
			if (!mesRequetesInfo->empty())
			{
				cout << "id(-1)-> Information pour le jeu " + mesRequetesInfo->front()->getJeuInfo()->getNomJeu() << endl;
				mesRequetesInfo->pop();
			}
		}
	}
}
void PUBG::gererRequete(PUBG * pubg, queue<Requete*>* mesRequetes)
{
	string nomDuJeu;
	while (true)
	{
		if (!mesRequetes->empty())
		{
			this_thread::sleep_for(2s);
			if (!mesRequetes->empty())
			{
				nomDuJeu = mesRequetes->front()->getJeuInfo()->getNomJeu();

				if (nomDuJeu == "Jeu1") pubg->getServeursJeu()[0]->lancerRequete(mesRequetes->front());
				else if (nomDuJeu == "Jeu2") pubg->getServeursJeu()[1]->lancerRequete(mesRequetes->front());
				else if (nomDuJeu == "Jeu3") pubg->getServeursJeu()[2]->lancerRequete(mesRequetes->front());
				else cout << "id (" + to_string(mesRequetes->front()->getId()) + ") -> Le serveur de jeu " + mesRequetes->front()->getJeuInfo()->getNomJeu() + " n'existe pas" << endl;

				mesRequetes->pop();
			}

		}

	}
	
}

void PUBG::journaliser(Requete * requete, ServeurJeu * serveurJeu)
{
	cout << "id(" + to_string(requete->getId()) + ")Traitement du jeu " + requete->getJeuInfo()->afficherInfo()<< endl;
}

void PUBG::lancerRequete(Requete * requete)
{
	this->mesRequetes.push(requete);
}

void PUBG::lancerRequeteInfo(RequeteInfo * requeteInfo)
{
	this->mesRequetesInfo.push(requeteInfo);
}
