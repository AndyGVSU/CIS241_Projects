#include <stdio.h>
#include <stdlib.h>
#include "subcipher.h"

int main(int argc, char* argv[]) {

	int alphabet_count = (int) ('Z' - 'A') + 1;
	char decryptMode = (char) *argv[1];

	int i;
	char* keyTest = removeDuplicates(argv[2]);	
	char* substitution = (char*) malloc(alphabet_count * sizeof(char)); 

	if (decryptMode == 'e') {
		initializeEncryptArray(keyTest, substitution);
	}
	else if (decryptMode == 'd') {	
		char* decrypt = (char*) malloc(alphabet_count * sizeof(char));
		initializeEncryptArray(keyTest, decrypt);
		initializeDecryptArray(decrypt, substitution);
		}
	else {
		printf("\nERROR: INVALID MODE (use d or e)\n");
		exit(1);
	}
	
	FILE* fin = fopen(argv[3], "r");
	FILE* fout = fopen(argv[4], "w");
	processInput(fin, fout, substitution);
	fclose(fin);
	fclose(fout);

	return 0;
}
