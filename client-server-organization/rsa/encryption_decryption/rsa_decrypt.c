#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>
#include "rsa_decrypt.h"

extern mpz_t server_private_key_d, server_private_key_n;
void initPrivateKeyServer();

void rsa_decrypt(mpz_t plaintext, mpz_t ciphertext, mpz_t d, mpz_t n) {
    printf("Inside rsa_decrypt...\n");

    // Print the values of d and n
    gmp_printf("Value of d: %Zd\n", d);
    gmp_printf("Value of n: %Zd\n", n);

    mpz_powm(plaintext, ciphertext, d, n); // Decryption: plaintext = ciphertext^d mod n
}

char* rsa_decrypt_message(const char* ciphertext) {
    initPrivateKeyServer();
    mpz_t msg_plaintext, msg_ciphertext;
    char *decrypted_msg = NULL;
    size_t size;

    printf("Initializing mpz variables...\n");
    mpz_inits(msg_plaintext, msg_ciphertext, NULL);

    // Assuming the ciphertext is already a number in string format
    if (mpz_set_str(msg_ciphertext, ciphertext, 10) != 0) {
        printf("Error: Conversion of ciphertext to mpz failed.\n");
        mpz_clears(msg_plaintext, msg_ciphertext, NULL);
        return NULL;
    }

    printf("Decrypting message...\n");
    rsa_decrypt(msg_plaintext, msg_ciphertext, server_private_key_d, server_private_key_n);
    size = mpz_sizeinbase(msg_plaintext, 10) + 2;
    printf("Allocating memory for decrypted message...\n");
    decrypted_msg = malloc(size * sizeof(char));
    if (decrypted_msg == NULL) {
        printf("Error: Memory allocation failed.\n");
        mpz_clears(msg_plaintext, msg_ciphertext, NULL);
        return NULL;
    }

    printf("Converting plaintext to string...\n");
    mpz_get_str(decrypted_msg, 10, msg_plaintext);
    printf("Clearing mpz variables...\n");
    mpz_clears(msg_plaintext, msg_ciphertext, NULL);
    return decrypted_msg;
}