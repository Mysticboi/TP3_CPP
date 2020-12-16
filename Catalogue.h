/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( Catalogue_H )
#define Catalogue_H

//--------------------------------------------------- Interfaces utilisées
#include "ListeChainee.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
//
//------------------------------------------------------------------------

class Catalogue 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Catalogue & operator = ( const Catalogue & unCatalogue );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Catalogue ( const Catalogue & unCatalogue );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    Catalogue();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Catalogue (ListeChainee * uneListe );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Catalogue ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void InsertTrajet(Trajet * unTrajet);
    // Mode d'emploi :
    // Insertion d'un trajet simple ou composee
    // Contrat :
    //

    void Afficher() const;
    // Mode d'emploi :
    // Affichage du catalogue
    // Contrat :
    //

    void SimpleSearch(char* villeDep, char* villeArr) const;
    // Mode d'emploi :
    // Recherche Simple
    // Contrat :
    //

    void AdvancedSearch(char * villeDep, char * villeArr);
    // Mode d'emploi :
    // Recherche Avancée
    // Contrat :
    //
	
	bool DepthFirstSearch( char * villeDep, char * villeArr);
    // Mode d'emploi :
    // Méthode récursive qui renvoie vrai si elle a trouvé un parcour
	// qui satisfait la recherche avancée et faux sinon 
    // Contrat :
    //

    ListeChainee* GetList();
    // Mode d'emploi :
    //
    // Contrat : 

    void EcrireCatalogue(ofstream & file, int option) const;
    // Mode d'emploi :
    //
    // Contrat : 

    void EcrireCatalogueVille(ofstream & file, int option, string ville) const;
    // Mode d'emploi :
    //
    // Contrat : 

    void EcrireCatalogueVilles(ofstream & file, string villeDep,string villeArr) const;
    // Mode d'emploi :
    //
    // Contrat : 



	



//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    
//----------------------------------------------------- Attributs protégés
    ListeChainee * listTrajet;
	ListeChainee pileParcours;
	int nbVoyagesValides;

};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // Catalogue_H

