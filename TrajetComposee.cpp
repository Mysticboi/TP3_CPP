/*************************************************************************
                           TrajetComposee  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetComposee> (fichier TrajetComposee.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"
#include "TrajetComposee.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetComposee::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void TrajetComposee::AfficherTrajet()const
// Algorithme :
//
{
	listeTrajet->AfficherTrajetComposee();		
} //----- Fin de AfficherTrajet

void TrajetComposee::EcrireTrajet(ofstream & file) const
// Algorithme :
//
{
    file<<"$"<<listeTrajet->GetTaille()<<","<<villeD<<","<<villeA;
    listeTrajet->EcrireListeTC(file);
} //----- Fin de EcrireTrajet

bool TrajetComposee::IsTrajetComposee() const
// Algorithme :
//
{
    return true;
} //----- Fin de IsTrajetComposee

//------------------------------------------------- Surcharge d'opérateurs
TrajetComposee & TrajetComposee::operator = ( const TrajetComposee & unTrajetComposee )
// Algorithme :
//
{
		return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
TrajetComposee::TrajetComposee ( const TrajetComposee & unTrajetComposee )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetComposee>" << endl;
#endif
} //----- Fin de TrajetComposee (constructeur de copie)


TrajetComposee::TrajetComposee ( ListeChainee * uneListe) : Trajet(uneListe->VilleD(),uneListe->VilleA())
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetComposee>" << endl;
#endif
	listeTrajet=uneListe;
} //----- Fin de TrajetComposee


TrajetComposee::~TrajetComposee ( )
// Algorithme :
//
{
    delete listeTrajet;
#ifdef MAP
    cout << "Appel au destructeur de <TrajetComposee>" << endl;
#endif
} //----- Fin de ~TrajetComposee


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

