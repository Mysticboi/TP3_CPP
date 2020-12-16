/*************************************************************************
                           ListeChainee  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ListeChainee> (fichier ListeChainee.h) ----------------
#if ! defined ( LISTECHAINEE_H )
#define LISTECHAINEE_H

//--------------------------------------------------- Interfaces utilisées
#include"Chainon.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ListeChainee>
//
//
//------------------------------------------------------------------------

class ListeChainee 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    //Méthodes pour liste chainee de Trajet Composee
    
    void InsertDansTrajetComposee(Trajet * unTrajet);
    // Mode d'emploi :
    // Cas Insertion dans TrajetComposee pas d'ordre.
    // Contrat :
    //
    void AfficherTrajetComposee() const;
    // Mode d'emploi :
    // Cas Affichage de la liste chainee d'un TrajetComposee
    // Contrat :
    //

    char * VilleD() const;
    // Mode d'emploi :
    // Obtenir la ville de départ ( pour l'initialisation de l'attribut du TrajetComposee)
    // Contrat :
    //

    char * VilleA() const;
    // Mode d'emploi :
    // Obtenir la ville d'arrivée ( pour l'initialisation de l'attribut du TrajetComposee)
    // Contrat :
    //

    Chainon * getTete() const;
    // Mode d'emploi :
    // Obtenir l'adresse contenue dans la tete de la listeChainee
    // Contrat :
    //

    void  setTete(Chainon *);
    // Mode d'emploi :
    // Modifier la tete de la listeChainee
    // Contrat :
    //
	
    //Méthodes pour liste chainee de Catalogue

    void InsertDansCatalogue(Trajet * unTrajet);
    // Mode d'emploi :
    // Cas Insertion dans catalogue il faut que la list chainée soit ordonnée
    // Contrat :
    //

    void AfficherCatalogue() const;
    // Mode d'emploi :
    // Cas Affichage de la liste chainee d'un catalogue
    // Contrat :
    //

    void SimpleSearch(char* villeDep, char* villeArr) const;
    // Mode d'emploi :
    // Méthode qui affiche les resultat de la recherche simple
    // Contrat :
    //

	bool ContainsCity(char * ville) const;
    // Mode d'emploi :
    // Méthode qui affiche les resultat de la recherche simple
    // Contrat :
    //

	void DeleteLast();
    // Mode d'emploi :
    // Méthode qui supprime le dernière élément de la liste chainee
    // Contrat :
    //
//------------------------------------------------- Surcharge d'opérateurs
    //ListeChainee & operator = ( const ListeChainee & unListeChainee );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //ListeChainee ( const ListeChainee & unListeChainee );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ListeChainee ();
    // Mode d'emploi :
    // 
    // Contrat :
    //

    virtual ~ListeChainee ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    int GetTaille();

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Chainon* tete;
    int taille;
};

//-------------------------------- Autres définitions dépendantes de <ListeChainee>

#endif // ListeChainee_H
