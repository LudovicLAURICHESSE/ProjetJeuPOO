#pragma once
using namespace std;
class RequeteInfo
{
public:
	RequeteInfo(int* ip,JeuInfo *jI);
	virtual ~RequeteInfo() { delete jInfo; delete ip; }
	int* getIp() { return ip; }
	JeuInfo* getJeuInfo() { return jInfo; }
	string toString() const {
		return "ENVOI D'UNE REQUETE INFO :" + jInfo->afficherInfo();
	}
	friend ostream& operator<<(ostream& os, const RequeteInfo& req);
private:
	int* ip;
	JeuInfo *jInfo;
};

