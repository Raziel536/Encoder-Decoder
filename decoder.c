/*
 * Daniil Kurov KMBO-02-20
 */

#include "functions.h"
#include "encryption.h"

#define METHOD_SZ 12
#define TEXT_SZ 128
#define KEY_SZ 20


int main(int argc, char** argv) {
	char method[METHOD_SZ];
	char text[TEXT_SZ];
	char key[KEY_SZ];
	if (argc == 1) {
		printf("Input method of encrypt [-caesar|-xor]: ");
		scanf("%s", method);
        printf("Input text: ");
		scanf("%s", text);
		printf("Input key: ");
		scanf("%s", key);
	} else {
		strcpy(method, argv[1]);
		strcpy(text, argv[2]);
		strcpy(key, argv[3]);
	}
	mutableToLower(method);
	if (strcmp(method, "-caesar") == 0) {
		if (!numberChecker(key)) {
			printf("Caesar offset key error - not a number\n");
			return -1;
		} else if (!wordChecker(text)) {
            printf("Text error - its not a word");
            return -2;
        }
        mutableCaesar(text, -(atoi(key)));
	} else if (strcmp(method, "-xor") == 0) {
		mutableXOR(text, key);
	} else {
		printf("Error - wrong method\n");
		return -3;
	}
	printf("Decoded string: %s\n", text);
	return 0;
}
