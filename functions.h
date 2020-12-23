#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


void mutableToUpper(char* string);
char* immutableToUpper(const char* string);

void mutableToLower (char* string);
char* immutableToLower (const char* string);

void mutableStrip(char* string);
char* immutableStrip(const char* string);

void mutableStripAll(char* string);
char* immutableStripAll(const char* string);

void mutableFilterString(char* string);
char* immutableFilterString(const char* string);

bool numberChecker(const char* string);
bool wordChecker(const char* string);

#endif
