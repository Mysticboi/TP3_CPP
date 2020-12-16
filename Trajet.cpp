/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Trajet::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Trajet & Trajet::operator = ( const Trajet & unTrajet )
// Algorithme :
//
{
    if(this!=&unTrajet){
        delete [] villeD;
        delete [] villeA;
        villeD=new char[strlen(unTrajet.villeD)+1];
        villeA=new char[strlen(unTrajet.villeA)+1];
        strcpy(villeD,unTrajet.villeD);
        strcpy(villeA,unTrajet.villeA);
    }
        
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet ( const Trajet & unTrajet )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Trajet>" << endl;
#endif
} //----- Fin de Trajet (constructeur de copie)

Trajet::Trajet()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <Trajet>" << endl;
#endif
} //----- Fin de Trajet (constructeur par défaut)


Trajet::Trajet ( const char * villeDep , const char * villeArr )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
	villeD=new char [strlen(villeDep)+1];
    strcpy(villeD,villeDep); 
	villeA=new char [strlen(villeArr)+1];
    strcpy(villeA,villeArr); 
} //----- Fin de Trajet

Trajet::~Trajet ( )
// Algorithme :
//
{
    delete [] villeA;
    delete [] villeD;
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
} //----- Fin de ~Trajet

void Trajet::AfficherTrajet () const 
// Algorithme :
// Sous la forme: ( De villeDepart à villeArrivee)
{
    cout<<"De "<<villeD;
    cout <<" à "<<villeA;
} //----- Fin de AfficherTrajet

bool Trajet::CompareTrajet (const Trajet & unTrajet) const 
// Algorithme :
//
{
    if(CmpVilleD(unTrajet.villeD) && CmpVilleA(unTrajet.villeA))
        return true;
    else
        return false;
} //----- Fin de CompareTrajet

bool Trajet::CmpVilleD(const char * Ville) const
// Algorithme :
//
{
		if(strcmp(Ville,villeD)==0)
				return true;
		else 
				return false;
} //----- Fin de CompareTrajetVilleD

bool Trajet::CmpVilleA(const char * Ville) const
// Algorithme :
//
{
		if(strcmp(Ville,villeA)==0)
				return true;
		else 
				return false;

} //----- Fin de CompareTrajetVilleD

bool Trajet::CompareTrajetVilles(const char * villeDep, const char * villeArr) const
// Algorithme :
//
{
    if(CmpVilleD(villeDep) && CmpVilleA(villeArr))
        return true;
    else
        return false;

} //----- Fin de CompareTrajetVilles

char * Trajet:: GetVilleD () const{
    return villeD;
} //----- Fin de GetVilleD

char* Trajet:: GetVilleA () const {
    return villeA;
} //----- Fin de GetVilleA

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

