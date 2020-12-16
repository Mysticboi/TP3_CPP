/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include<cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Catalogue::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Catalogue & Catalogue::operator = ( const Catalogue & unCatalogue )
// Algorithme :
//
{
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( const Catalogue & unCatalogue )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue (constructeur de copie)

Catalogue::Catalogue ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
    listTrajet=new ListeChainee();
} //----- Fin de Catalogue

Catalogue::Catalogue ( ListeChainee * uneListe)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
    listTrajet=uneListe;
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
	delete listTrajet;
} //----- Fin de ~Catalogue

void Catalogue::InsertTrajet(Trajet * unTrajet)
// Algorithme :
//
{
    listTrajet->InsertDansCatalogue(unTrajet);
} //----- Fin de operator =

void Catalogue::Afficher() const
// Algorithme :
//
{
    listTrajet->AfficherCatalogue();
} //----- Fin de operator =

void Catalogue::SimpleSearch(char * villeDep,char* villeArr) const
// Algorithme :
//
{
    listTrajet->SimpleSearch(villeDep,villeArr);
} //----- Fin de SimpleSearch



void Catalogue::AdvancedSearch(char * villeDep,char * villeArr)
// Algorithme :
//
{
	//on ré-initialise le compteur de voyages valides
	nbVoyagesValides=0;
	DepthFirstSearch(villeDep,villeArr);
	cout<<nbVoyagesValides<<" parcours sont disponibles"<<endl;
} //----- Fin AdvancedSearch



bool Catalogue::DepthFirstSearch( char * VilleD,char * VilleA)
// Algorithme :
//
{
	//On vérifie si on est arrivé dans la ville d'arrivé
	//si c'est le cas on incrémente nbVoyagesValides
	//et on remonte d'un niveau dans la récursivité en renvoyant true
	if(strcmp(VilleD,VilleA)==0)
	{
		nbVoyagesValides++;
		return true;
	}
	//On créer un pointeur qui nous permettra de parourir
	//la LinkedList listeDesTrajets.
	Chainon * parcours = listTrajet->getTete();
	if(parcours==NULL)
		return false;
	else
	{
		while(parcours!=NULL)
		{
			if(strcmp(parcours->GetTrajet()->GetVilleD(),VilleD)==0)
			{
				//Si la ville de départ du trajet courant dans
				//la listeDesTrajets est égal à la ville de départ de la
				//recherche avancé.



				//On vérifie si L'on tombe dans une ville  qui apparait déjà dans la Pile
				//parcours
				//Si tel est le cas on va  au prochain trajet
				if(pileParcours.getTete()!=nullptr && pileParcours.ContainsCity(parcours->GetTrajet()->GetVilleA()))
				{
						parcours=parcours->GetNext();
						continue;
				}

				//On empile le trajet correspondant sur la pileParcours
				pileParcours.InsertDansTrajetComposee(parcours->GetTrajet());
				//On appelle dfs avec comme ville de départ la ville d'arrivé
				//du trajet courant dans listeDesTrajets et comme ville d'arrivé
				//la ville d'arrivé de la recherche avancée
				if(DepthFirstSearch(parcours->GetTrajet()->GetVilleA(),VilleA))
				{
					//Si dfs a trouvé la ville d'arrivé on affiche le parcours
					cout<<endl;
					cout<<"Parcours n°"<<nbVoyagesValides;
					cout<<endl;
					//On ne teste pas si la pile
					//est vide avant l'affichage
					//car si dfs renvoie vrai la pile est
					//forcément non-vide.
					pileParcours.AfficherCatalogue();
					cout<<endl;
				}
				//On dépile le trajet courant
				pileParcours.DeleteLast();


			}
			//On passe au trajet suivant
			parcours=parcours->GetNext();

		}
			//On return false si il n'y a plus de trajet commençant par la
			//ville de départ du trajet courant.
			return false;
	}

} //----- Fin de dfs

ListeChainee* Catalogue::GetList(){
// Algorithme :
//
	return listTrajet;
}
//----- Fin de GetList


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

