/*
 *APP_creationEleve.c
 *
 * Created on: 12 feb. 2020
 *      Author: Mathieu
 */

 #include <stdlib.h>
 #include <stdlib.h>
 #include <string.h>
 #include "../defStruct.h"
 #include "../DATA/DATA_save.h"

/**
 * Crée et renvoie un struct Eleve
 *
 * @param nom : char* --> nom de l'élève
 * @param prenom : char* --> prenom de l'élève
 * @param promotion : char* --> promotion de l'élève
 * @param id : int --> 0 si nouvelle création, > 0 si récupéré de la base
 * @return newEleve: Struct Eleve* contenant les paramètres
 *
 * @author mathieu
 */
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

/**
 *  sauvegarde en base
 *
 * @param eleve: Struct Eleve* contenant toutes les infos d'Eleves
 *
 * @author mathieu
 */
void saveEleves(Eleve* eleve){
    DATA_save__saveEleve(eleve);
}

/**
 *  renvoie un tableau struct Eleve
 *
 * @return newEleve: Struct Eleve** contenant tous les Eleves en base
 *
 * @author mathieu
 */
Eleve** APP_creationEleve__getAllEleves(){

    return DATA_save__getEleve();
}

/**
 *  renvoie le nombre d'Eleve
 *
 * @return nbEleve: int
 *
 * @author mathieu
 */
 int APP_creationEleve__getNbEleve(){
    return DATA_save__retNbValTable_eleve();
 }

/**
 *  supprime un élève
 *
 * @param idEleve: int id de l'élève en base
 *
 * @author mathieu
 */
void APP_creationEleve__supprimerEleve(int idEleve){
    DATA_save__supprimerEleve(idEleve);
}

/**
 *  renvoie un struct Eleve
 *
 * @param idEleve : int id de l'élève en base
 * @return newEleve: Struct Eleve* contenant un Eleve en base
 *
 * @author mathieu
 */
Eleve* APP_creationEleve__getOneEleve(int idEleve){
    Eleve* tmpEleve = DATA_save__getOneEleve(idEleve);
    return tmpEleve;
}

/**
 *  modifie un élève
 *
 * @param idEleve: int id de l'élève en base
 *
 * @author mathieu
 */
void APP_creationEleve__modifierEleve(Eleve* tmpEleve){
    DATA_save__modifierEleve(tmpEleve);

}

/**
 *  renvoie un struct Eleve et ses notes
 *
 * @param idEleve : int id de l'élève en base
 * @return newEleve: Struct Eleve* contenant un Eleve en base
 *
 * @author mathieu
 */
Eleve* APP_creationEleve__getOneElevePlusNotes(int idEleve){
    Eleve* tmpEleve = DATA_save__getOneEleve(idEleve);
    tmpEleve->listesNotes = DATA_save__getNotes(idEleve);
    return tmpEleve;
}

/**
 *  renvoie un tableau struct Eleve
 *
 * @return newEleve: Struct Eleve** contenant tous les Eleves en base
 *
 * @author mathieu
 */
Eleve** APP_creationEleve__getAllElevesNOM(){

    return DATA_save__getEleve_OderByNAME();
}

/**
 *  renvoie un tableau struct Eleve
 *
 * @return newEleve: Struct Eleve** contenant tous les Eleves en base
 *
 * @author mathieu
 */
Eleve** APP_creationEleve__getAllElevesPRENOM(){

    return DATA_save__getEleve_OderByPRENOM();
}

/**
 *  renvoie un tableau struct Eleve
 *
 * @return newEleve: Struct Eleve** contenant tous les Eleves en base
 *
 * @author mathieu
 */
Eleve** APP_creationEleve__getAllElevesPROMOTION(){

    return DATA_save__getEleve_OderByPROMOTION();
}
