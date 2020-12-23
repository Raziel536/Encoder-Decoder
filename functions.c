/*
 * Kurov Daniil KMBO-02-20
 */

#include "functions.h"


void mutableToUpper(char* string) {
    int i;
    int k = strlen(string);
    for (i = 0; i < k; ++i) {
        string[i] = toupper(string[i]);
    }
}


char* immutableToUpper(const char* string){
    int i;
    const int k = strlen(string) + 1;
    char* newString = malloc (sizeof(char) * k);
    if (newString == NULL) {
        printf("Error - Out of memory\n");
    }
    strcpy(newString, string);
    mutableToUpper(newString);
    return newString;
}


void mutableToLower (char* string) {
    int i;
    int k = strlen(string);
    for (i = 0; i < k; ++i) {
        string[i] = tolower(string[i]);
    }
}


char* immutableToLower (const char* string) {
    int i;
    const int k = strlen(string) + 1;
    char* newString = malloc (sizeof(char) * k);
    if (newString == NULL) {
        printf("Error - Out of memory\n");
    }
    strcpy(newString, string);
    mutableToLower(newString);
    return newString;
}


void mutableStrip(char* string) {
    int begin = 0;
    int end;
    int k, i;
    if (strlen(string) == 0) { 
        k = 0;
    } else {
            end = strlen(string) - 1;
            while(string[begin] == ' ') {
                if(string[begin + 1] == '\0') {
                    break;
                }
                ++begin;
            }
            if(begin == end) {
                k = 0;
            } else {
                    while (string[end] == ' ') {
                            --end;
                    }
                    k = end - begin + 1;    
                    for (i = 0; i < k; ++i) {
                            string[i] = string[i + begin];
                    }
            }
    }
    string[k] = '\0';
}


char* immutableStrip(const char* string) {
    const int k = strlen(string) + 1;
    char* newString = (char*) malloc(k * sizeof(char));
    if (newString == NULL) {
        printf("Error - out of memory\n");
    }
    strcpy(newString, string);
    mutableStrip(newString);
    return newString;
}


void mutableStripAll(char* string) {
    int i = 0, j = 0;
    int k = strlen(string);
    for (i = 0; i < k; ++i) {
        if (string[i] != ' ') {
            string[j + 1] = string[i];
        }
    }
    string[j] = '\0';
}


char* immutableStripAll (const char* string) {
    const int k = strlen(string) + 1;
    char* newString = (char*) malloc(k * sizeof(char));
    if (newString == NULL) {
        printf("Error - out of memory\n");
    }
    strcpy(newString, string);
    mutableStripAll(newString);
    return newString;
}


void mutableFilterString(char* string) {
    int i = 0, j = 0;
    int k = strlen(string);
    for(i = 0; i < k; ++i) {
            if(string[i] != ' ' && !isalpha(string[i]) && !isdigit(string[i])) {
                string[j + 1] = string[i];
        }
    }
    string[j] = '\0';
}


char* immutableFilterString(const char* string) {
    const int k = strlen(string) + 1;
    char* newString = (char*) malloc(k * sizeof(char));
    if (newString == NULL) {
        printf("Error - out of memory\n");
    }
    strcpy(newString, string);
    mutableFilterString(newString);
    return newString;
}


bool numberChecker(const char* string) {
    int i;
    const int k = strlen(string);
    if (string[i] == '-') {
        i++;
    }
    for (; i < k; ++i) {
         if (!isdigit(string[i])) {
             return false;
         }
    }
    return true;
}


bool wordChecker(const char* string) {
    int i;
    const int k = strlen(string);
    for (i = 0; i < k; ++i) {
        if (!isalpha(string[i])) {
            return false;
        }        
    }
    return true;    
}
