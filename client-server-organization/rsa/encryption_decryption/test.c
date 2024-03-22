#include "rsa_encrypt.h"
#include "rsa_decrypt.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char* message = "6643839173115983065901696984234387152417656552510024143528035243075932039141540887560891921413152283372617392972052858355392130164398195728846682147108335529399573584722630675668028759157420693015776494121027122236227911260946427912817705343653404799866060371935100989352961648363069353334496732725087";
    char* encrypted_message = rsa_encrypt_message(message);

    if (encrypted_message != NULL) {
        printf("Encrypted message: %s\n", encrypted_message);
    } else {
        printf("Encryption failed.\n");
    }

    char* decrypted_message = rsa_decrypt_message(encrypted_message);

    if (decrypted_message != NULL) {
        printf("Decrypted message: %s\n", decrypted_message);
        free(decrypted_message);
    } else {
        printf("Decryption failed.\n");
    }

    if (encrypted_message != NULL) {
        free(encrypted_message);
    }
    return 0;
}
