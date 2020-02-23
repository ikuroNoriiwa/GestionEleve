/*
 *APP_creationNotes.c
 *
 * Created on: 12 feb. 2020
 *      Author: Mathieu
 */

 #include <stdlib.h>
 #include <stdlib.h>
 #include "../defStruct.h"

 /**
 * Crée et renvoie un struct Notes
 *
 * @param note : double --> note de l'élève
 * @param coeff : double --> coeff de la note
 * @param id : int --> id de l'élève
 * @return newNotes: Struct Notes* contenant les paramètres
 *
 * @author mathieu
 */
Notes* APP_creationNotes__createNote(double note, double coeff, int idEleve){
    //printf("Note : %d   \n",idEleve);
    Notes* newNotes = (Notes*)malloc(sizeof(Notes));
    newNotes->coeff = coeff;
    newNotes->note = note;
    newNotes->idEleve = idEleve;

    return newNotes;
}

/**
 *  sauvegarde en base
 *
 * @param eleve: Struct Notes* contenant toutes les infos d'une note
 *
 * @author mathieu
 */
void APP_creationNotes__saveNote(Notes* tmpNote){
    DATA_save__saveNote(tmpNote);
}

/**
 *  renvoie le nombre de Notes
 *
 * @return nbNote: int
 *
 * @author mathieu
 */
int App_creationNotes__getNombreNote(int idEleve){
    return DATA_save__retNbValTable_note(idEleve);

}
