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

 int main(void){

     printf(" void");
     Eleve* newEleve = createEleve("noyelle","mathieu","3SI2");

     printf("nom : %s \n",newEleve->nom);
     return EXIT_SUCCESS;
 }
