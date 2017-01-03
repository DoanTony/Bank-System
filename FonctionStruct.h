#include <iostream>
#include <string>
#include <fstream>
#include "Clients.h"
#include "ListeClients.h"
using namespace std;

// PROTOTYPE DES FONCTIONS
void AfficheTitre(string);
void MenuPrincipal();
ListeClients LoadingFichierClient();
ListeComptes LoadingFichierCompte(string);
Clients CreerClient();
Comptes CreeCompte(string);
string NumeroClient();
void Affichage(vector<Clients>::iterator);
void AfficheClients(ListeClients);
void SupprimerClient(ListeClients);
string TypeCompte(int);
void EnregitrementClientCompte(ListeClients);
void AfficherReverse(ListeClients);


