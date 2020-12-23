/*
 * Kurov Daniil
 */
#include "encryption.h"


void mutableCaesar(char* string, const int offset) {
    bool flag = false;
    int offsetEdited = offset % 26;
    int i;
    const int k = strlen(string);
    for (i = 0; i < k; ++i) {
        if(string[i] >= 'A' && string[i] <= 'Z') {
            string[i] += 'a' - 'A';
            flag = true;
        }
        if(string[i] + offsetEdited > 'z') {
            string[i] -= ('z' - 'a') + 1;
        }
        if(string[i] + offsetEdited < 'a') {
            string[i] += ('z' - 'a') + 1;
        }
        string[i] += offsetEdited;
        if(flag) {
            string[i] -= 'a' - 'A';
            flag = false;
        }
    }
}


char* immutableCaesar(char* string, const int offset) {   
    const int k = strlen(string) + 1;
    char* newString = (char*) malloc(k * sizeof(char));
    if (newString == NULL) {
        printf("Error - out of memory\n");
    }
    strcpy(newString, string);
    mutableCaesar(newString, offset);
    return newString;
}


void mutableXOR (char* string, const char* key) {
    int i;
    const int k = strlen(string);
    const int keyLen = strlen(key);
    for (i = 0; i < k; ++i) {
        string[i] ^= key[i % keyLen];
    }
}


char* immutableXOR (char* string, const char* key) {
    const int k = strlen(string) + 1;
    char* newString = (char *) malloc (sizeof(char) * k);
    if (newString == NULL) {
        printf("Error - out of memory\n");
    }
    strcpy(newString, string);
    mutableXOR(newString, key);
    return newString;
}
