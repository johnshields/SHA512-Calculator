/*
 * John Shields - G00348436
 * SHA-512 Calculator
 * A program in the C programming language to calculate the SHA512 (Secure Hash Standard) value of an input file.
 *
 * [1] https://www.nist.gov/publications/secure-hash-standard
 * https://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html
 * https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/
 * https://www.guru99.com/c-bitwise-operators.html
 */

#include <stdio.h>
#include <inttypes.h>

#define W 64
#define WORD uint64_t
#define PF PRIX64

// Page 5 of the secure hash standard. [1]
#define ROTL(x, n) (x<<n) | (x>>(W-n))
#define ROTR(x, n) (x>>n) | (x<<(W-n))

// Page 10 of the secure hash standard. [1]
#define CH(x, y, z) (x & y) ^ (~x & z)
#define MAJ(x, y, z) (x & y) ^ (x & z) ^ (y & z)


int main(int argc, char *argv[]) {
    printf("SHA-512 Calculator\n");

    // x picks out the 1s and 0s from the corresponding position
    // where X has 0s picks out the 1s and 0s in z.
    // Use x to choose bits from y & z and merge them together.
    WORD x = 0xF1234567;
    WORD y = 0x0A0A0A0A;
    WORD z = 0xB0B0B0B0;

    WORD ans;

    ans = CH(x, y, z);
    printf("Ch(%08"PF",%08"PF",%08"PF")=%08"PF"\n", x, y, z, ans);

    ans = MAJ(x, y, z);
    printf("Maj(%08"PF",%08"PF",%08"PF")=%08"PF"\n", x, y, z, ans);

    printf("ROTL(%08" PF " -> %08" PF "\n", x, ROTL(x, 4));
    printf("ROTR(%08" PF " -> %08" PF "\n", x, ROTR(x, 4));

    return 0;
}
