/*************************************************************************
                           TrajetComposee  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetComposee> (fichier TrajetComposee.h) ----------------
#if ! defined ( TrajetComposee_H )
#define TrajetComposee_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "ListeChainee.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetComposee>
//
//
//------------------------------------------------------------------------

class TrajetComposee : public Trajet 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	void AfficherTrajet() const;
    // Mode d'emploi :
    //Affichage du trajet composé
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    TrajetComposee & operator = ( const TrajetComposee & unTrajetComposee );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    TrajetComposee ( const TrajetComposee & unTrajetComposee );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    TrajetComposee (ListeChainee * uneListe);
	// @arg1 : Pointeur vers un tableau de Trajet Simple 
	// @arg2 : Taille de ce tableau
    // Mode d'emploi :
    //Creer un objet Trajet composé à partir d'une liste de trajets simples 
    // Contrat :
    //

    virtual ~TrajetComposee ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void EcrireTrajet(ofstream & file) const;
    // Mode d'emploi :
    // Ecriture d'un trajet composée dans un fichier
    // Contrat :
    //

    bool IsTrajetComposee() const;

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    ListeChainee * listeTrajet;
};

//-------------------------------- Autres définitions dépendantes de <TrajetComposee>

#endif // TrajetComposee_H

