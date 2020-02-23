/*
 *DATA_save.c
 *
 * Created on: 16 feb. 2020
 *      Author: Mathieu
 */

 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
 #include "../sqlite/sqlite3.h"
 #include "../defStruct.h"
 #include "../UTIL/UTIL_tools.h"
 //ne pas oublier d'inclure Sqlite
 #include "../sqlite/sqlite3.h"

/**
 * Initialise la base de donn�es, si la base n'est pas cr��e, appelle la
 * fonction DATA_save__createDatabase()
 * @author mathieu
 */
void DATA_save__initDB(){
 //fonction au d'emarrage de l'appli

    sqlite3 *db;
    char* messageError = NULL;
    printf("[INITDB]");
    if(sqlite3_open_v2("SaveEleveNotes.sql",&db, SQLITE_OPEN_READONLY,NULL) != 0){
        DATA_save__createDatabase();
    }else{
        //printf("[DEBUG] base bien cree ");
    }
    sqlite3_close(db);
}

/**
 * Cr�e la Base de donn�es, appel� uniquement depuis la fonction DATA_save__initDB()
 * @author mathieu
 */
int DATA_save__createDatabase(){
    sqlite3 *db;
    char* messageError = NULL;
    int codeRetour = 0;

    if(codeRetour = sqlite3_open_v2("SaveEleveNotes.sql", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL ) != 0){
        printf("[ERROR] DATA_createDatabase() -- Creation : %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 0x001;
        //[DATA_createDataBase]
    }

    //Creation des differentes tables

    codeRetour = sqlite3_exec(db, "CREATE TABLE Eleve(pk_ID integer PRIMARY KEY AUTOINCREMENT, Nom varchar, Prenom varchar, Promotion varchar);", NULL, 0, &messageError );
    if((codeRetour != 0 )&& (messageError =! NULL)){
        sqlite3_free(messageError);
        messageError = NULL;
    }

    codeRetour = sqlite3_exec(db, "CREATE TABLE Note(fk_IDEleve integer, Note float, Coeff float);", NULL, 0, &messageError );
    if((codeRetour != 0 )&& (messageError =! NULL))
        {
        sqlite3_free(messageError);
        messageError = NULL;
    }

    sqlite3_close(db);
}

/**
 * Permet de sauvegarder un �l�ve dans la base de donn�es SaveEleveNotes.sql ouverte en LECTURE / ECRITURE
 *
 * @param tmp : Eleve* --> un �l�ve d�j� initialis� avec un id = 0
 * @return : 0x001 si probl�me d'ouverture de la base
 * @author mathieu
 */
void DATA_save__saveEleve(Eleve* tmp){
    sqlite3 *db;
    char* messageError = NULL;
    int codeRetour = 0;
    char* tmpLower[200];
    char* tmpLower2[200];
    char* tmpLower3[200];

     if(codeRetour = sqlite3_open_v2("SaveEleveNotes.sql", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL ) != 0){
        printf("[ERROR] DATA_saveEleve()  : %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 0x001;
        //[DATA_saveEleve]
    }

    //Insertion de l'eleve
    printf("[DATA_saveEleve] nom : %s , prenom : %s \n",tmp->nom,tmp->prenom);
    char* query  = sqlite3_mprintf("INSERT INTO Eleve(Nom, Prenom, Promotion) VALUES('%q','%q','%q');",strtolower(tmpLower,tmp->nom), strtolower(tmpLower2,tmp->prenom), strtolower(tmpLower3,tmp->promotion));
    codeRetour = sqlite3_exec(db,query, NULL, 0, &messageError );
    if((codeRetour != 0 )&& (messageError =! NULL)){
        sqlite3_free(messageError);
        messageError = NULL;
    }

    sqlite3_close(db);


}

/**
 * R�cup�re tous les �l�ves pr�sents dans la base SaveEleveNotes.sql
 *
 * @return : 0x001 si probl�me d'ouverture de la base
 * ou un Eleve** correspondant � un tableau avec tous les �l�ves
 * @author mathieu
 */
Eleve** DATA_save__getEleve(){
    sqlite3 *db;
    char* messageError = NULL;
    int codeRetour = 0;
    sqlite3_stmt *requete;
    char* query = "SELECT * FROM Eleve;";
    Eleve** newEleve;


     if(codeRetour = sqlite3_open_v2("SaveEleveNotes.sql", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL ) != 0){
        printf("[ERROR] DATA_getEleve()  : %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 0x001;
        //[DATA_saveEleve]s
    }
    if(!(codeRetour = sqlite3_prepare_v2(db, query, strlen(query), &requete, NULL))){
        newEleve = (Eleve*)malloc(sizeof(Eleve)*DATA_save__retNbValTable_eleve());
        int i = 0;
        while(codeRetour == SQLITE_OK || codeRetour == SQLITE_ROW){
            codeRetour = sqlite3_step(requete);
            if(codeRetour == SQLITE_OK || codeRetour == SQLITE_ROW){
               // printf("Nom : %s et Prenom : %s et ID =  %d\n ",sqlite3_column_text(requete,1),sqlite3_column_text(requete,2),sqlite3_column_int(requete,0));
                newEleve[i] = createEleve(sqlite3_column_text(requete,1),sqlite3_column_text(requete,2), sqlite3_column_text(requete,3),sqlite3_column_int(requete,0));
                i++;
            }
        }
        sqlite3_finalize(requete);
    }
    sqlite3_close(db);
    return newEleve;
}

/**
 * R�cup�re le nombre d'�l�ves pr�sentsdans la base  SaveEleveNotes.sql
 *
 * @return : 0x001 si probl�me d'ouverture de la base
 * ou un int correspondant au nombre d'�l�ves dans la base
 * @author mathieu
 */
int DATA_save__retNbValTable_eleve(){
    sqlite3 *db;
    char* messageError = NULL;
    int codeRetour = 0;
    sqlite3_stmt *requete;
    char* query = "SELECT COUNT(*) FROM Eleve;";
    int ret = 0 ;

     if(codeRetour = sqlite3_open_v2("SaveEleveNotes.sql", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL ) != 0){
        printf("[ERROR] DATA_retNbValTab()  : %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 0x001;
    }

    if(!(codeRetour = sqlite3_prepare_v2(db, query, strlen(query), &requete, NULL))){
        while(codeRetour == SQLITE_OK || codeRetour == SQLITE_ROW){
            codeRetour = sqlite3_step(requete);
            if(codeRetour == SQLITE_OK || codeRetour == SQLITE_ROW){
                ret = sqlite3_column_int(requete,0);
            }
        }
        sqlite3_finalize(requete);
    }
    sqlite3_close(db);
    return ret;
}

/**
 * R�cup�re le nombre de notes pr�sentes dans la base SaveEleveNotes.sql pour un �l�ve
 *
 * @param id : int correspondant � l'id de l'�l�ve dont on souhaite avoir les notes
 * @return : 0x001 si probl�me d'ouverture de la base
 * ou un int correspondant au nombre de notes de l'�l�ve dans la base
 * @author mathieu
 */
int DATA_save__retNbValTable_note(int id){
    sqlite3 *db;
    char* messageError = NULL;
    int codeRetour = 0;
    sqlite3_stmt *requete;
    char* query = sqlite3_mprintf("SELECT COUNT(*) FROM Note WHERE fk_IDEleve = '%d';",id);
    int ret = 0 ;

     if(codeRetour = sqlite3_open_v2("SaveEleveNotes.sql", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL ) != 0){
        printf("[ERROR] DATA_retNbValTab()  : %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 0x001;
    }

    if(!(codeRetour = sqlite3_prepare_v2(db, query, strlen(query), &requete, NULL))){
        while(codeRetour == SQLITE_OK || codeRetour == SQLITE_ROW){
            codeRetour = sqlite3_step(requete);
            if(codeRetour == SQLITE_OK || codeRetour == SQLITE_ROW){
                ret = sqlite3_column_int(requete,0);
            }
        }
        sqlite3_finalize(requete);
    }
    sqlite3_close(db);
    return ret;
}

/**
 * R�cup�re toutes les notes pr�sentes dans la base SaveEleveNotes.sql pour un �l�ve donn�
 *
 * @return : 0x001 si probl�me d'ouverture de la base
 * ou un Notes** correspondant � un tableau avec toutes les notes d'un �l�ve
 * @author mathieu
 */
Notes** DATA_save__getNotes(int idEleve){
    sqlite3 *db;
    char* messageError = NULL;
    int codeRetour = 0;
    sqlite3_stmt *requete;
    printf("getNotessss");
    char* query = sqlite3_mprintf("SELECT * FROM Note WHERE fk_IDEleve = '%d';", idEleve);
    Notes** newNotes;

    printf("[DATA] GETNOTE");
     if(codeRetour = sqlite3_open_v2("SaveEleveNotes.sql", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL ) != 0){
        printf("[ERROR] DATA_getNotes()  : %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 0x001;
        //[DATA_saveEleve]s
    }
    if(!(codeRetour = sqlite3_prepare_v2(db, query, strlen(query), &requete, NULL))){
        newNotes = (Notes*)malloc(sizeof(Notes)*DATA_save__retNbValTable_note(idEleve));
        int i = 0;
        while(codeRetour == SQLITE_OK || codeRetour == SQLITE_ROW){
            codeRetour = sqlite3_step(requete);
            if(codeRetour == SQLITE_OK || codeRetour == SQLITE_ROW){
                printf("\n\nNom : %s et Prenom : %s et ID =  %d\n ",sqlite3_column_text(requete,1),sqlite3_column_text(requete,2),sqlite3_column_int(requete,0));
                newNotes[i] = APP_creationNotes__createNote(atof(sqlite3_column_text(requete,1)),atof(sqlite3_column_text(requete,2)), sqlite3_column_int(requete,0));
                printf("tmptest : %f et coeff : %f ", newNotes[i]->note, newNotes[i]->coeff);
                i++;
            }
        }
        sqlite3_finalize(requete);
    }
    sqlite3_close(db);
    return newNotes;
}

/**
 * Permet de sauvegarder une note dans la base de donn�es SaveEleveNotes.sql ouverte en LECTURE / ECRITURE
 *
 * @param tmp : Notes* --> une ntoe d�j� initialis� avec l'id d'un �l�ve
 * @return : 0x001 si probl�me d'ouverture de la base
 * @author mathieu
 */
void DATA_save__saveNote(Notes* tmp){
    sqlite3 *db;
    char* messageError = NULL;
    int codeRetour = 0;

     if(codeRetour = sqlite3_open_v2("SaveEleveNotes.sql", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL ) != 0){
        printf("[ERROR] DATA_saveNote()  : %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 0x001;
        //[DATA_saveEleve]
    }

    //Insertion de l'eleve
    printf("[DATA_saveNote] Note : %f , coeff : %f \n",tmp->note,tmp->coeff);

    char* query  = sqlite3_mprintf("INSERT INTO Note(fk_IDEleve, Note, Coeff) VALUES('%d','%.2f','%.2f');",tmp->idEleve, tmp->note, tmp->coeff);
    codeRetour = sqlite3_exec(db,query, NULL, 0, &messageError );
    if((codeRetour != 0 )&& (messageError =! NULL)){
            printf("error ; %s\n",messageError);
        sqlite3_free(messageError);
        messageError = NULL;
    }

    sqlite3_close(db);
}

/**
 * Permet de supprimer un �l�ve, et donc par cons�quent les notes qui lui sont attribu�es dans la base
 * de donn�es SaveEleveNotes.sql ouverte en LECTURE / ECRITURE
 *
 * @param idEleve : int --> id de l'�l�ve � supprimer dans la base
 * @return : 0x001 si probl�me d'ouverture de la base
 * @author mathieu
 */
void DATA_save__supprimerEleve(int idEleve){
    sqlite3 *db;
    char* messageError = NULL;
    int codeRetour = 0;
    char* queryEleve = sqlite3_mprintf("DELETE FROM Eleve WHERE pk_ID = '%d';", idEleve);
    char* queryNote = sqlite3_mprintf("DELETE FROM Note WHERE fk_IDEleve = '%d';", idEleve);

    if(codeRetour = sqlite3_open_v2("SaveEleveNotes.sql", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL ) != 0){
        printf("[ERROR] DATA_getNotes()  : %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 0x001;
        //[DATA_saveEleve]s
    }

    codeRetour = sqlite3_exec(db,queryNote, NULL, 0, &messageError );
    if((codeRetour != 0 )&& (messageError =! NULL)){
        sqlite3_free(messageError);
        messageError = NULL;
    }

    codeRetour = sqlite3_exec(db,queryEleve, NULL, 0, &messageError );
    if((codeRetour != 0 )&& (messageError =! NULL)){
        sqlite3_free(messageError);
        messageError = NULL;
    }

    sqlite3_close(db);
}

/**
 * R�cup�re Un �l�ves pr�sents dans la base SaveEleveNotes.sql
 *
 * @param idEleve :
 * @return : 0x001 si probl�me d'ouverture de la base
 * ou un Eleve** correspondant � un tableau avec tous les �l�ves
 * @author mathieu
 */
Eleve* DATA_save__getOneEleve(int idEleve){
    sqlite3 *db;
    char* messageError = NULL;
    int codeRetour = 0;
    sqlite3_stmt *requete;
    char* queryCount = sqlite3_mprintf("SELECT COUNT (*) FROM Eleve WHERE pk_ID = '%d';",idEleve);
    int count = -1;
    char* query = sqlite3_mprintf("SELECT * FROM Eleve WHERE pk_ID = '%d';",idEleve);
    Eleve* newEleve = NULL;


     if(codeRetour = sqlite3_open_v2("SaveEleveNotes.sql", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL ) != 0){
        printf("[ERROR] DATA_getOneEleve()  : %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 0x001;
        //[DATA_saveEleve]s
    }
    if(!(codeRetour = sqlite3_prepare_v2(db, queryCount, strlen(queryCount), &requete, NULL))){
        //printf("DATA COUNT : %d\n", sqlite3_step(requete));
        while(codeRetour == SQLITE_OK || codeRetour == SQLITE_ROW){
            codeRetour = sqlite3_step(requete);

            if(codeRetour == SQLITE_OK || codeRetour == SQLITE_ROW){
                count = sqlite3_column_int(requete,0);
            }
        }
        if(count > 0){
            if(!(codeRetour = sqlite3_prepare_v2(db, query, strlen(query), &requete, NULL))){

                while(codeRetour == SQLITE_OK || codeRetour == SQLITE_ROW){
                    codeRetour = sqlite3_step(requete);
                    if(codeRetour == SQLITE_OK || codeRetour == SQLITE_ROW){
                       // printf("Nom : %s et Prenom : %s et ID =  %d\n ",sqlite3_column_text(requete,1),sqlite3_column_text(requete,2),sqlite3_column_int(requete,0));
                        newEleve = createEleve(sqlite3_column_text(requete,1),sqlite3_column_text(requete,2), sqlite3_column_text(requete,3),sqlite3_column_int(requete,0));
                    }
                }
            }
        }else{
            newEleve = NULL;
        }
        sqlite3_finalize(requete);
    }
    sqlite3_close(db);
    return newEleve;
}


void DATA_save__modifierEleve(Eleve* tmpEleve){
    sqlite3 *db;
    char* messageError = NULL;
    int codeRetour = 0;
    char* query = sqlite3_mprintf("UPDATE Eleve SET Nom = '%q', Prenom = '%q', Promotion = '%q' WHERE pk_ID = %d",tmpEleve->nom,tmpEleve->prenom,tmpEleve->promotion,tmpEleve->id);

    if(codeRetour = sqlite3_open_v2("SaveEleveNotes.sql", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL ) != 0){
        printf("[ERROR] DATA_getNotes()  : %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 0x001;
        //[DATA_saveEleve]s
    }

    codeRetour = sqlite3_exec(db,query, NULL, 0, &messageError );
    if((codeRetour != 0 )&& (messageError =! NULL)){
        sqlite3_free(messageError);
        messageError = NULL;
    }
    sqlite3_close(db);
}
