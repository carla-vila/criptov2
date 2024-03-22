#include "./server_key.h"
#include <gmp.h>

mpz_t server_private_key_d;
mpz_t server_private_key_n;

// Function to initialize primes
void initPrivateKeyServer() {

    mpz_init(server_private_key_d);
    mpz_init(server_private_key_n);

    mpz_set_str(server_private_key_d, "1143962164783472382905283550657387800872748817766120328647606128386883366536573844259643809931706894941862531602652124249711187730527477133009978059114188147620255071233519618175968062107539244652657607844496603399892412250333891780022986786522378994601380088813425975525221666356226998817243893223890053821724724991854946513188366882736163775624798443042451627402554677880029905869123530594985081090715851553677452668020448700176122039475734402824056912542548725072756109609665857", 10);
    mpz_set_str(server_private_key_n, "1232663856125588687434661844748248537607032756283820193330891679454319646054938919637037805552264427973970252604248734268646061562545490354747125697705834311020677999431630114868193862092727832110639773191903682889441952971015475996569712520630371143533464190192167277413302666026173676557602552365526639943554424303044717518077189805930413771674706770460329522933426941362890328247761964355673083536571273735218319569731179160421634555393152700820206471676467706134292085407619453", 10);
}