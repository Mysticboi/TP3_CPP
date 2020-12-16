/*************************************************************************
                           Chainon  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Chainon> (fichier Chainon.h) ----------------
#if ! defined ( CHAINON_H )
#define CHAINON_H

//--------------------------------------------------- Interfaces utilisées
#include"Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Chainon>
//
//
//------------------------------------------------------------------------

class Chainon 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher () const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool HasNext() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    Chainon();
    // Mode d'emploi :
    //
    // Contrat :
    //


    Chainon (Trajet * unTrajet , Chainon* chainonSuivant ); // Constructeur par défaut
    // Mode d'emploi :
    //
    // Contrat :
    //

    Chainon (Trajet* unTrajet);
    // Mode d'emploi :
    //
    // Contrat :
    //

    Trajet * GetTrajet();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Chainon* GetNext();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void SetTrajet(Trajet * unTrajet);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void SetNext(Chainon* chainonSuivant);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Chainon ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Trajet* t;
    Chainon* next;

};

//-------------------------------- Autres définitions dépendantes de <Chainon>

#endif // CHAINON_H
