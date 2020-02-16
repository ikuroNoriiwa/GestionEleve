/*
 * APP_creationEleve.h
 *
 * Created on: 16 feb. 2020
 *      Author: Mathieu
 */

 #ifndef APP_creationEleve_H_
 #define APP_creationEleve_H_

   Eleve* createEleve(char* nom, char* prenom, char *promotion);
   void saveEleves(Eleve* eleve);
   Eleve* getAllEleves();

 #endif // APP_creationEleve_H_

