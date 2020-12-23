#ifndef ENCRYPTION_H_INCLUDED
#define ENCRYPTION_H_INCLUDED


#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>


void mutableCaesar(char* string, const int offset);
char* immutableCaesar(char* string, const int offset);

void mutableXOR (char* string, const char* key);
char* immutableXOR (char* string, const char* key);

#endif // ENCRYPTION_H_INCLUDED
