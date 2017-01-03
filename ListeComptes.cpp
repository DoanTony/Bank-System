#include "ListeComptes.h"


ListeComptes::ListeComptes()
{
}


int ListeComptes::getNombre()
{
	return ListeCompte.size();
}
void ListeComptes::Ajouter(Comptes compte)
{
	ListeCompte.push_back(compte);
}

vector<Comptes>::iterator  ListeComptes::getComptes()
{
	vector<Comptes>::iterator ptrComptes;
	ptrComptes = ListeCompte.begin();
	return ptrComptes;
}