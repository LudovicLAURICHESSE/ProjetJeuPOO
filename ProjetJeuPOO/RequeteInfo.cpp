#include "stdafx.h"
#include "RequeteInfo.h"




RequeteInfo::RequeteInfo(int* ip,JeuInfo *jI)
{
	this->jInfo = jI;
	this->ip = ip;
}

ostream & operator<<(ostream & os,const RequeteInfo& req)
{
	os << req.toString();
	return os;
}

