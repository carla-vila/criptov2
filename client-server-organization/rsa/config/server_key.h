#ifndef SERVER_KEY_H
#define SERVER_KEY_H
#include <gmp.h>

// Define global variables for primes
extern mpz_t server_private_key_d;
extern mpz_t server_private_key_n;

void initPrivateKeyServer();

#endif /* KEYS_H */