#ifndef CLIENT_KEY_H
#define CLIENT_KEY_H
#include <gmp.h>

// Define global variables for primes
extern mpz_t server_public_key_e;
extern mpz_t server_public_key_n;

void initPublicKeyServer();

#endif /* KEYS_H */