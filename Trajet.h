/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( Trajet_H )
#define Trajet_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
//
//------------------------------------------------------------------------
class Trajet 
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
    Trajet & operator = ( const Trajet & unTrajet );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Trajet ( const Trajet & unTrajet );
    // Mode d'emploi (ructeur de copie) :
    //
    // Contrat :
    //

    Trajet ();
    // Mode d'emploi (ructeur par défaut) :
    //
    // Contrat :
    //

    Trajet ( const char * villeDep , const char * villeArr );
    // Mode d'emploi :
    // Constructeur utilisants 2 villes comme paramètres
    // Contrat :
    //

    virtual ~Trajet ( );
    // Mode d'emploi :
    // Destructeur
    // Contrat :
    //

    virtual void AfficherTrajet ( ) const;
    // Mode d'emploi :
    // Méthode permettant d'afficher les infos d'un trajet ( virtual car à réutiliser dans TrajetSimple et TrajetComposee)
    // Contrat :
    //

    bool CompareTrajet( const Trajet & unTrajet) const;
    // Mode d'emploi :
    // Méthode permettant de comparer la VD et VA entre 2 trajets renvoie true si tous les 2 sont égaux.
    // Contrat :
    //

    bool CmpVilleD( const char * villeDep) const;
    // Mode d'emploi :
    // Méthode permettant de comparer l'attribut villeDepart avec une ville en paramètre.
    // Contrat :
    //

    bool CmpVilleA( const char * villeArr) const;
    // Mode d'emploi :
    // Méthode permettant de comparer l'attribut villeArrivee avec une ville en paramètre.
    // Contrat :
    //

    bool CompareTrajetVilles( const char * villeDep, const char * villeArr) const;
    // Mode d'emploi :
    // Méthode permettant de comparer les 2 attributs villeDepart et villeArrivee avec 2villes en paramètre.
    // Contrat :
    //

    char* GetVilleD() const;
    // Mode d'emploi :
    // 
    // Contrat :
    //

    char* GetVilleA() const;
    // Mode d'emploi :
    // 
    // Contrat :
    //





//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    char * villeD;
    char * villeA;
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // Trajet_H

