/*
 * Kurov Daniil
 */
#include "encryption.h"


void mutableCaesar(char* string, const int offset) {
    bool flag = false;
    int offset_edited = offset % 26;
    int i, k = strlen(string);
    for (i = 0; i < k; ++i) {
        if(string[i] >= 'A' && string[i] <= 'Z') {
            string[i] += 'a' - 'A';
            flag = true;
        }
        if(string[i] + offset_edited > 'z') {
            string[i] -= ('z' - 'a') + 1;
        }
        if(string[i] + offset_edited < 'a') {
            string[i] += ('z' - 'a') + 1;
        }
        string[i] += offset_edited;
        if(flag) {
            string[i] -= 'a' - 'A';
            flag = false;
        }
    }
}


char* immutableCaesar(char* string, const int offset) {
    bool flag = false;
    int offset_edited = offset % 26;
    int i, k = strlen(string);
    char* new_string = malloc (sizeof(char) * (k + 1));
    strcpy(new_string, string);
    for (i = 0; i < k; ++i) {
        if(new_string[i] >= 'A' && new_string[i] <= 'Z') {
            new_string[i] += 'a' - 'A';
            flag = true;
        }
        if(new_string[i] + offset_edited > 'z') {
            new_string[i] -= ('z' - 'a') + 1;
        }
        if(new_string[i] + offset_edited < 'a') {
            new_string[i] += ('z' - 'a') + 1;
        }
        new_string[i] += offset_edited;
        if(flag) {
            new_string[i] -= 'a' - 'A';
            flag = false;
        }
    }
    return new_string;
}


void mutableXOR (char* string, const char* key) {
    int i;
    int k = strlen(string);
    int key_len = strlen(key);
    for (i = 0; i < k; ++i) {
        string[i] ^= key[i % key_len];
    }
}


char* immutableXOR (char* string, const char* key) {
    int i;
    int k = strlen(string);
    int key_len = strlen(key);
    char* new_string = malloc (sizeof(char) * (k + 1));
    strcpy(new_string, string);
    for (i = 0; i < k; ++i) {
        new_string[i] ^= key[i % key_len];
    }
    return new_string;
}
