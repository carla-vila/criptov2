#ifndef KEYS_H
#define KEYS_H

#include <gmp.h>

// Define global variables for primes
extern mpz_t client_p;
extern mpz_t client_q;
extern mpz_t server_p;
extern mpz_t server_q;

void initPrimes();

#endif /* KEYS_H */