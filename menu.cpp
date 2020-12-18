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
        cout<<"\t 5: Ecriture dans un fichier"<<endl;
        cout<<"\t 6: Lecture d'un fichier"<<endl;
        cout<<"\t 7: Sauvegarde du catalogue complet dans un fichier sauvegarde.txt"<<endl;
        cout<<"\t 8: Effacer catalogue"<<endl;
        cin >>option;
		if(!cin.fail())
		{
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
						if(!cin.fail())
						{
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
										if(nbTrajet != 0 && nbTrajet != 1) 
										{ 
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
								else{ // Si on rentre un entier non présent dans les options
									cout<<red;
									cout<<"Option Invalide"<<endl;
									cout<<normal;
								}
						}
						else
						{ // Si on rentre une valeur autre qu'un entier
							cout<<red;
        				    cout<<"Option Invalide"<<endl;
							cout<<normal;
							cin.clear();
							cin.ignore(100,'\n');

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

				else if(option==5){
						cout<<"Veuillez saisir le nom du fichier sous forme (nom.txt): ";
						string nomF;
						cin>>nomF;
						ofstream file;
						file.open(nomF);
						cout<<"Veuillez choisir l'option de l'écriture"<<endl;
						cout<<"\t 1: Ecriture de tous les trajets sans sélection"<<endl;
						cout<<"\t 2: Ecriture des trajets simples uniquement"<<endl;
						cout<<"\t 3: Ecriture des trajets composés uniquement"<<endl;
						cout<<"\t 4: Ecriture des trajets selon une ville de départ"<<endl;
						cout<<"\t 5: Ecriture des trajets selon une ville d'arrivée"<<endl;
						cout<<"\t 6: Ecriture des trajets selon une ville de départ et une ville d'arrivée"<<endl;
						int optionC;
						cin>>optionC;
						if(!cin.fail()){
							if(optionC>0 and optionC<4){
									monCatalogue.EcrireCatalogue(file,optionC);
							}
							else if(optionC==4){
									string villeDep;
									cout<<"Veuillez rentrer la ville de départ: ";
									cin>>villeDep;
									monCatalogue.EcrireCatalogueVille(file,4,villeDep);
							}
							else if(optionC==5){
									string villeArr;
									cout<<"Veuillez rentrer la ville d'arrivée: ";
									cin>>villeArr;
									monCatalogue.EcrireCatalogueVille(file,5,villeArr);

							}
							else if(optionC==6){
									string villeDep;
									string villeArr;
									cout<<"Veuillez rentrer la ville départ: ";
									cin>>villeDep;
									cout<<"Veuillez rentrer la ville d'arrivée: ";
									cin>>villeArr;
									monCatalogue.EcrireCatalogueVilles(file,villeDep,villeArr);
							}
							else{
								cout<<red;
								cout<<"Option Invalide"<<endl;
								cout<<normal;
							}

							file.close();
						}
						else{
							cout<<red;
							cout<<"Option Invalide"<<endl;
							cout<<normal;
							cin.clear();
							cin.ignore(100,'\n');
						}
				}
				else if(option==6){
						cout<<"Veuillez saisir le nom du fichier sous forme (nom.txt): ";
						string nomF;
						cin>>nomF;
						ifstream file;
						file.open(nomF);
						cout<<"Veuillez choisir l'option de lecture"<<endl;
						cout<<"\t 1: Lecture de tous les trajets sans sélection"<<endl;
						cout<<"\t 2: Lecture des trajets simples uniquement"<<endl;
						cout<<"\t 3: Lecture des trajets composés uniquement"<<endl;
						cout<<"\t 4: Lecture des trajets selon une ville de départ"<<endl;
						cout<<"\t 5: Lecture des trajets selon une ville d'arrivée"<<endl;
						cout<<"\t 6: Lecture des trajets selon une ville de départ et une ville d'arrivée"<<endl;
						int optionC;
						cin>>optionC;
						if(!cin.fail()){
							if(optionC>0 and optionC<4){
									monCatalogue.LireCatalogue(file,optionC);
							}
							else if(optionC==4){
									string villeDep;
									cout<<"Veuillez rentrer la ville de départ: ";
									cin>>villeDep;
									monCatalogue.LireCatalogueVille(file,4,villeDep);
							}
							else if(optionC==5){
									string villeArr;
									cout<<"Veuillez rentrer la ville d'arrivée: ";
									cin>>villeArr;
									monCatalogue.LireCatalogueVille(file,5,villeArr);

							}
							else if(optionC==6){
									string villeDep;
									string villeArr;
									cout<<"Veuillez rentrer la ville départ: ";
									cin>>villeDep;
									cout<<"Veuillez rentrer la ville d'arrivée: ";
									cin>>villeArr;
									monCatalogue.LireCatalogueVilles(file,villeDep,villeArr);
							}
							else{ // Càs où l'utilisateur rentre un entier pas présent dans les options
								cout<<red;
								cout<<"Option Invalide"<<endl;
								cout<<normal;
							}

							file.close();
						}
						else{
							cout<<red;
							cout<<"Option Invalide"<<endl;
							cout<<normal;
							cin.clear();
							cin.ignore(100,'\n');
						}
				}
				else if(option==7)
				{
					ofstream file;
					file.open("sauvegarde.txt");
					monCatalogue.EcrireCatalogue(file,1);
					file.close();
				}
				else if(option==8)
				{
					monCatalogue.Reset();
				}
				else//cas où l'utilisateur a rentré un nombre qui ne faisait pas partie du menu
				{
					cout<<red;
					cout<<"Option Invalide"<<endl;
					cout<<normal;
				}
		}
        else//cas où l'utilisateur a rentré autre chose qu'un entier
		{
			cout<<red;
            cout<<"Option Invalide"<<endl;
			cout<<normal;
			cin.clear();
			cin.ignore(100,'\n');
        }
    }

    return 0;
}
