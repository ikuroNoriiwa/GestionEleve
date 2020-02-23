/*
 *APP_creationNotes.c
 *
 * Created on: 12 feb. 2020
 *      Author: Mathieu
 */

 #include <stdlib.h>
 #include <stdlib.h>
 #include "../defStruct.h"

Notes* APP_creationNotes__createNote(double note, double coeff, int idEleve){
    //printf("Note : %d   \n",idEleve);
    Notes* newNotes = (Notes*)malloc(sizeof(Notes));
    newNotes->coeff = coeff;
    newNotes->note = note;
    newNotes->idEleve = idEleve;

    return newNotes;
}


void APP_creationNotes__saveNote(Notes* tmpNote){
    DATA_save__saveNote(tmpNote);
}


int App_creationNotes__getNombreNote(int idEleve){
    return DATA_save__retNbValTable_note(idEleve);

}
