#include "FonctionStruct.h"
#include "ListeClients.h"
#include "Clients.h"
#include <iostream>


// Main
void main()
{
	int choix = 0;
	ListeClients Liste = LoadingFichierClient(); // Loading des fichiers text
	vector<Clients>::iterator tmp;
	do // Loop de choix while != 7
	{
		MenuPrincipal(); // Affichage de menu principal
		cin >> choix;
		switch (choix)
		{
		case 1:
			Liste.Ajouter(CreerClient()); // Creation d'un client avec ses comptes
			EnregitrementClientCompte(Liste); // Enregistrement Automatique des clients et compte
			break;
		case 2:
			tmp = Liste.Trouver(NumeroClient()); // Fonction Trouverclient ****** CRASH QUAND LE NUMERO DE CLIENT N'EXISTE PAS *************
			Affichage(tmp);
			break;
		case 3:
			SupprimerClient(Liste); // Fonction Supprimer un client
			//EnregitrementClientCompte(Liste); // Enregistrement Automatique des clients et compte
			break;
		case 4:
			AfficheClients(Liste); // Fonction afficher les clients et leur comptes
			break;
		case 5:
			AfficherReverse(Liste); // Fonction afficher les clients et leur comptes en reverse
			break;
		case 6:
			cout << "Programme terminer. Au revoir!";
			break;
		}
		cout << "\n (Retour au menu principal). ";
		system("pause"); // Pauser le programme et demande de peser n'importe quel touche
	} while (choix != 6); 
}


// AFFICHER LES TITRES
void AfficheTitre(string titre)
{
	cout << "\t\tFEDERAL-BANK\n";
	cout << "\t\t------------\n";
	cout << "\t\t" << titre << endl;
	cout << "\t\t";

	for (int i = 0; i<titre.length(); i++) // Tracer le underscore selon la longueur du titre
	{
		cout << "-";
	}
	cout << endl;
}

// AFFICHAGE DU MENU PRINCIPAL
void MenuPrincipal()
{
	system("cls");
	AfficheTitre("Menu Principal");
	cout << "1 - Ajouter un client/compte\n";
	cout << "2 - Trouver un client/compte\n";
	cout << "3 - Supprimer un client/compte \n";
	cout << "4 - Afficher tous les clients/comptes \n";
	cout << "5 - Afficher en reverse tous les clients/comptes \n";
	cout << "6 - Quitter \n";
	cout << "Entrez votre choix (1-6): ";
}

// LOADING DES FICHIERS TEXTE
ListeClients LoadingFichierClient()
{
	ListeClients LClient;
	ifstream fichierclient("clients.txt"); // FICHIER TEXTE EN MODE LECTURE
	string Numero, Prenom, Nom, Telephone;
	ListeComptes Liste;

	while (fichierclient >> Numero >> Prenom >> Nom >> Telephone) // LOOP DE CHAQUE LIGNE DU FICHIER TEXTE ET INSERER DANS LA STRUCTURE
	{
		
		Liste = LoadingFichierCompte(Numero); // AFFECTER LA LISTE DE COMPTES DU CLIENT DES COMPTES LOADER
		Clients client(Numero, Prenom, Nom, Telephone, Liste); // INITIALISATION D'UN NOUVEAU CLIENT 
		LClient.Ajouter(client); // AJOUTER LE CLIENT DANS LA LISTE DE CLIENT
	}
	return LClient;
}

// LOADING DU FICHIER TEXTE COMPTES ET RETOURNE L'ADDRESSE D'UNE STRUCTURE
ListeComptes LoadingFichierCompte(string Numero)
{

	ListeComptes Liste; // INITIALISATION D'UNE NOUVELLE LISTE DE COMPTES
	string NumeroCompte,Type,NoClient; // VARIABLE POUR COMPARER LE NUMERO DU CLIENT DANS LE COMPTE AVEC LE NUMERO DE CLIENT
	long Solde;
	ifstream fichiercompte("comptes.txt"); // FICHIER TEXTE EN MODE LECTURE

	while (fichiercompte >> NumeroCompte >> Type >> Solde >> NoClient) // AFFECTER LES LIGNE DU FICHIER TEXT DANS LA STRUCTURE COMPTE
	{
		if (NoClient == Numero) // COMPARISON DU NUMERO DE CLIENT DANS LE COMPTE AVEC LE NUMERO DE CLIENT
		{
			Comptes Nouveau(NumeroCompte,Type,Solde,NoClient); // INITIALISATION D'UN NOUVEAU COMPTE
			Liste.Ajouter(Nouveau); // AJOUT DU COMPTE DANS LA LISTE DE COMPTES
		}
	}

	return Liste; // RETOURNE L'ADDRESSE DE LA LISTE DE COMPTES
}


// ENREGISTREMENT DE TOUT LES INFORMATIONS DU CLIENT
void EnregitrementClientCompte(ListeClients Lclient)
{
	ofstream fichierClients("clients.txt"); // Fichier texte en mode ecriture
	ofstream fichierComptes("comptes.txt"); // Fichier texte en mode ecriture
	vector<Clients>::iterator client = Lclient.getListe(); // Pointeur qui pointe au premier client

	
	for (int i = 0; i < Lclient.getNombre(); i++)
	{
		fichierClients << client->getNumero() << " " << client->getPrenom() << " " << client->getNom() << " " << client->getTelephone() << endl; // Ecrire dans le fichier texte
		ListeComptes Lcompte = client->getComptes(); // Pointeur de comptes
		vector<Comptes>::iterator compte = Lcompte.getComptes();
		for (int i = 0; i < Lcompte.getNombre(); i++)
		{
			compte->setNoClient(client->getNumero()); //  Attacher le numero du client au compte enregistrer
			fichierComptes << compte->getNumero() << " " << compte->getType() << " " << compte->getSolde() << " " << compte->getNoClient() << endl; // Ecrire dans le fichier texte
			compte++;
		}
		client++;
	}
	fichierClients.close();
	fichierComptes.close();

}
// CREATION D'UN CLIENT
Clients CreerClient()
{
	char choix;
	string numero, prenom, nom, telephone;
	Comptes typeCompte;
	system("cls"); // Clear le contenue d'affichage de la console
	AfficheTitre("Ajouter un nouveau client"); // Affichage du titre

	cout << "Entrez le numero du client: ";
	cin >> numero;
	cout << "Entrez le prenom du client: ";
	cin >> prenom;
	cout << "Entrez le nom du client: ";
	cin >> nom;
	cout << "Entre le numero de telephone: ";
	cin >> telephone;
	ListeComptes listecomptes;
	do
	{
			typeCompte = CreeCompte(numero);
			listecomptes.Ajouter(typeCompte);
			if (listecomptes.getNombre() !=3)
				do 
				{
					cout << "Voulez-vous ajouter un autre compte(o/n)?:  ";
					cin >> choix;
				} while (!(choix == 'o' || choix == 'O' || choix == 'n' || choix == 'N')); // Boucle tant que la mauvaise reponse est entrer
			else
			{
				cout << "\nCe client a le nombre maximum de comptes";
			}
		
	} while (!(choix == 'n' || choix == 'N' || listecomptes.getNombre() == 3));
	Clients NouveauClient(numero, prenom, nom, telephone, listecomptes);

	return NouveauClient;
}

// CREATION D'UN COMPTE
Comptes CreeCompte(string NoClient){

	
	string Numero, Type;
	long Solde;
	int choix;
	cout << "----------\n";
	cout << "Compte(s): \n";
	cout << "\tEntrez le numero de compte: ";
	cin >> Numero;
	cout << "\tEntrez le type de compte(1-Cheque,2-Epargne ou 3-Credit): ";
	cin >> choix;
	Type = TypeCompte(choix);
	cout << "\tEntrez le solde du compte: ";
	cin >> Solde;
	Comptes NouveauCompte(Numero, Type, Solde, NoClient);// Creation d'un nouveau compte
	return NouveauCompte; // Retourne l'addresse du compte

}

string NumeroClient()
{
	string numero;
	system("cls"); // Clear tous les affichages sur la console
	AfficheTitre("Affichage des clients"); // Affichage du titre
	cout << "Entrez le numero du client desirer : ";
	cin >> numero;
	return numero;
}

void Affichage(vector<Clients>::iterator client)
{
	ListeComptes Liste;
	Liste = client->getComptes();
	vector<Comptes>::iterator ptrComptes = Liste.getComptes();
	cout << "\tNumero: " <<  client->getNumero() << endl;
	cout << "\tNom : " << client->getPrenom() << " " << client->getNom() << endl;
	cout << "\tTelephone: " << client->getTelephone() << endl;
	cout << "\t\t-----------\n";
	cout << "\t\tCompte(s)\n";
	for (int i = 0; i < Liste.getNombre(); i++)
	{
		cout << "\t\t-----------\n";
		cout << "\t\tNumero: " << ptrComptes->getNumero() << endl;
		cout << "\t\tType: " << ptrComptes->getType() << endl;
		cout << "\t\tSolde: " << ptrComptes->getSolde() << endl;
		ptrComptes++;
	}
}

// AFFICHAGE DES CLIENTS ET COMPTES
void AfficheClients(ListeClients Liste)
{
	system("cls"); // Clear tous les affichages sur la console
	AfficheTitre("Affichage des clients"); // Affichage du titre
	vector<Clients>::iterator ptrclient = Liste.getListe();
	if (Liste.getNombre() > 0) // Tant qu'un client existe dans la banque
	{
		for (int i = 0; i < Liste.getNombre(); i++)
		{
			Affichage(ptrclient);
			ptrclient++;
		}
	}
	else
	{
		cout << "Aucun client enregistrer a cette banque\n\n";
	}
}
// Type de compte creer
string TypeCompte(int choix)
{
	string TypeCompte;
	switch (choix)
	{
	case 1:
		TypeCompte = "Cheque";
		break;
	case 2:
		TypeCompte = "Epargne";
		break;
	case 3:
		TypeCompte = "Credit";
		break;
	}
	return TypeCompte;
}

// SUPPRIMER UN CLIENT;   *************** NE FONCTIONNE PAS ***************************
void SupprimerClient(ListeClients Liste)
{
	system("cls"); // Clear tous les affichages sur la console
	AfficheTitre("Supprimer un client"); // Affichage du titre
	if (Liste.getNombre() > 0)
	{
		char choix;
		bool Validation = false;
		string Client; // pointeur client
	//	pTempSuivant = pTempPrecedent = NULL;
		Client = NumeroClient();
		do
		{
			cout << "Voulez vous vraiment supprimer le client (o/n)?";
			cin >> choix;
		} while (!(choix == 'o' || choix == 'O' || choix == 'n' || choix == 'N')); // Boucle tant que le mauvaise reponse est entrer

		if (choix == 'o' || choix == 'O')
		{
			Liste.Supprimer(Client);
			cout << "\nClient supprimer! \n ";
			Validation = true;
		}
		if (Validation == false) // Condition de client pas trouver
		{
			cout << "\nAucun client trouver!\n";
		}
	}
	else
	{
		cout << "\nAucun client enregistrer a cette banque\n"; // Clients n'existe pas dans la banque
	}

}

// AFFICHAGE DES CLIENTS ET COMPTES EN REVERSE *************** NE FONCTIONNE PAS ***************************
void AfficherReverse(ListeClients Liste)
{
	system("cls");  // Clear tous les affichages sur la console
	AfficheTitre("Affichage des clients reverse"); // Affichage du titre
	vector<Clients>::iterator ptrclient = Liste.getFinListe();
	if (Liste.getNombre() > 0) // Tant qu'un client existe dans la banque
	{
		for (int i = 0; i < Liste.getNombre(); i++)
		{
				Affichage(ptrclient);
				ptrclient--;
		}

	}
	else
	{
		cout << "Aucun client enregistrer a cette banque\n\n";
	}
}

