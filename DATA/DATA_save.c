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

//ne pas oublier d'inclure Sqlite

#include "../sqlite/sqlite3.h"

void initDB(){
 //fonction au d'emarrage de l'appli

    sqlite3 *db;
    char* messageError = NULL;

    if(sqlite3_open_v2("SaveEleveNotes.sql",&db, SQLITE_OPEN_READONLY,NULL) != 0){
        createDatabase();
    }else{
        //printf("[DEBUG] base bien cree ");
    }
    sqlite3_close(db);
}


int createDatabase(){
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

void saveEleve(Eleve* tmp){
    sqlite3 *db;
    char* messageError = NULL;
    int codeRetour = 0;

     if(codeRetour = sqlite3_open_v2("SaveEleveNotes.sql", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL ) != 0){
        printf("[ERROR] DATA_saveEleve()  : %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 0x001;
        //[DATA_saveEleve]
    }

    //Insertion de l'eleve
    printf("[DATA_saveEleve] nom : %s , prenom : %s \n",tmp->nom,tmp->prenom);
    char* query  = sqlite3_mprintf("INSERT INTO Eleve(Nom, Prenom, Promotion) VALUES('%q','%q','%q');",tmp->nom, tmp->prenom, tmp->promotion);
    codeRetour = sqlite3_exec(db,query, NULL, 0, &messageError );
    if((codeRetour != 0 )&& (messageError =! NULL)){
        sqlite3_free(messageError);
        messageError = NULL;
    }

    sqlite3_close(db);


}

Eleve* getEleve(){
    sqlite3 *db;
    char* messageError = NULL;
    int codeRetour = 0;
    sqlite3_stmt *requete;
    char* query = "SELECT * FROM Eleve;";

     if(codeRetour = sqlite3_open_v2("SaveEleveNotes.sql", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL ) != 0){
        printf("[ERROR] DATA_getEleve()  : %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 0x001;
        //[DATA_saveEleve]s
    }
    printf("[DB get]");
    if(!(codeRetour = sqlite3_prepare_v2(db, query, strlen(query), &requete, NULL))){
        printf("[DB get] if1");
        while(codeRetour == SQLITE_OK || codeRetour == SQLITE_ROW){
                printf("[DB get]while : %d \n",codeRetour);
                printf("SQLITE_OK : %d\n", SQLITE_OK);
                printf("SQLITE_ROW : %d\n", SQLITE_ROW);
            codeRetour = sqlite3_step(requete);
            printf("COdeRetour = %d \n",codeRetour);
            if(codeRetour == SQLITE_OK || codeRetour == SQLITE_ROW){
                printf("Nom : %s et Prenom : %s et ID =  %d\n ",sqlite3_column_text(requete,1),sqlite3_column_text(requete,2),sqlite3_column_int(requete,0));
            }
        }
        sqlite3_finalize(requete);
    }
    sqlite3_close(db);
    return NULL;
}
