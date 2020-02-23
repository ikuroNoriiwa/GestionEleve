/*
 * APP_creationEleve.h
 *
 * Created on: 16 feb. 2020
 *      Author: Mathieu
 */

 #ifndef APP_creationEleve_H_
 #define APP_creationEleve_H_

   Eleve* createEleve(char* nom, char* prenom, char *promotion, int id);
   void saveEleves(Eleve* eleve);
   Eleve** APP_creationEleve__getAllEleves();
   int APP_creationEleve__getNbEleve();
   void APP_creationEleve__supprimerEleve(int idEleve);
   Eleve* APP_creationEleve__getOneEleve(int idEleve);
   void APP_creationEleve__modifierEleve(Eleve* tmpEleve)
   Eleve* APP_creationEleve__getOneElevePlusNotes(int idEleve);

 #endif // APP_creationEleve_H_

