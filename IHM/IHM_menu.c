/*
 *IHM_menu.c
 *
 * Created on: 22 feb. 2020
 *      Author: Mathieu
 */

 #include <stdlib.h>
 #include <stdio.h>
 #include "conio.h"

void IHM_menu__affichageTitre(){
    printf(" __| |___________________________________________________________________________________| |__\n");
    printf("(__   ___________________________________________________________________________________   __)\n");
    printf("   | |    _____ _             _            _   __  __                                    | | \n");
    printf("   | |   / ____| |           | |          | | |  \\/  |                                   | |\n");
    printf("   | |  | (___ | |_ _   _  __| | ___ _ __ | |_| \\  / | __ _ _ __   __ _  __ _  ___ _ __  | |\n");
    printf("   | |   \\___ \\| __| | | |/ _` |/ _ \\ \'_ \\| __| |\\/| |/ _` | \'_ \\ / _` |/ _` |/ _ \\ \'__| | |\n");
    printf("   | |   ____) | |_| |_| | (_| |  __/ | | | |_| |  | | (_| | | | | (_| | (_| |  __/ |    | | \n");
    printf("   | |  |_____/ \\__|\\__,_|\\__,_|\\___|_| |_|\\__|_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_|    | | \n");
    printf("   | |                                                                   __/ |           | |\n");
    printf(" __| |__________________________________________________________________\\___/____________| |__\n");
    printf("(__   ___________________________________________________________________________________   __)\n");
    printf("   | |                                                                                   | | \n");


}

void IHM_menu__affichageMenuPrincipal(){
    printf("\n");
    printf("\t\t+-------------------------+ \n");
    printf("\t\t| -1- Lister les eleves   | \n");
    printf("\t\t| -2- Ajouter un eleve    |\n");
    printf("\t\t| -3- Supprimer un eleve  | \n");
    printf("\t\t| -4- Modifier un eleve   |\n");
    printf("\t\t| -5- Ajouter une note    |\n");
    printf("\t\t| -6- Detail d\'un eleve   |\n");
    printf("\t\t|                         |\n");
    printf("\t\t| -0- Quitter             |\n");
    printf("\t\t+-------------------------+ \n");


}



char IHM_menu__choixMenu() {
    char c;

    printf("\n\n\t\t\t\t Que voulez vous faire ? ");
    c = getch();// récupère la selection du clavier
    return c;
}


void IHM_menu__startApp(){
    clrscr();
    IHM_menu__affichageTitre();
    IHM_menu__affichageMenuPrincipal();
}
