/*
 * John Shields - G00348436
 * SHA-512 Calculator
 * A program in the C programming language to calculate the SHA512 (Secure Hash Standard) value of an input file.
 *
 * [1] Secure Hash Standard - https://www.nist.gov/publications/secure-hash-standard
 * [2] https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/
 * [3] https://crypto.stackexchange.com/questions/5358/what-does-maj-and-ch-mean-in-sha-256-algorithm
 * [4] https://developer.ibm.com/technologies/systems/articles/au-endianc/
 * [5] https://web.microsoftstream.com/video/7fed3236-f072-433f-a512-a3007da35953
 * [6] https://web.microsoftstream.com/video/64686d04-eea6-411a-85de-676559b9246b
 * [7] https://stackoverflow.com/questions/20076001/how-do-i-create-a-help-option-in-a-command-line-program-in-c-c
 */

#include <stdio.h>
#include <inttypes.h>
#include <byteswap.h>
// for --help in CLI
#include <string.h>

// Words and bytes.
#define WORD uint64_t
#define PF PRIx64
#define BYTE uint8_t

// [4] Endianness
const int _i = 1;
#define is_little_endian() ((*(char*)&_i) != 0) // char = 8 bits

/*
 * Logical Functions.
 *
 * ROT functions - [1] (Page 5)
 * The rotate right (circular right shift) operation ROTR n (x),
 * where x is a w-bit word and n is an integer with 0 < n < w. [1] (Page 8)
*/
#define ROTR(_x, _n) (((_x) >> (_n)) | ((_x) << ((sizeof(_x) * 8) - (_n))))
/*
 * The right shift operation SHR n (x),
 * where x is a w-bit word and n is an integer with 0 < n < w. [1] (Page 8)
*/
#define SHR(_x, _n) ((_x) >> (_n))

/*
 * Ch & Maj - [1] Page 11.
 * Bitwise Operators - [1] (Page 5) + [2]
 *
 * Ch stands for choose: The x input chooses if the output is from y or from z.
 * For each bit index, that result bit is according to the bit from y or z  at this index,
 * depending on if the bit from x is 1 or 0. [3]
 */
#define CH(_x, _y, _z) (((_x) & (_y)) ^ (~(_x) & (_z)))

/*
 * Maj stands for majority: for each bit index, that result bit is according to the majority
 * of the three inputs bits for x, y and z at this index. [3]
 */
#define MAJ(_x, _y, _z) (((_x) & (_y)) ^ ((_x) & (_z)) ^ ((_y) & (_z)))

// SIGMA functions - [1] (Page 11)
#define SIG0(_x) (ROTR(_x, 28) ^ ROTR(_x, 34) ^ ROTR(_x, 39))
#define SIG1(_x) (ROTR(_x, 14) ^ ROTR(_x, 18) ^ ROTR(_x, 41))
#define Sig0(_x) (ROTR(_x, 1) ^ ROTR(_x, 8) ^ SHR(_x, 7))
#define Sig1(_x) (ROTR(_x, 19) ^ ROTR(_x, 61) ^ SHR(_x, 6))

// SHA-512 works on blocks of 1024 bits.
union Block {
    BYTE bytes[128];
    WORD words[16];
    uint64_t sixF[16];
};

// For keeping track of where the input message/padding is.
enum Status {
    READ, PAD, END
};

/*
 * This const represents the first 64 bits of the fractional parts of the cube roots of the
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
 * Get Next Block. [5] & [6]
 * Returns 1 if it created a new block from original message or padding.
 * Returns 0 if all padded message has already been consumed.
*/
int next_block(FILE *f, union Block *M, enum Status *S, uint64_t *num_of_bits) {
    // number of bytes read.
    size_t num_of_bytes;

    if (*S == END) {
        return 0;
    } else if (*S == READ) {
        // Try to read 128 bytes from the input file.
        num_of_bytes = fread(M->bytes, 1, 128, f);
        // Calculate the total bits read so far.
        *num_of_bits = *num_of_bits + (8 * num_of_bytes);
        // Enough room for padding.
        if (num_of_bytes == 128) {
            // This happens when it is possible to read 128 bytes from f.
            return 1;
        } else if (num_of_bytes < 112) {
            // This happens when there is have enough room for all the padding.
            // Append a 1 bit (and seven 0 bits to make a full byte).
            M->bytes[num_of_bytes] = 0x80; // In bits: 10000000.
            // Append enough 0 bits, leaving 128 at the end.
            for (num_of_bytes++; num_of_bytes < 112; num_of_bytes++) {
                M->bytes[num_of_bytes] = 0x00; // In bits: 00000000
            }
            // Append length of original input - Check endianness.
            M->sixF[15] = (is_little_endian() ? bswap_64(*num_of_bits) : *num_of_bits);
            // Say this is the last block.
            *S = END;
        } else {
            // Got to the end of the input message and not enough room
            // in this block for all padding.
            // Append a 1 bit (and seven 0 bits to make a full byte.)
            M->bytes[num_of_bytes] = 0x80;
            // Append 0 bits.
            for (num_of_bytes++; num_of_bytes < 128; num_of_bytes++) {
                // Error: trying to write to
                M->bytes[num_of_bytes] = 0x00; // In bits: 00000000
            }
            // Change the status to PAD.
            *S = PAD;
        }
    } else if (*S == PAD) {
        // Append 0 bits.
        for (num_of_bytes = 0; num_of_bytes < 112; num_of_bytes++) {
            M->bytes[num_of_bytes] = 0x00; // In bits: 00000000
        }
        // Append num_of_bits as an integer - Check endian.
        M->sixF[15] = (is_little_endian() ? bswap_64(*num_of_bits) : *num_of_bits);
        // Change the status to END.
        *S = END;
    }

    // Swap the byte order of the words if is_little_endian.
    if (is_little_endian()) {
        for (int i = 0; i < 16; i++) {
            M->words[i] = bswap_64(M->words[i]);
        }
    }
    return 1;
}

// Get the Next Hash
// SHA-512 Hash Computation - [1] Section 6.4.1 (Page 24)
// designed to make it difficult to reverse the process - [5].
int next_hash(union Block *M, WORD H[]) {
    // Message schedule, [1] Section 6.4.2
    WORD W[128];
    // Iterator.
    int t;
    // Temporary variables.
    WORD a, b, c, d, e, f, g, h, T1, T2;

    // Prepare the message schedule - [1] Section 6.4.2, part 1.
    for (t = 0; t < 16; t++)
        W[t] = M->words[t];
    for (t = 16; t < 80; t++)
        W[t] = Sig1(W[t - 2]) + W[t - 7] + Sig0(W[t - 15]) + W[t - 16];

    // Initialize the eight working variables, a, b, c, d, e, f, g, and h, with the (i-1)st hash value.
    // [1] Section 6.4.2, part 2.
    a = H[0];
    b = H[1];
    c = H[2];
    d = H[3];
    e = H[4];
    f = H[5];
    g = H[6];
    h = H[7];

    // Bring in the Logical Functions SIG1, Ch, SIG0 and Maj [1] Section 6.4.2, part 3.
    for (t = 0; t < 80; t++) {
        T1 = h + SIG1(e) + CH(e, f, g) + K[t] + W[t];
        T2 = SIG0(a) + MAJ(a, b, c);
        h = g;
        g = f;
        f = e;
        e = d + T1;
        d = c;
        c = b;
        b = a;
        a = T1 + T2;
    }

    // [1] Section 6.4.2, part 4.
    // Compute the ith intermediate hash value H(i).
    // next hash from current message block and previous hash value.
    H[0] = a + H[0];
    H[1] = b + H[1];
    H[2] = c + H[2];
    H[3] = d + H[3];
    H[4] = e + H[4];
    H[5] = f + H[5];
    H[6] = g + H[6];
    H[7] = h + H[7];

    return 0;
}

// The function that performs/orchestrates the SHA-512 algorithm on message f.
int sha512(FILE *f, WORD H[]) {
    // The current block.
    union Block M;

    // Total number of bits read.
    uint64_t num_of_bits = 0;

    // Current status of reading input.
    enum Status S = READ;

    // Loop through the (preprocessed) blocks.
    while (next_block(f, &M, &S, &num_of_bits)) {
        next_hash(&M, H);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    /*
     * Preprocessing
     * Section 5.3.5 - [1] (Page 15)
     * initial hash value 'H' - eight 64-bit words
     */
    WORD H[] = {
            0x6a09e667f3bcc908,
            0xbb67ae8584caa73b,
            0x3c6ef372fe94f82b,
            0xa54ff53a5f1d36f1,
            0x510e527fade682d1,
            0x9b05688c2b3e6c1f,
            0x1f83d9abfb41bd6b,
            0x5be0cd19137e2179
    };

    // File pointer for reading.
    FILE *f;

    // --help in command line - [7].
    if (argc == 2 && strcmp(argv[1], "--help")==0) {
        printf("SHA-512 Calculator --help \n");
        printf("\nHash a file with the program by specifying a file e.g: './main input.txt' \n");
        printf("\nPlease make sure the file path and type is correct. \n");
        return 0;
    }

    // Error checking to show if no file was specified in the command line argument.
    if (argc != 2) {
        printf("Expected filename in argument. \n");
        printf("\nType './main --help' for more info. \n");
        return 1;
    }

    // Open file from command line for reading.
    if (!(f = fopen(argv[1], "r"))) {
        printf("Not able to read file %s \n", argv[1]);
        printf("\nType './main --help' for more info. \n");
        return 1;
    }

    // Calculate the SHA-512 of f.
    sha512(f, H);

    // Print the final SHA-512 hash.
    printf("SHA-512 hash value of %s \n\n", argv[1]);
    for (int i = 0; i < 8; i++)
        printf("%016" PF, H[i]);
    printf("\n");

    // Close the file.
    fclose(f);

    return 0;
}
