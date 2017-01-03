#pragma once

#include "Clients.h"
#include <vector>

class ListeClients
{
public:
	ListeClients();
	vector<Clients>::iterator Trouver(string Numero);
	vector<Clients>::iterator ListeClients::getListe();
	vector<Clients>::iterator ListeClients::getFinListe();
	void Ajouter(Clients client);
	void Supprimer(string Numero);
	int getNombre();


private:

	vector<Clients> CustomerList;
	vector<Clients>::iterator ptrClient;
};

