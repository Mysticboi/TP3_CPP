/*************************************************************************
                           Chainon  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Chainon> (fichier Chainon.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Chainon.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Chainon::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
//Chainon & Chainon::operator = ( const Chainon & unChainon )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur



Chainon::Chainon (Trajet * unTrajet ,Chainon* chainonSuivant)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Chainon>" << endl;
#endif

t = unTrajet;
next = chainonSuivant;

} //----- Fin de Chainon

Chainon:: Chainon( Trajet * unTrajet)
{
#ifdef MAP
    cout << "Appel au constructeur de <Chainon>" << endl;
#endif
    t=unTrajet;
    next=nullptr;
}

Chainon::Chainon()
{
#ifdef MAP
    cout << "Appel au constructeur de <Chainon>" << endl;
#endif
    t=new Trajet();
    next=nullptr;
}


Chainon::~Chainon ( )
// Algorithme :
//
{
    delete t;
#ifdef MAP
    cout << "Appel au destructeur de <Chainon>" << endl;
#endif
} //----- Fin de ~Chainon

Trajet * Chainon::GetTrajet()
{
    return t;
}

Chainon * Chainon::GetNext()
{
    return next;
}

void Chainon::SetTrajet(Trajet * unTrajet)
{
    t=unTrajet;
}

void Chainon::SetNext(Chainon* chainonSuivant)
{
    next=chainonSuivant;
}

bool Chainon::HasNext() const
{
    if(next==nullptr)
        return false;
    else
        return true;
}
void Chainon::Afficher() const
{
    t->AfficherTrajet();
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
