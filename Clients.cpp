#include "Clients.h"


Clients::Clients()
{
}

Clients::Clients(string numero, string prenom, string nom, string telephone, ListeComptes listecomptes)
{
	setNumero(numero);
	setPrenom(prenom);
	setNom(nom);
	setTelephone(telephone);
	setCompte(listecomptes);
}


string Clients::getNumero()
{
	return Numero;
}

string Clients::getPrenom()
{
	return Prenom;
}

string Clients::getNom()
{
	return Nom;
}

string Clients::getTelephone()
{
	return Telephone;
}
ListeComptes Clients::getComptes()
{
	return ListeCompte;
}
void Clients::setNumero(string _Numero)
{
	Numero = _Numero;
}

void Clients::setPrenom(string _Prenom)
{
	Prenom = _Prenom;
}

void Clients::setNom(string _Nom)
{
	Nom = _Nom;
}

void Clients::setTelephone(string _Telephone)
{
	Telephone = _Telephone;
}

void Clients::setCompte(ListeComptes _ListeComptes)
{
	ListeCompte = _ListeComptes;
}

