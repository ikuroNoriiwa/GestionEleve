/*
 *APP_creationEleve.c
 *
 * Created on: 12 feb. 2020
 *      Author: Mathieu
 */

 #include <stdlib.h>
 #include <stdlib.h>
 #include "../defStruct.h"

Eleve* createEleve(char* nom, char* prenom, char *promotion){
    Eleve* newEleve = (Eleve*)malloc(sizeof(Eleve));
    newEleve->nom = (char*)malloc(sizeof(char*)*sizeof(nom));
    newEleve->prenom = (char*)malloc(sizeof(char*)*sizeof(prenom));
    newEleve->promotion = (char*)malloc(sizeof(char*)*sizeof(promotion));
    newEleve->id = 0;

    strcpy(newEleve->nom, nom);
    strcpy(newEleve->prenom, prenom);
    strcpy(newEleve->promotion, promotion);

    return newEleve;
}

void saveEleves(Eleve* eleve){

}

Eleve* getAllEleves(){

    return NULL;
}


