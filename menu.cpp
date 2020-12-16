#include <iostream>
using namespace std;

#include <cstring>
#include "Trajet.h"
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetComposee.h"
#include "ListeChainee.h"

int main(int argc, char const *argv[])
{
    Catalogue  monCatalogue=Catalogue();
	//affichage coloré
	char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
	char red[] = { 0x1b, '[', '1', ';', '3', '1', 'm', 0 };
	char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };

    while(true){
        int option;
        cout<<"Bienvenue au menu: Veuillez choisir une option"<<endl;
        cout<<"\t 0: Quitter l'application"<<endl;
        cout<<"\t 1: Ajout d'un trajet"<<endl;
        cout<<"\t 2: Afficher le contenu du catalogue"<<endl;
        cout<<"\t 3: Recherche Simple dans le catalogue"<<endl;
        cout<<"\t 4: Recherche Avancée dans le catalogue"<<endl;
        cin >>option;
        if(option==0){
            cout<<"Au revoir!"<<endl;
            break;
        }
        else if(option==1){ 
			cout<<red;
            cout<<"Veuillez choisir le type du trajet:"<<endl;
            cout<<"\t 1: Trajet Simple"<<endl;
            cout<<"\t 2: Trajet Composé"<<endl;
			cout<<normal;
            int optionT;
            cin>>optionT;
            if(optionT==1){ //Ajout d'un trajet simple
                char * villeD =new char[20];
                char * villeA=new char[20];
                char * moyenT=new char[20];
				cout<<red;
                cout<<"Veuillez rentrer la ville de départ: ";
				cout<<normal;
                cin>>villeD;
				cout<<red;
                cout<<"Veuillez rentrer la ville d'arrivée: ";
				cout<<normal;
                cin>>villeA;
				cout<<red;
                cout<<"Veuillez rentrer le moyen de transport: ";
				cout<<normal;
                cin>>moyenT;
                TrajetSimple * tS=new TrajetSimple(villeD,villeA,moyenT);
                monCatalogue.InsertTrajet(tS);
                delete [] villeD;
                delete [] villeA;
                delete [] moyenT;
            }
            else if(optionT==2){ // Ajout d'un trajet composée
		        int nbTrajet; 
                cout<<"De combien de trajets simples est composé votre trajet composé? : ";
                cin>>nbTrajet;
	            if(nbTrajet != 0 && nbTrajet != 1) { //Traiter le cas où le nombre de trajet est 1 -> trajet Simple
                	ListeChainee * list=new ListeChainee(); 
			        char* tmpVilleA = new char[20];  //Ville de départ du trajet simple suivant 
                    for(int i=0; i < nbTrajet; i++){
                        cout<<"Trajet simple n° "<<i+1<<":"<<endl;
                        // Allocation des caractéristiques du trajet.	
                        char * villeA = new char[20];
                        char * moyenT = new char[20];
                        if (i==0) {
                            char * villeD = new char[20];
                            cout<<"Veuillez rentrer la ville de départ: ";
                            cin>>villeD;
                            cout<<"Veuillez rentrer la ville d'arrivée: ";
                            cin>>villeA;
                            cout<<"Veuillez rentrer le moyen de transport: ";
                            cin>>moyenT;
                            TrajetSimple * tS=new TrajetSimple(villeD,villeA,moyenT);
                            list->InsertDansTrajetComposee(tS);
                            delete [] villeD;	
                        } 
                        else {
                            cout<<"Veuillez rentrer la ville d'arrivée du trajet simple n° "<< i+1 << " : ";
                            cin>>villeA;
                            cout<<"Veuillez rentrer le moyen de transport: ";
                            cin>>moyenT;
                            TrajetSimple *tS = new TrajetSimple(tmpVilleA,villeA,moyenT);
                            list->InsertDansTrajetComposee(tS);
                        }
                        strcpy(tmpVilleA, villeA);   
                        delete [] villeA;
                        delete [] moyenT;
                    }
                    delete [] tmpVilleA;
                TrajetComposee * tc= new TrajetComposee(list);
                monCatalogue.InsertTrajet(tc);
		        }
        	    else if (nbTrajet == 1) {  //Cas où le nombre de trajets est 1 : Trajet Simple
                    char * villeD =new char[20];
                        char * villeA=new char[20];
                        char * moyenT=new char[20];
                        cout<<"Veuillez rentrer la ville de départ: ";
                        cin>>villeD;
                        cout<<"Veuillez rentrer la ville d'arrivée: ";
                        cin>>villeA;
                        cout<<"Veuillez rentrer le moyen de transport: ";
                        cin>>moyenT;
                        TrajetSimple * tS=new TrajetSimple(villeD,villeA,moyenT);
                        monCatalogue.InsertTrajet(tS);
                        delete [] villeD;
                        delete [] villeA;
                        delete [] moyenT;
	            }
            }
	    }
        else if(option==2){ //Affichage Catalogue
			cout<<blue;
            cout<<"----------Affichage du catalogue-----------"<<endl;
            monCatalogue.Afficher();
            cout<<"----------Fin Affichage du catalogue-------"<<endl;
			cout<<normal;
        }

        else if(option==3){  //Recherche Simple
            char * villeD =new char[20];
            char * villeA=new char[20];
			cout<<blue;
            cout<<"-----Début recherche simple------- "<<endl;
			cout<<normal;
			cout<<red;
            cout<<"Veuillez rentrer la ville de départ: ";
			cout<<normal;
            cin>>villeD;
			cout<<red;
            cout<<"Veuillez rentrer la ville d'arrivée: ";
			cout<<normal;
            cin>>villeA;
			cout<<blue;
            monCatalogue.SimpleSearch(villeD,villeA);
            cout<<"------Fin recherche simple--------"<<endl;
			cout<<normal;
            delete [] villeD;
            delete [] villeA;
        }

        else if(option==4){ //Recherche Avancée
            char * villeD =new char[20];
            char * villeA=new char[20];
			cout<<blue;
            cout<<"Début recherche avancée: "<<endl;
			cout<<normal;
			cout<<red;
            cout<<"Veuillez rentrer la ville de départ: ";
			cout<<normal;
            cin>>villeD;
			cout<<red;
            cout<<"Veuillez rentrer la ville d'arrivée: ";
			cout<<normal;
            cin>>villeA;
			cout<<blue;
            monCatalogue.AdvancedSearch(villeD,villeA);
            cout<<"Fin recherche avancée."<<endl;
			cout<<normal;
            delete [] villeD;
            delete [] villeA;
        }

        else{
            cout<<"Option Invalide"<<endl;
        }
    }

    return 0;
}
