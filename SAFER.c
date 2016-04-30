//
// Created by eflyax on 20.4.16.
//

#include <stdio.h>
#include <stdlib.h>
#include "core.h"

int main(void) {

	short key[4], S[512], S_inv[512];
	uchar X[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8}, Y[9];
	uchar i, **K;
	K = (uchar **) calloc(2 * ROUNDS + 3, sizeof(char *));
	for (i = 0; i < 2 * ROUNDS + 3; i++)
		K[i] = (uchar *) calloc(9, sizeof(char));
	key[0] = 256 * 8 + 7;
	key[1] = 256 * 6 + 5;
	key[2] = 256 * 4 + 3;
	key[3] = 256 * 2 + 1;

	// rozdeleni klice na podklice
	SAFER_K_64_key_schedule(key, S, S_inv, K);

	// sifrovani
	SAFER_K_64_encryption(X, Y, S, S_inv, K);

	printf("Výsledek šifrování\n");
	for (i = 1; i <= 8; i++) {
		printf("%3d ", Y[i]);
	}
	printf("\n");

	// desifrovani
	SAFER_K_64_decryption(Y, X, S, S_inv, K);

	printf("Výsledek dešifrování\n");
	for (i = 1; i <= 8; i++) {
		printf("%3d ", X[i]);
	}
	printf("\n");
	for (i = 0; i < 2 * ROUNDS + 3; i++) {
		free(K[i]);
	}
	free(K);
	return 0;
}