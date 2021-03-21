/*
 * John Shields - G00348436
 * SHA-512 Calculator
 * A program in the C programming language to calculate the SHA512 (Secure Hash Standard) value of an input file.
 *
 * [1] Secure Hash Standard - https://www.nist.gov/publications/secure-hash-standard
 * [2] https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/
 * [3] https://crypto.stackexchange.com/questions/5358/what-does-maj-and-ch-mean-in-sha-256-algorithm
 */

#include <stdio.h>
#include <inttypes.h>

#define W 64
// A group of 64 bits (8 bytes). [1] (Page 4)
#define WORD uint64_t
#define PF PRIX64

/*
 * Six Logical Functions.
 *
 * ROT functions - [1] (Page 5)
 * The rotate right (circular right shift) operation ROTR n (x),
 * where x is a w-bit word and n is an integer with 0 < n < w. [1] (Page 8)
*/
#define ROTR(x, n) (x>>n) | (x<<(W-n))
/*
 * The right shift operation SHR n (x),
 * where x is a w-bit word and n is an integer with 0 < n < w. [1] (Page 8)
*/
#define SHR(x, n) x>>n
/*
 * The rotate left (circular left shift) operation, ROTL n (x),
 * where x is a w-bit word and n is an integer with 0 < n < w. [1] (Page 9)
*/
#define ROTL(x, n) (x<<n) | (x>>(W-n))

/*
 * Ch & Maj - [1] Page 11.
 * Bitwise Operators - [1] (Page 5) + [2]
 *
 * Ch stands for choose: The x input chooses if the output is from y or from z.
 * For each bit index, that result bit is according to the bit from y or z  at this index,
 * depending on if the bit from x is 1 or 0. [3]
 */
#define CH(x, y, z) (x & y) ^ (~x & z)

/*
 * Maj stands for majority: for each bit index, that result bit is according to the majority
 * of the three inputs bits for x y and z at this index. [3]
 */
#define MAJ(x, y, z) (x & y) ^ (x & z) ^ (y & z)

// SIGMA functions - [1] (Page 11)
#define SIG0(x) ROTR(x, 28) ^ ROTR(x, 34) ^ ROTR(x, 39)
#define SIG1(x) ROTR(x, 14) ^ ROTR(x, 18) ^ ROTR(x, 41)
#define Sig0(x) ROTR(x, 1) ^ ROTR(x, 8) ^ SHR(x, 7)
#define Sig1(x) ROTR(x, 19) ^ ROTR(x, 61) ^ SHR(x, 6)

/*
 * This const represents the first sixty-four bits of the fractional parts of the cube roots of the
 * first eighty prime numbers. In hex, these constant words are from left to right. [1] (Page 12)
 */
const WORD K[] = {
        0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc,
        0x3956c25bf348b538, 0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118,
        0xd807aa98a3030242, 0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
        0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235, 0xc19bf174cf692694,
        0xe49b69c19ef14ad2, 0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
        0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
        0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f, 0xbf597fc7beef0ee4,
        0xc6e00bf33da88fc2, 0xd5a79147930aa725, 0x06ca6351e003826f, 0x142929670a0e6e70,
        0x27b70a8546d22ffc, 0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
        0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6, 0x92722c851482353b,
        0xa2bfe8a14cf10364, 0xa81a664bbc423001, 0xc24b8b70d0f89791, 0xc76c51a30654be30,
        0xd192e819d6ef5218, 0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
        0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8,
        0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb, 0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3,
        0x748f82ee5defb2fc, 0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
        0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915, 0xc67178f2e372532b,
        0xca273eceea26619c, 0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178,
        0x06f067aa72176fba, 0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b,
        0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc, 0x431d67c49c100d4c,
        0x4cc5d4becb3e42b6, 0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817
};

/*
 * Preprocessing
 * Section 5.3.5 - [1] (Page 15)
 * initial hash value 'H' - eight 64-bit words
 */
WORD H[] = {
        0x6a09e667f3bcc908, 0xbb67ae8584caa73b, 0x3c6ef372fe94f82b, 0xa54ff53a5f1d36f1,
        0x510e527fade682d1, 0x9b05688c2b3e6c1f, 0x1f83d9abfb41bd6b, 0x5be0cd19137e2179
};

// TODO - Block of 1024

int main(int argc, char *argv[]) {
    printf("SHA-512 Calculator\n");

    /*
     * x picks out the 1s and 0s from the corresponding position where X has 0s picks out the 1s and 0s in z.
     * Use x to choose bits from y & z and merge them together.
    */
    WORD x = 0xF1234567;
    WORD y = 0x0A0A0A0A;
    WORD z = 0xB0B0B0B0;

    WORD ans;

    ans = CH(x, y, z);
    // formatting the outputs of the functions
    // Ch function
    printf("Ch(%08"PF",%08"PF",%08"PF")=%08"PF"\n", x, y, z, ans);

    ans = MAJ(x, y, z);
    // Maj function
    printf("Maj(%08"PF",%08"PF",%08"PF")=%08"PF"\n", x, y, z, ans);

    // ROT functions
    printf("ROTL(%08" PF " -> %08" PF "\n", x, ROTL(x, 4));
    printf("ROTR(%08" PF " -> %08" PF "\n", x, ROTR(x, 4));
    printf("SHR(%08" PF " -> %08" PF "\n", x, SHR(x, 4));
    // SIGMA functions
    printf("SIG0(%08" PF " -> %08" PF "\n", x, SIG0(x));
    printf("SIG1(%08" PF " -> %08" PF "\n", x, SIG1(x));
    printf("Sig0(%08" PF " -> %08" PF "\n", x, Sig0(x));
    printf("Sig1(%08" PF " -> %08" PF "\n", x, Sig1(x));
    // const
    printf("K[1] = %08" PF "\nK[79] = %08" PF "\n", K[1], K[79]);

    return 0;
}
