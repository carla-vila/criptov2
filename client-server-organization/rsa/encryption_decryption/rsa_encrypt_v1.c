#include <stdio.h>
#include "../config/client_key.h"
#include <gmp.h>
#include <stdlib.h>
#include "rsa_encrypt.h"

extern mpz_t server_public_key_e, server_public_key_n;
void initPublicKeyServer();

void rsa_encrypt(mpz_t ciphertext, mpz_t plaintext, mpz_t e, mpz_t n) {
    mpz_powm(ciphertext, plaintext, e, n); // Encryption: ciphertext = plaintext^e mod n
}

char* rsa_encrypt_message(const char* message) {
    mpz_t msg, ciphertext;
    char *encrypted_msg = NULL;
    size_t size;

    printf("Initializing mpz variables...\n");
    mpz_inits(msg, ciphertext, NULL);

    if (mpz_set_str(msg, message, 10) != 0) {
        printf("Error: Conversion of message to mpz failed.\n");
        mpz_clears(msg, ciphertext, NULL);
        return NULL;
    }

    printf("Encrypting message...\n");
    rsa_encrypt(ciphertext, msg, server_public_key_e, server_public_key_n);
    size = mpz_sizeinbase(ciphertext, 10) + 2;
    printf("Allocating memory for encrypted message...\n");
    encrypted_msg = malloc(size * sizeof(char));
    if (encrypted_msg == NULL) {
        printf("Error: Memory allocation failed.\n");
        mpz_clears(msg, ciphertext, NULL);
        return NULL;
    }

    printf("Converting ciphertext to string...\n");
    mpz_get_str(encrypted_msg, 10, ciphertext);
    printf("Clearing mpz variables...\n");
    mpz_clears(msg, ciphertext, NULL); 
    return encrypted_msg;
}