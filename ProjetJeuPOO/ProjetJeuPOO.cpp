// ProjetJeuPOO.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
using namespace std;
template <class T> void afficher(T const& req) 
{
	cout << *req << endl;
}
void maFonctionMainFirstPart() {
	cout << "Entrez votre compte : " << endl;
	string compte;
	int ip[4] = { 127,0,0,1 };
	cin >> compte;
	RequeteFactory* rFactory = new RequeteFactory();
	while (true)
	{
		//pause 1s
		this_thread::sleep_for(1s);
		srand(time(NULL));
		int nbgen = rand() % 10 + 1;
		if (nbgen <= 9)
		{
			Requete *r = rFactory->createRequete(ip, compte);
			afficher(r);
			PUBG::getInterfaceLancementInstance()->lancerRequete(r);
		}
		else
		{
			RequeteInfo *rI = rFactory->createRequeteInfo(ip);
			afficher(rI);
			PUBG::getInterfaceLancementInstance()->lancerRequeteInfo(rI);
		}
	}
}
void maFonctionMainSecondePart() {
	thread** mesThreads = PUBG::getInterfaceLancementInstance()->getMesThreads();
	thread t1(&maFonctionMainFirstPart);
	for (int x = 0; x < 5; x++)
		mesThreads[x]->join();
	t1.join();
}
int main()
{
	//maFonctionMainFirstPart();
	maFonctionMainSecondePart();
	
    return 0;
}

