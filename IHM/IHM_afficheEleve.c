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
    printf("\nSaisir le nom : ");
    fgets(nom, 79,stdin);
    printf("\nSaisir le prenom : ");
    fgets(prenom, 79,stdin);
    printf("\nSaisir la promotion : ");
    fgets(promotion, 79,stdin);

    while(choix != 'y' || choix != 'n' ||
          choix != 'Y' || choix != 'N' ||
          choix != 'o' || choix != 'O'   ){
            printf("Etes-vous sur de vouloir entrer l\'eleve %s %s de la promotion %s ? (y ou n)",prenom,nom,promotion);
            choix = getch();
            printf("char : %c\n",choix);
            if(choix == 'o' || choix == 'y'){
                break;
            }
          }
 }
