/*
 * APP_creationNotes.h
 *
 * Created on: 20 feb. 2020
 *      Author: Mathieu
 */

 #ifndef APP_creationNotes_H_
 #define APP_creationNotes_H_

    Notes* APP_creationNotes__createNote(double note, double coeff, int idEleve);
    void APP_creationNotes__saveNote(Notes* tmpNote);
    int App_creationNotes__getNombreNote(int idEleve);

 #endif // APP_creationNotes_H_


