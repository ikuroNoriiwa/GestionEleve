/*
 *IHM_afficheEleve.c
 *
 * Created on: 22 feb. 2020
 *      Author: Mathieu
 */

 #include <stdlib.h>
 #include <stdio.h>
 #include "conio.h"
 #include "../defStruct.h"
 #include "../APP/APP_creationEleve.h"


 void IHM_afficheEleve__afficherTousEleves(){
    Eleve** tabEleves = APP_creationEleve__getAllEleves() ;
    int longTab = APP_creationEleve__getNbEleve();
    int i = 0, j = 0;
    printf("long tab = : %d",longTab );

    printf("\n");
    printf("|    id    |     Nom    |    Prenom    |    Promo   |\n");
    for(i = 0; i < longTab; i++){

        printf("|   %4d   |",tabEleves[i]->id);

        for(j = 0 ; j < (6 - strlen(tabEleves[i]->nom)/2) ; j++){
            printf(" ");
        }
        printf("%s",tabEleves[i]->nom);
        if(strlen(tabEleves[i]->nom)%2 == 0 ){
            for(j = 0 ; j < (6 - strlen(tabEleves[i]->nom)/2) ; j++){
                printf(" ");
            }
        }else if(strlen(tabEleves[i]->nom)%2 != 0 ){
            for(j = 0 ; j < (6 - strlen(tabEleves[i]->nom)/2)-1 ; j++){
                printf(" ");
            }
        }
        printf("|");

        for(j = 0 ; j < (7 - strlen(tabEleves[i]->prenom)/2) ; j++){
            printf(" ");
        }
        printf("%s",tabEleves[i]->prenom);
        if(strlen(tabEleves[i]->prenom)%2 == 0 ){
            for(j = 0 ; j < (7 - strlen(tabEleves[i]->prenom)/2) ; j++){
                printf(" ");
            }
        }else if(strlen(tabEleves[i]->prenom)%2 != 0 ){
            for(j = 0 ; j < (7 - strlen(tabEleves[i]->prenom)/2)-1 ; j++){
                printf(" ");
            }
        }
        printf("|");

        for(j = 0 ; j < (6 - strlen(tabEleves[i]->promotion)/2) ; j++){
            printf(" ");
        }
        printf("%s",tabEleves[i]->promotion);
        if(strlen(tabEleves[i]->promotion)%2 == 0 ){
            for(j = 0 ; j < (6 - strlen(tabEleves[i]->promotion)/2) ; j++){
                printf(" ");
            }
        }else if(strlen(tabEleves[i]->promotion)%2 != 0 ){
            for(j = 0 ; j < (6 - strlen(tabEleves[i]->promotion)/2)-1 ; j++){
                printf(" ");
            }
        }
        printf("|\n");
       // printf("|");
    }
 }

 void IHM_afficheEleve__ajouterEleve(){
    char nom[80];
    char prenom[80];
    char promotion[80];
    char choix;
    Eleve* tmp;

    printf("\nSaisir le nom : ");
    fgets(nom, 79,stdin);
    nom[strlen(nom)-1] = '\0';
    printf("\nSaisir le prenom : ");
    fgets(prenom, 79,stdin);
    prenom[strlen(prenom)-1] = '\0';
    printf("\nSaisir la promotion : ");
    fgets(promotion, 79,stdin);
    promotion[strlen(promotion)-1] = '\0';

    while(choix != 'y' || choix != 'n' ||
          choix != 'Y' || choix != 'N' ||
          choix != 'o' || choix != 'O'   ){
            printf("Etes-vous sur de vouloir entrer l\'eleve %s %s de la promotion %s ? (y ou n)",prenom,nom,promotion);
            choix = getch();
            if(choix == 'o' || choix == 'y' ||
               choix == 'O' || choix == 'Y'){
                tmp = createEleve(nom,prenom,promotion,0);
                saveEleves(tmp);
                break;
            }
          }
 }


 void IHM_afficherEleve__supprimerEleve(){
     char idSaissie[20];
     int ret  = 0;
     Eleve* tmp;
     int enCours = -1;
     char choix ;

     while(enCours == -1){
         printf("\nSaisir l\'ID de l\'eleve a supprimer : ");
         fgets(idSaissie, 19, stdin);
         ret = atoi(idSaissie);
         tmp = APP_creationEleve__getOneEleve(ret);
        if(ret != 0 ){
             if(tmp == NULL){
               // printf("NULL ?? %s\n",tmp->nom);
               printf("\nAucun eleve ne porte cet Identifiant\n");
             }else if(tmp != NULL){
                 while(1){
                    printf("Etes-vous sur de vouloir supprimer %s %s de la promotion %s ainsi que toutes ses notes ?\n",tmp->prenom, tmp->nom, tmp->promotion);
                    printf("Attention, cette action est irreversible !! (Y ou N)\n ");
                    choix = getch();
                    if(choix == 'o' || choix == 'y' ||
                        choix == 'O' || choix == 'Y'){
                        APP_creationEleve__supprimerEleve(ret);
                        enCours = 9;
                        break;
                    }else if(choix == 'n' || choix == 'N'){
                        printf("Suppression annulee\n");
                        enCours = 12;
                        break;
                    }
                 }
             }
             //break;
        }else if(ret == 0){
            enCours = 10;
            break;
        }
     }
 }

 void IHM_afficheEleve__modifierEleve(int idEleve){
    har idSaissie[20];
     int ret  = 0;
     Eleve* tmp;
     int enCours = -1;
     char choix ;
     int aModifier ;

     while(enCours == -1){
         printf("\nSaisir l\'ID de l\'eleve a modifier : ");
         fgets(idSaissie, 19, stdin);
         ret = atoi(idSaissie);
         tmp = APP_creationEleve__getOneEleve(ret);
        if(ret != 0 ){
             if(tmp == NULL){
               // printf("NULL ?? %s\n",tmp->nom);
               printf("\nAucun eleve ne porte cet Identifiant\n");
             }else if(tmp != NULL){
                 while(1){
                    printf("Etes-vous sur de vouloir modifier %s %s de la promotion %s ?\n",tmp->prenom, tmp->nom, tmp->promotion);
                    printf("Attention, cette action est irreversible !! (Y ou N)\n ");
                    choix = getch();
                    if(choix == 'o' || choix == 'y' ||
                        choix == 'O' || choix == 'Y'){
                        //APP_creationEleve__supprimerEleve(ret);
                        enCours = 9;
                        break;
                    }else if(choix == 'n' || choix == 'N'){
                        printf("Modification annulee\n");
                        enCours = 12;
                        break;
                    }
                 }
             }
             //break;
        }else if(ret == 0){
            enCours = 10;
            break;
        }
     }

 }
