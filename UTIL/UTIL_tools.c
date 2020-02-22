/*
 *UTIL_tools.c
 *
 * Created on: 22 feb. 2020
 *      Author: Mathieu
 */

 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>

/**
 * Met en minuscule une chaine de caractères sans modifier la source
 *
 * @param dest : char*
 * @param src : char* chaine à convertir
 * @return : result --> le résultat de la conversion
 * @author mathieu
 */
 char * strtolower( char * dest, const char * src ) {
    char* result = dest;
    while( *dest++ = tolower(*src++));
    return result;
}
