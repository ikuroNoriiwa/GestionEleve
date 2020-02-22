
/*
 * defStruct.h
 *
 * Created on: 12 feb. 2020
 *      Author: Mathieu
 */

 #ifndef DATA_SAVE_H_
 #define DATA_SAVE_H_

    void DATA_save__initDB();
    int DATA_save__createDatabase();
    void DATA_save__saveEleve(Eleve* tmp);
    Eleve** DATA_save__getEleve();
    int DATA_save__retNbValTable_eleve();
    int DATA_save__retNbValTable_note(int id);
    Notes** DATA_save__getNotes(int idEleve);
    void DATA_save__saveNote(Notes* tmp);
    void DATA_save__supprimerEleve(int idEleve);

 #endif // DATA_SAVE_H_
