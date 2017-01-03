#include "ListeClients.h"


ListeClients::ListeClients()
{
}

int ListeClients::getNombre()
{
	return CustomerList.size();

}


void ListeClients::Ajouter(Clients client)
{
	CustomerList.push_back(client);
}

void ListeClients::Supprimer(string Numero)
{
	for (ptrClient = CustomerList.begin(); ptrClient != CustomerList.end(); ++ptrClient)
	{
		if (ptrClient->getNumero() == Numero)
		{
			CustomerList.erase(ptrClient);
			break;
		}
	}
}

vector<Clients>::iterator ListeClients::Trouver(string Numero)
{
	for (ptrClient = CustomerList.begin(); ptrClient != CustomerList.end(); ++ptrClient)
	{
		if (ptrClient->getNumero() == Numero)
		{
			return ptrClient;
			break;
		}
	}
	return ptrClient;
}

vector<Clients>::iterator ListeClients::getListe()
{
	return CustomerList.begin();
}


vector<Clients>::iterator ListeClients::getFinListe()
{
	return CustomerList.end();
}
