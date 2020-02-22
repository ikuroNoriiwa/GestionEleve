/*
 *APP_creationEleve.c
 *
 * Created on: 12 feb. 2020
 *      Author: Mathieu
 */

 #include <stdlib.h>
 #include <stdlib.h>
 #include "../defStruct.h"
 #include "../DATA/DATA_save.h"

Eleve* createEleve(char* nom, char* prenom, char *promotion, int id ){
    Eleve* newEleve = (Eleve*)malloc(sizeof(Eleve));
    newEleve->nom = (char*)malloc(sizeof(char*)*sizeof(nom));
    newEleve->prenom = (char*)malloc(sizeof(char*)*sizeof(prenom));
    newEleve->promotion = (char*)malloc(sizeof(char*)*sizeof(promotion));
    newEleve->id = id;

    strcpy(newEleve->nom, nom);
    strcpy(newEleve->prenom, prenom);
    strcpy(newEleve->promotion, promotion);

    return newEleve;
}

void saveEleves(Eleve* eleve){

}

Eleve** APP_creationEleve__getAllEleves(){
    return DATA_save__getEleve();
}
 int APP_creationEleve__getNbEleve(){
    return DATA_save__retNbValTable_eleve();
 }

