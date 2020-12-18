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
    int k = strlen(string);
    char* new_string = malloc (sizeof(char) * (k + 1));
    strcpy(new_string, string);
    for (i = 0; i < k; ++i) {
        new_string[i] = toupper(string[i]);
    }
    return new_string;
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
    int k = strlen(string);
    char* new_string = malloc (sizeof(char) * (k + 1));
    strcpy(new_string, string);
    for (i = 0; i < k; ++i) {
        new_string[i] = tolower(string[i]);
    }
    return new_string;
}


void mutableStrip(char* string) {
    int begin = 0;
    int end = strlen(string) - 1;
    int k, i;
    while(string[begin] == ' ') {
        if(string[begin+1] == '\0') {
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
    }
    for (i = 0; i < k; ++i) {
        string[i] = string[i + begin];
    }
    string[k] = '\0';
}


char* immutableStrip(const char* string) {
    int begin = 0;
    int i = 0, j = 0;
    int k;
    int end = strlen(string) - 1;
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
    }
    char* result = (char*) malloc((k + 1) * sizeof(char));
    if(result == NULL) {
        printf("Malloc error - No memory\n");
    }
    for (j = 0; j < k; ++j) {
        result[j] = string[i + begin];
        i++;
    }
    result[k] = '\0';
    return result;
}


void mutableStripAll(char* string) {
    int i = 0, k, j;
    k = strlen(string);
    while(string[i] != '\0') {
        if(string[i] == ' ') {
            for(j = i; j < k-1; ++j) {
                string[j] = string [j + 1];
            }
            string[k - 1] = '\0';
            --k;
        }
        ++i;
    }
}


char* immutableStripAll (const char* string) {
    int i = 0, j = 0;
    int s = 1;
    char* result = (char*) malloc (s * sizeof(char));
    if ( result == NULL) {
        printf("Malloc error - out of memory\n");
    }
    while(string[i] == ' ') {
        i++;
    }
    while(string[i] != '\0') {
        if(string[i] == ' ') {
            i++;
            continue;
        }

        result[j] = string[i];
        j++;
        i++;
        if(j == s) {
            s++;
            result = (char*) realloc(result, s * sizeof(char));
            if (result == NULL) {
                printf("Realloc error - out of memory\n");
            }
        }
    }
    result[j] = '\0';
    return result;
}


void mutableFilterString(char* string) {
    int i = 0;
    int k, j;
    k = strlen(string);
    while(string[i] != '\0') {
        if(string[i] != ' ' && !isalpha(string[i]) && !isdigit(string[i])) {
            for(j = i; j < k-1; ++j) {
                string[j] = string [j + 1];
            }
            string[k - 1] = '\0';
            --k;
        }
        ++i;
    }
}


char* immutableFilterString(const char* string) {
    int i = 0, j = 0;
    int s = 1;
    char* result = (char*) malloc(s * sizeof(char));
    if (result == NULL) {
        printf("Malloc error - out of memory\n");
    }
    while(string[i] != '\0') {
        if(string[i] != ' ' && !isalpha(string[i]) && !isdigit(string[i])) {
            i++;
            continue;
        }
        result[j] = string[i];
        i++;
        j++;
        if(j == s) {
            s++;
            result = (char*) realloc (result, s * sizeof(char));
            if(result == NULL) {
                printf("Realloc error - out of memory\n");
            }
        }
    }
    result[j] = '\0' ;
    return result;
}


bool numberChecker(const char* string) {
int i, k;
k = strlen(string);
for (i = 0; i < k; ++i) {
    if (!isdigit(string[i])) {
        return false;
    }
    return true;
}
}


bool wordChecker(const char* string) {
int i, k;
k = strlen(string);
for (i = 0; i < k; ++i) {
    if (!isalpha(string[i])) {
        return false;
    }
    return true;
}
}
