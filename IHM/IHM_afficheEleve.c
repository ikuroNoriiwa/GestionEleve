/*
 *IHM_afficheEleve.c
 *
 * Created on: 22 feb. 2020
 *      Author: Mathieu
 */

 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
 #include "conio.h"
 #include "../defStruct.h"
 #include "../APP/APP_creationEleve.h"
 #include "../APP/APP_creationNotes.h"

/**
 * Liste tous les élèves présents en base triés par ID
 *
 * @author mathieu
 */
void IHM_afficheEleve__afficherTousEleves(){
    Eleve** tabEleves = APP_creationEleve__getAllEleves() ;
    int longTab = APP_creationEleve__getNbEleve();
    int i = 0, j = 0;
    //printf("long tab = : %d",longTab );

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

 /**
  * propose l'ajout d'un nouvel élève dans la base
  *
  * @author mathieu
  */
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

 /**
  * propose la suppression d'un élève dans la base
  *
  * @author mathieu
  */
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

 /**
  * propose la modification d'un élève dans la base
  *
  * @author mathieu
  */
 void IHM_afficheEleve__modifierEleve(){
    char idSaissie[20];
    char modification[100];
     int ret  = 0;
     Eleve* tmp;
     int enCours = -1;
     char aModifier ;

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
                    printf("\nQue voulez-vous modifier ?? \n");
                    printf("-1- Nom\n");
                    printf("-2- Prenom\n");
                    printf("-3- Promotion\n");
                    aModifier = getch();
                    switch(aModifier){
                        case '1':
                            printf("Saisissez le nom : ");
                            fgets(modification, 99, stdin);
                            modification[strlen(modification)-1] = '\0';
                            strcpy(tmp->nom, modification);
                            break;
                        case '2':
                            printf("Saisissez le prenom : ");
                            fgets(modification, 99, stdin);
                            modification[strlen(modification)-1] = '\0';
                            strcpy(tmp->prenom, modification);
                            break;
                        case '3':
                            printf("Saisissez la promotion : ");
                            fgets(modification, 99, stdin);
                            modification[strlen(modification)-1] = '\0';
                            strcpy(tmp->promotion, modification);
                            break;
                    }
                    if(strlen(modification) > 0){
                        APP_creationEleve__modifierEleve(tmp);
                        enCours = 15;
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

 /**
  * propose d'ajouter une note à un élève dans la base
  *
  * @author mathieu
  */
 void IHM_afficheEleve__ajouterNoteEleve(){
     char idSaissie[20];
     int ret  = 0;
     Eleve* tmp;
     Notes* tmpNote;
     int enCours = -1;
     double note = 0.0, coeff = 0.0;

     while(enCours == -1){
         printf("\nSaisissez l\'ID de l\'eleve pour y ajouter une note : ");
         fgets(idSaissie, 19, stdin);
         ret = atoi(idSaissie);
         tmp = APP_creationEleve__getOneEleve(ret);
        if(ret != 0 ){
             if(tmp == NULL){
               // printf("NULL ?? %s\n",tmp->nom);
               printf("\nAucun eleve ne porte cet Identifiant\n");
             }else if(tmp != NULL){
                 strcpy(idSaissie,"");
                 printf("Saisissez la note : ");
                 fgets(idSaissie, 19, stdin);
                 note = atof(idSaissie);

                 strcpy(idSaissie,"");
                 printf("\nSaisissez le coefficient : ");
                 fgets(idSaissie,19, stdin);
                 coeff = atof(idSaissie);

                 if(coeff != 0.0 && note != 0.0){
                    tmpNote = APP_creationNotes__createNote(note,coeff,tmp->id);
                    APP_creationNotes__saveNote(tmpNote);
                    enCours = 13;
                 }

             }
             //break;
        }else if(ret == 0){
            enCours = 10;
            break;
        }
     }
 }

 /**
  * affiche le Détail d'un élève (Nom, prenom, promotion, notes , moyenne)
  *
  * @author mathieu
  */
 void IHM_afficheEleve__detaillerEleve(){
    char idSaissie[20];
     int ret  = 0;
     Eleve* tmp;
     int enCours = -1;
     int nbNotes = 0;
     double moy = 0.0, sommeCoeff = 0.0;
     int i = 0;

     while(enCours == -1){
         printf("\nSaisissez l\'ID de l\'eleve pour y ajouter une note : ");
         fgets(idSaissie, 19, stdin);
         ret = atoi(idSaissie);
         tmp = APP_creationEleve__getOneElevePlusNotes(ret);
        if(ret != 0 ){
             if(tmp == NULL){
               // printf("NULL ?? %s\n",tmp->nom);
               printf("\nAucun eleve ne porte cet Identifiant\n");
             }else if(tmp != NULL){
                 nbNotes = App_creationNotes__getNombreNote(ret);
                 if(nbNotes > 0){
                    printf("\n Informations eleve : \n");
                    printf("\n - %s %s promotion : %s \n",tmp->prenom, tmp->nom, tmp->promotion);
                    printf("\n Notes : \n");


                    for(i = 0 ; i < nbNotes ; i++){
                        printf(" Note %d : %.2f | coefficient : %.2f\n",(i+1) , tmp->listesNotes[i]->note, tmp->listesNotes[i]->coeff);
                        moy += (tmp->listesNotes[i]->note * tmp->listesNotes[i]->coeff);
                        sommeCoeff += (tmp->listesNotes[i]->coeff);
                    }
                    printf("\t ----- \n");
                    printf("Moyenne = %.2f\n",(moy/sommeCoeff));
                    enCours = 21;
                 }else{
                    printf("Pas de notes pour %s %s \n", tmp->prenom, tmp->nom);
                    //enCours = 17;
                 }
                 //break;
             }
        }else if(ret == 0){
            enCours = 10;
            break;
        }
    }
 }
