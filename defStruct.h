/*
 * defStruct.h
 *
 * Created on: 12 feb. 2020
 *      Author: Mathieu
 */

 #ifndef DEFSTRUCT_H_
 #define DEFSTRUCT_H_

    typedef struct{
        double note;
        double coeff;
        int idEleve;
    }Notes;

    typedef struct{
        int id;
        char* nom;
        char* prenom;
        char* promotion;
        Notes** listesNotes;
    }Eleve;


 #endif // DEFSTRUCT_H_
