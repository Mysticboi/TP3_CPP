/*************************************************************************
                           ListeChainee  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ListeChainee> (fichier ListeChainee.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ListeChainee.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs
//ListeChainee & ListeChainee::operator = ( const ListeChainee & unListeChainee )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
/*ListeChainee::ListeChainee ( const ListeChainee & unListeChainee )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ListeChainee>" << endl;
#endif
}*/ //----- Fin de ListeChainee (constructeur de copie)


ListeChainee::ListeChainee ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ListeChainee>" << endl;
#endif
    tete = nullptr;
    taille=0;

} //----- Fin de ListeChainee


ListeChainee::~ListeChainee ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ListeChainee>" << endl;
#endif
	if(taille==0){

	}
	else if(taille==1)
		delete tete;
	else if(taille==2){
		delete tete->GetNext();
		delete tete;
	}
	else{
		//Obligé de faire comme ça et de delete depuis la fin
		Chainon** tab=new Chainon* [taille];
		Chainon * elem=tete;
		for(int i=0;i<taille;i++){
			tab[i]=elem;
			if(i!=taille-1)
				elem=elem->GetNext();
		}
		for(int i=taille-1; i>=0; i--){
			elem=tab[i];
			delete elem;
		}
		delete []tab;
	}
} //----- Fin de ~ListeChainee

// Méthodes pour utilisation de ListeChainee pour TrajetComposee

void ListeChainee::InsertDansTrajetComposee(Trajet * unTrajet)
// Algorithme :
//
{
    if(taille==0){
        Chainon * elem=new Chainon(unTrajet);
        tete=elem;
        taille++;
        return;
    }
    else{
        Chainon* elem=tete;
        while(elem->HasNext()){
            elem=elem->GetNext();
        }
        Chainon * nouveau=new Chainon(unTrajet);
        elem->SetNext(nouveau);
        taille++;
    }
} //----- Fin de InsertDansTrajetComposee

void ListeChainee::DeleteLast()
{
	//pointeur de parcours
	Chainon * parcours;
	
	parcours = tete;

	//On s'assure que la liste ne soit pas vide
	if(parcours==nullptr)
			return;

	//Cas ou la liste n'a qu'un seul élément
	if(!parcours->HasNext())
	{
		operator delete(tete);
		tete = nullptr;
		taille=0;
		return;
	}

	//cas de plusieurs éléments
	// pointeur pour sauvegarder le chainon d'avant
	Chainon * prev = parcours;
	parcours =parcours->GetNext();
	while(parcours->HasNext())
	{
		prev = parcours;
		parcours = parcours->GetNext();
	}
	operator delete(prev->GetNext());
	prev->SetNext(nullptr);
	taille--;
	return;
}
void ListeChainee::setTete(Chainon * tete)
// Algorithme :
//
{
		this->tete = tete;
} //----- Fin setTete

Chainon * ListeChainee::getTete() const
// Algorithme :
//
{
		return tete;
} //----- Fin setTete

void ListeChainee::AfficherTrajetComposee() const
// Algorithme :
//
{
    if(taille==0){
        cout<<"La liste est vide"<<endl;
        return;
    }
    Chainon * elem=tete;
    elem->Afficher();
    cout<<" - ";
    while(elem->HasNext()){
        elem=elem->GetNext();
        elem->Afficher();
        cout<<" - ";
    }
    
} //----- Fin de Afficher

char* ListeChainee::VilleD() const
// Algorithme:
//
{
        return tete->GetTrajet()->GetVilleD();
} // Fin de VilleD

char* ListeChainee::VilleA() const
// Algorithme:
//
{
        Chainon * elem=tete;
        while(elem->HasNext()){
            elem=elem->GetNext();
        }
        return elem->GetTrajet()->GetVilleA();
} // Fin de VilleA

// Méthodes pour utilisation de ListeChainee pour Catalogue

/*bool ListeChainee::InsertDansCatalogue(Trajet * unTrajet) // Opérationnel || Idée d'upgrade: Vérifier pour les moyens de transport avec un Trajet->GetTransport() 
//Algorithme:
//
{
	bool isInserted = true;
	if(taille==0) {
		Chainon * nouveau = new Chainon(unTrajet);
		tete = nouveau;
		taille++;
		cout << "Trajet de " << unTrajet->GetVilleD() << " à " << unTrajet->GetVilleA() << " inséré." << endl;
		return isInserted;
	}
         else {
		Chainon* previous;
		Chainon* actual=tete;
		while(actual->HasNext() && (strcmp(unTrajet->GetVilleD(),actual->GetTrajet()->GetVilleD()) > 0)) {		
			previous = actual;
			actual = actual->GetNext();
		}
		if(strcmp(unTrajet->GetVilleD(),actual->GetTrajet()->GetVilleD()) == 0 && strcmp(unTrajet->GetVilleA(),actual->GetTrajet()->GetVilleA()) == 0) {
			cout << "Le trajet de " << unTrajet->GetVilleD() << " à " << unTrajet->GetVilleA() << " existe déjà." << endl;
			isInserted = false;
			return isInserted;
		} else {
			if(!(actual->HasNext())) {
				Chainon * nouveau = new Chainon(unTrajet);
				actual->SetNext(nouveau);
				taille++;
				cout << "Trajet de " << unTrajet->GetVilleD() << " à " << unTrajet->GetVilleA() << " inséré." << endl;			
				return isInserted;
			}
			 else {
				Chainon * nouveau = new Chainon(unTrajet);
				previous->SetNext(nouveau);
				nouveau->SetNext(actual);
				taille++;
				cout << "Trajet de " << unTrajet->GetVilleD() << " à " << unTrajet->GetVilleA() << " inséré." << endl;
				return isInserted;
			 }
		}
	 }
}
// Fin de InsertDansCatalogue
*/

void ListeChainee::InsertDansCatalogue(Trajet * unTrajet)
// Algorithme:
//
{
    if(taille==0){ // Cas liste vide
        Chainon * elem=new Chainon(unTrajet);
        tete=elem;
        taille++;
        return;
    }
    if(taille==1){ // Cas 1seul élement dans la liste
        Chainon * nouveau=new Chainon(unTrajet);
        if(strcmp(unTrajet->GetVilleD(),tete->GetTrajet()->GetVilleD())>0){
            tete->SetNext(nouveau);
        }
        else{
            nouveau->SetNext(tete);
            tete=nouveau;
        }
        taille++;
        return;
    } // Cas plusieurs élements
    Chainon * nouveau=new Chainon(unTrajet);
    if(strcmp(unTrajet->GetVilleD(),tete->GetTrajet()->GetVilleD())<=0){ // Cas Ajout en tête
        nouveau->SetNext(tete);
        tete=nouveau;
        taille++;
        return;
    }
    Chainon * elem=tete->GetNext();
    Chainon * prev=tete;
    while(elem->HasNext() && strcmp(unTrajet->GetVilleD(),elem->GetTrajet()->GetVilleD())>0 ){
        prev=elem;
        elem=elem->GetNext();
    }
    if(!(elem->HasNext()) && strcmp(unTrajet->GetVilleD(),elem->GetTrajet()->GetVilleD())>0 ){ // Ajout fin
        elem->SetNext(nouveau);
        taille++;
        return;
    }
    else{ // Ajout milieu
        prev->SetNext(nouveau);
        nouveau->SetNext(elem);
        taille++;
        return;
    }
} // Fin de InsertDansCatalogue

void ListeChainee::AfficherCatalogue() const
// Algorithme:
//
{
    if(taille==0)
	{
        cout<<"La liste est vide"<<endl;
        return;
    }
    Chainon * elem=tete;
    elem->Afficher();
    cout<<endl;
    while(elem->HasNext()){
        elem=elem->GetNext();
        elem->Afficher();
        cout<<endl;
    }

} // Fin de AfficherCatalogue

void ListeChainee::SimpleSearch(char* villeDep, char* villeArr) const
// Algorithme:
//
{
	//On vérifie que la liste n'est pas vide
	if(tete==nullptr)
	{
		cout<<endl<<"Aucun résultat"<<endl;
		return;
	}
    unsigned int n=0;
    Chainon* elem=tete;
    if(elem->GetTrajet()->CompareTrajetVilles(villeDep,villeArr)){
        elem->GetTrajet()->AfficherTrajet();
        cout<<endl;
        n++;
    }
    while(elem->HasNext()){
        elem=elem->GetNext();
        if(elem->GetTrajet()->CompareTrajetVilles(villeDep,villeArr)){
            elem->GetTrajet()->AfficherTrajet();
            cout<<endl;
            n++;
        }
    }
    cout<<n<< " Parcours possibles au total"<<endl;
}

bool ListeChainee::ContainsCity(char * Ville) const
// Algorithme :
//
{
	//Variable de parcours de la liste
	Chainon * parcours = tete;

	while(parcours!=nullptr)
	{
		//Si la ville en paramètre correspond à la ville de départ ou d'arrivé du trajet du chainon courant on retourne true
		if(strcmp(Ville,parcours->GetTrajet()->GetVilleA())==0 || strcmp(Ville,parcours->GetTrajet()->GetVilleD())==0)
				return true;
		parcours = parcours->GetNext();
	}
	//Si la ville n'a pas été trouvé in retourne false
	return false;
}//---- Fin de ContainsCity

int ListeChainee::GetTaille()
// Algorithme :
//
{
	return taille;
}//---- Fin de GetTaille

void ListeChainee::EcrireListeCatalogue(ofstream & file,int option) const
// Algorithme :
//
{
    if(option==1){ // Cas Affichage de tous les trajets sans sélection
        if(getTete()==nullptr)
            return;
        Chainon * elem=getTete();
        if(!elem->HasNext())
		{
            elem->GetTrajet()->EcrireTrajet(file);
            file<<endl;
            return;
        }
        else
		{
            elem->GetTrajet()->EcrireTrajet(file);
            file<<endl;
            while(elem->HasNext())
			{
                elem=elem->GetNext();
                elem->GetTrajet()->EcrireTrajet(file);
                file<<endl;
            }
        }
    }
    else if(option==2){ // Cas Affichage que des trajets Simples
        if(getTete()==nullptr)
            return;
        Chainon * elem=getTete();
        if(!elem->HasNext()){
            if(!elem->GetTrajet()->IsTrajetComposee()){
                elem->GetTrajet()->EcrireTrajet(file);
                file<<endl;
            }
            return;
        }
        else{
            elem->GetTrajet()->EcrireTrajet(file);
            file<<endl;
            while(elem->HasNext()){
                elem=elem->GetNext();
                if(!elem->GetTrajet()->IsTrajetComposee()){
                    elem->GetTrajet()->EcrireTrajet(file);
                    file<<endl;
                }
            } 
        }
    }
    else if(option==3){ // Cas Affichage que des trajets Composées
        if(getTete()==nullptr)
            return;
        Chainon * elem=getTete();
        if(!elem->HasNext()){
            if(elem->GetTrajet()->IsTrajetComposee()){
                elem->GetTrajet()->EcrireTrajet(file);
                file<<endl;
            }
            return;
        }
        else{
            if(elem->GetTrajet()->IsTrajetComposee()){
                elem->GetTrajet()->EcrireTrajet(file);
                file<<endl;
            }
            while(elem->HasNext()){
                elem=elem->GetNext();
                if(elem->GetTrajet()->IsTrajetComposee()){
                    elem->GetTrajet()->EcrireTrajet(file);
                    file<<endl;
                }
            } 
        }
    }

}//---- Fin de EcrireListeCatalogue

void ListeChainee::EcrireListeTC(ofstream & file) const
// Algorithme :
//
{
    if(getTete()==nullptr)
        return;
    Chainon * elem=getTete();
    if(!elem->HasNext()){
        elem->GetTrajet()->EcrireTrajet(file);
        return;
    }
    else{
        elem->GetTrajet()->EcrireTrajet(file);
        while(elem->HasNext()){
            elem=elem->GetNext();
            elem->GetTrajet()->EcrireTrajet(file);
        }
    }

}//---- Fin de EcrireListeCatalogue

void ListeChainee::EcrireListeCatalogueVille(ofstream & file, int option, string ville) const
// Algorithme :
//
{
    if(option==4){ // Cas Ville départ
        if(getTete()==nullptr)
            return;
        Chainon * elem=getTete();
        if(!elem->HasNext()){
            if(elem->GetTrajet()->CmpVilleD(ville.c_str())){
                elem->GetTrajet()->EcrireTrajet(file);
                file<<endl;
            }
            return;
        }
        else{
            if(elem->GetTrajet()->CmpVilleD(ville.c_str())){
                elem->GetTrajet()->EcrireTrajet(file);
                file<<endl;
            }
            while(elem->HasNext()){
                elem=elem->GetNext();
                if(elem->GetTrajet()->CmpVilleD(ville.c_str())){
                    elem->GetTrajet()->EcrireTrajet(file);
                    file<<endl;
                }
            } 
        }
    }

    else if(option==5){ // Cas Ville arrivée
        if(getTete()==nullptr)
            return;
        Chainon * elem=getTete();
        if(!elem->HasNext()){
            if(elem->GetTrajet()->CmpVilleA(ville.c_str())){
                elem->GetTrajet()->EcrireTrajet(file);
                file<<endl;
            }
            return;
        }
        else{
            if(elem->GetTrajet()->CmpVilleA(ville.c_str())){
                elem->GetTrajet()->EcrireTrajet(file);
                file<<endl;
            }
            while(elem->HasNext()){
                elem=elem->GetNext();
                if(elem->GetTrajet()->CmpVilleA(ville.c_str())){
                    elem->GetTrajet()->EcrireTrajet(file);
                    file<<endl;
                }
            } 
        }

    }
}//----- Fin de EcrireListeCatalogueVille

void ListeChainee::EcrireListeCatalogueVilles(ofstream & file, string villeDep,string villeArr) const
// Algorithme:
//
{
    if(getTete()==nullptr)
        return;
    Chainon * elem=getTete();
    if(!elem->HasNext()){
        if(elem->GetTrajet()->CompareTrajetVilles(villeDep.c_str(),villeArr.c_str())){
            elem->GetTrajet()->EcrireTrajet(file);
            file<<endl;
        }
        return;
    }
    else{
        if(elem->GetTrajet()->CompareTrajetVilles(villeDep.c_str(),villeArr.c_str())){
            elem->GetTrajet()->EcrireTrajet(file);
            file<<endl;
        }
        while(elem->HasNext()){
            elem=elem->GetNext();
            if(elem->GetTrajet()->CompareTrajetVilles(villeDep.c_str(),villeArr.c_str())){
                elem->GetTrajet()->EcrireTrajet(file);
                file<<endl;
            }
        } 
    }

}//----- Fin de EcrireListeCatalogueVilles


void ListeChainee::Reset()
// Algorithme :
//
{
	Chainon * elem;
	Chainon * tmp;
	elem = tete;

	if(elem==nullptr)
	{
			taille=0;
			return;
	}
	if(!elem->HasNext())
	{
		delete(elem);
		taille=0;
		tete=nullptr;
		return;
	}
	while(elem->HasNext())
	{
		tmp=elem->GetNext();
		delete(elem);
		elem=tmp;
	}
	delete(elem);
	taille=0;
	tete=nullptr;
	return;
}//____ Fin de Reset



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
