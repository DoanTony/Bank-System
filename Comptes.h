
#include<iostream>
#include<string>
#pragma once


using namespace std;
class Comptes
{
public:
	Comptes();
	Comptes(string _Numero, string _Type, long _Solde, string _NoClient);
	void setNumero(string _Numero);
	void setType(string _Type);
	void setSolde(long _Solde);
	void setNoClient(string _NoClient);
	string getNumero();
	string getType();
	long getSolde();
	string getNoClient();


private:
	string Numero;
	string Type;
	long Solde;
	string NoClient;;
};

