#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>


extern mpz_t server_public_key_e, server_public_key_n;
void initPublicKeyServer();

void rsa_encrypt(mpz_t ciphertext, mpz_t plaintext, mpz_t e, mpz_t n) {
    printf("Inside rsa_encrypt...\n");
    // Print the values of e and n
    gmp_printf("Value of e: %Zd\n", e);
    gmp_printf("Value of n: %Zd\n", n);

    mpz_powm(ciphertext, plaintext, e, n); // Encryption: ciphertext = plaintext^e mod n
}

char* rsa_encrypt_message(const char* message) {
    initPublicKeyServer();
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
    gmp_printf("Valor de p: %Zd\n", server_public_key_e);
    gmp_printf("Valor de q: %Zd\n", server_public_key_n);
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

