#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "subcipher.h"

//remove duplicates in the given word, return the resulting string
char* removeDuplicates(char word[]) {
	int wordLength = strlen(word);

	if (wordLength == 0) {
		printf("\nKEY MUST BE PROVIDED AS STRING FOR ENCRYPTION\n");
	      	exit(1);
	}

	char* uniqueLetters = (char*) malloc(wordLength * sizeof(char));

	int i, check, foundLetter; 
	int uniqueCount = 0;
	char current;
	for(i = 0; i < wordLength; i++)	{
		check = 0;
		current = word[i];
		foundLetter = 0; //false
	
		for (check = i + 1; check < wordLength; check++) {
			if (word[check] == current)
				foundLetter = 1; //true	
		}
		if (foundLetter == 0) {
			uniqueLetters[uniqueCount] = current;
			uniqueCount++;
			}
	}
	return uniqueLetters;
}	
//search the first num characters for target, return 1
//return 0 if not found
int targetFound(char charArray[], int num, char target) {
	int i;
	char current;
	for(i = 0; i < num; i++) {
		current = charArray[i];
		if(current == target)
			return 1;
	}
	return 0;			
}
//sets up the decryption array
void initializeDecryptArray(char encrypt[], char decrypt[]) {
	int i,j;
	//fix 26?
	
	for (i = 0; i < 26; i++) {
		for (j = 0; j < 26; j++)
			if (encrypt[j] == 'A' + i)
				break;
		decrypt[i] = 'A' + j;
	}
}
//sets up an ecryption array
void initializeEncryptArray(char key[], char encrypt[]) {
	int i;
	int keyLength = strlen(key);
	for(i = 0; i < keyLength; i++)
		encrypt[i] = key[i];

	char c;
	for (c = 'Z'; c >= 'A'; c--) {
		if (targetFound(key, keyLength, c) == 0) {
			encrypt[i] = c;
			i++;
		}
	}	
}
//does the actual encryption with the given files
void processInput(FILE* inf, FILE* outf, char substitute[]) {
	if (inf == NULL || outf == NULL) {
		printf("\nFILE COULD NOT BE OPENED\n");
		exit(1);
	}

	char ch;
	while (fscanf(inf, "%c", &ch) != EOF) {
		fprintf(outf, "%c", substitute[ch - 'A']);
	}
}
