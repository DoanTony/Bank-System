#pragma once
#include "ListeComptes.h"
#include "Comptes.h"
#include <iostream>
#include <string>

using namespace std;
class Clients
{
public:
	Clients();
	
	Clients::Clients(string numero, string prenom, string nom, string telephone, ListeComptes listecompte);
	string getNumero();
	string getPrenom();
	string getNom();
	string getTelephone();
	ListeComptes getComptes();
	void setNumero(string _Numero);
	void setPrenom(string _Prenom);
	void setNom(string _Nom);
	void setTelephone(string _Telephone);
	void setCompte(ListeComptes _ListeComptes);

private:
	string Numero, Prenom, Nom, Telephone;
	ListeComptes ListeCompte;

};


