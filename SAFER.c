//
// Created by eflyax on 20.4.16.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "core.h"

int check_user_inputs(char *user_text, char *user_key) {

	if (strlen(user_text) > 8) {
		printf("Šifrovaný text může mít maximálně 8 znaků");
		exit(1);
	}
	if (strlen(user_key) > 8) {
		printf("Heslo může mít maximálně 8 znaků");
		exit(1);
	}
	init(user_text, user_key);
}

int init(char *user_text, char *user_key) {

	strcpy(X, "12345478");
	strcpy(Y, "87654321");

	K = (uchar **) calloc(2 * ROUNDS + 3, sizeof(char *));
	for (i = 0; i < 2 * ROUNDS + 3; i++) {
		K[i] = (uchar *) calloc(9, sizeof(char));
	}
	key[0] = 256 * 8 + 7;
	key[1] = 256 * 6 + 5;
	key[2] = 256 * 4 + 3;
	key[3] = 256 * 2 + 1;

	// rozdeleni klice na podklice
	SAFER_K_64_key_schedule(key, S, S_inv, K);
}

int main(int argc, char *argv[]) {

	if (argc != 4) {
		printf("Program nebyl spuštěn se správným počtem parametrů");
	} else {
		// správný počet  parametrů
		if (strcmp(argv[1], "e") == 0) {
			printf("encryption\n");
			check_user_inputs(argv[2], argv[3]);
			SAFER_K_64_encryption(X, Y, S, S_inv, K);
		} else {
			printf("decryption\n");
			check_user_inputs(argv[2], argv[3]);
			SAFER_K_64_decryption(X, Y, S, S_inv, K);
		}
	}

	for (i = 1; i <= 8; i++) {
		printf("%3d ", Y[i]);
	}

	for (i = 0; i < 2 * ROUNDS + 3; i++) {
		free(K[i]);
	}
	free(K);
	return 0;
}