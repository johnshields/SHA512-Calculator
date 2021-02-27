/*
 * John Shields - G00348436
 * SHA-512 Calculator
 * A program in the C programming language to calculate the SHA512 (Secure Hash Standard) value of an input file.
 *
 * https://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html
 * https://www.nist.gov/publications/secure-hash-standard
 * https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/
 * https://www.guru99.com/c-bitwise-operators.html
 */

#include <stdio.h>
#include <inttypes.h>

#define WORD uint64_t
#define PF PRIX64

// TODO - ROTR & SHR - little SIGMA - big SIGMA

// Ch(x, y, z) = (x  y)(x  z)
WORD Ch(WORD x, WORD y, WORD z) {
    return (x & y) ^ (~x & z);
}

// Maj(x, y, z) = (x  y)(x  z)(y  z)
WORD Maj(WORD x, WORD y, WORD z) {
    return (x & y) ^ (~x & z) ^ (y & z);
}


int main(int argc, char *argv[]) {
    printf("SHA-512 Calculator\n");
    // x picks out the 1s and 0s from the corresponding position
    // where X has 0s picks out the 1s and 0s in z.
    // Use x to choose bits from y & z and merge them together.
    WORD x = 0x0F0F0F0F;
    WORD y = 0x0A0A0A0A;
    WORD z = 0xB0B0B0B0;

    WORD ans = Ch(x, y, z);
    WORD res = Maj(x, y, z);
    printf("Ch(%08"PF",%08"PF",%08"PF")=%08"PF"\n", x, y, z, ans);
    printf("Maj(%08"PF",%08"PF",%08"PF")=%08"PF"\n", x, y, z, res);

    return 0;
}
