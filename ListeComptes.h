#pragma once
#include "Comptes.h"
#include <vector>
class ListeComptes
{
public:
	ListeComptes();
	int getNombre();
	void Ajouter(Comptes compte);
	vector<Comptes>::iterator getComptes();


private:
	vector<Comptes> ListeCompte;
};

