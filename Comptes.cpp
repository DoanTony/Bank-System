#include "Comptes.h"


Comptes::Comptes()
{
};

Comptes::Comptes(string _Numero, string _Type, long _Solde, string _NoClient)
{
	setNumero(_Numero);
	setType(_Type);
	setSolde(_Solde);
	setNoClient(_NoClient);
}
void Comptes::setNumero(string _Numero)
{
	Numero = _Numero;
}
void Comptes::setType(string _Type)
{
	Type = _Type;
}
void Comptes::setSolde(long _Solde)
{
	Solde = _Solde;
}
void Comptes::setNoClient(string _NoClient)
{
	NoClient = _NoClient;
}
string Comptes::getNumero()
{
	return Numero;
}
string Comptes::getType()
{
	return Type;
}
long Comptes::getSolde()
{
	return Solde;
}
string Comptes::getNoClient()
{
	return NoClient;
}