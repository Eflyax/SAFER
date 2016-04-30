//
// Created by eflyax on 27.4.16.
//

#ifndef SAFER_CORE_H
#define SAFER_CORE_H

#define ROUNDS 6

typedef unsigned char uchar;


short key[4], S[512], S_inv[512];

uchar **K;

uchar X[9],Y[9];

uchar i ;

void SAFER_K_64_key_schedule(short *key, short *S, short *S_inv, uchar **K);

void SAFER_K_64_encryption(uchar *X, uchar *Y, short *S, short *S_inv, uchar **K);

void SAFER_K_64_decryption(uchar *X, uchar *Y, short *S, short *S_inv, uchar **K);

void f_inv(uchar L, uchar R, uchar *l, uchar *r);

void generate_S_boxes(short *S, short *S_inv);

void f(uchar x, uchar y, uchar *X, uchar *Y);

#endif //SAFER_CORE_H
