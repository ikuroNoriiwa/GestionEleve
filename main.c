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
 #include "DATA/DATA_save.h"

 int main(void){

     printf(" void");
     Eleve* newEleve = createEleve("PETIT","Jean","3SI2");

     printf("nom : %s \n",newEleve->nom);

    initDB();
    //saveEleve(newEleve);
    getEleve();
    return EXIT_SUCCESS;
 }
