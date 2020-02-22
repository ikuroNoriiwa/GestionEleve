/*
 * main.c
 *
 * Created on: 02 feb. 2020
 *      Author: Mathieu
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "defStruct.h"
 #include "APP/APP_creationEleve.h"
 #include "APP/APP_creationNotes.h"
 #include "DATA/DATA_save.h"

 int main(void){

     printf(" void");
        initDB();
     Eleve* newEleve = createEleve("JEAN","Petit","3SI2");
     Eleve* newEleve2 = createEleve("NOYELLE","Mathieu","3SI2");
     //saveEleve(newEleve2);
     //saveEleve(newEleve);
     Notes* newNote = createNote(19.4,1.2,1);/*= createEleve("PETIT","Jean","3SI2")*/
     Notes* newNote2 = createNote(6.0,0.25,1);
     Notes* newNote3 = createNote(12.2,2.0,1);
     Notes* newNote4 = createNote(16.3,1.0,2);
   // int i = 0;
   // saveNote(newNote);
    //saveNote(newNote2);
    //saveNote(newNote3);
    //saveNote(newNote4);

    Eleve** tabEleves = getEleve();
    Notes** tabNotes = getNotes(1);


    int i= 0;
    //saveEleve(newEleve);
    //newEleve = getEleve();

    for(i = 0 ; i < retNbValTable_eleve() ; i++){
        printf("\n\n[ACCEUIL]nom : %s \n",tabEleves[i]->nom);
    }

    for(i = 0; i < retNbValTable_note(1) ; i++){
        printf("Note %d eleve %s : %.2f\n",i,tabEleves[0]->nom,tabNotes[i]->note);
    }
    //printf("deuxieme fonction");
    //newNote = getNotes(1);


    return EXIT_SUCCESS;
 }
