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
 #include "UTIL/UTIL_tools.h"
 #include "IHM/IHM_menu.h"
 #include "IHM/IHM_afficheEleve.h"

 int main(void){
     system("mode con lines=55 cols=96");
     char choixMenu ;
     while(1){
         IHM_menu__startApp();
         choixMenu = IHM_menu__choixMenu();
         printf("%c",choixMenu);
         switch(choixMenu){
            case '1' :
                IHM_menu__entete();
                IHM_afficheEleve__afficherTousEleves();
                system("pause");
                break;
            case '2' :
                IHM_menu__entete();
                IHM_afficheEleve__ajouterEleve();
                system("pause");
                break;
            case '3' :
                IHM_menu__entete();
                IHM_afficherEleve__supprimerEleve();
                system("pause");
                break;
            case '4' :
                IHM_menu__entete();
                IHM_afficheEleve__modifierEleve();
                break;
            case '5' :
                IHM_menu__entete();
                IHM_afficheEleve__ajouterNoteEleve();
                break;
            case '6' :
                IHM_menu__entete();
                break;
            case '0' :
                exit(0);
                break;
         }
     }


    /* printf(" void");
    DATA_save__initDB();
     Eleve* newEleve = createEleve("GABIN","Petit","3SI2");
     Eleve* newEleve2 = createEleve("MICHEL","Mathieu","3SI2");
     DATA_save__saveEleve(newEleve2);
     DATA_save__saveEleve(newEleve);
     Notes* newNote = createNote(19.4,1.2,1);
     Notes* newNote2 = createNote(6.0,0.25,1);
     Notes* newNote3 = createNote(12.2,2.0,1);
     Notes* newNote4 = createNote(16.3,1.0,2);
    // int i = 0;
    // saveNote(newNote);
    //saveNote(newNote2);
    //saveNote(newNote3);
    //saveNote(newNote4);

    Eleve** tabEleves = DATA_save__getEleve();
    Notes** tabNotes = DATA_save__getNotes(1);


    int i= 0;
    //saveEleve(newEleve);
    //newEleve = getEleve();

    for(i = 0 ; i < DATA_save__retNbValTable_eleve() ; i++){
        printf("\n\n[ACCEUIL]nom : %s \n",tabEleves[i]->nom);
    }

    for(i = 0; i < DATA_save__retNbValTable_note(1) ; i++){
        printf("Note %d eleve %s : %.2f\n",i,tabEleves[0]->nom,tabNotes[i]->note);
    }*/

    //DATA_save__supprimerEleve(1);
    /*
    char* src = "NOYELLE";
    char* src1 = "ASdASDASD";
    char* src2 = "ASDJHAGCJKLA";
    char* dest[100] ;
    printf("TEST TOLOWER 1 %s\n",strtolower(dest,src));
    printf("TEST TOLOWER 2 %s\n",strtolower(dest,src1));
    printf("TEST TOLOWER 3 %s\n",strtolower(dest,src2));*/
    //printf("deuxieme fonction");
    //newNote = getNotes(1);


    return EXIT_SUCCESS;
 }
