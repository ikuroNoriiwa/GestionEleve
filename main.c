/*
 * main.c
 *
 * Created on: 02 feb. 2020
 *      Author: Mathieu
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "defStruct.h"
 #include "APP/APP_creationNotes.h"
 #include "DATA/DATA_save.h"

 int main(void){

     printf(" void");
     Notes** newNote /*= createEleve("PETIT","Jean","3SI2")*/;
   // int i = 0;
    initDB();
    //saveEleve(newEleve);
    //newEleve = getEleve();

    /*for(i = 0 ; i < 2 ; i++){
        printf("nom : %s \n",newEleve[i]->nom);
    }*/
    newNote = getNotes(1);
    //newNote = createNote(12.4 , 8.2 , 1);
    printf("Note : %f, Coeff : %f id = %d\n",newNote[0]->note, newNote[0]->coeff, newNote[0]->idEleve);
    //saveNote(newNote);

    return EXIT_SUCCESS;
 }
