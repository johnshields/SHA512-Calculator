/*
 * John Shields - G00348436
 * SHA-512 Calculator
 * Six Logical Functions for SHA-512.
 *
 * [1] Secure Hash Standard - https://www.nist.gov/publications/secure-hash-standard
 * [2] https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/
 * [3] https://crypto.stackexchange.com/questions/5358/what-does-maj-and-ch-mean-in-sha-256-algorithm
 */

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

// SIGMA functions - [1] (Page 10)
#define SIG0(x) ROTR(x, 28) ^ ROTR(x, 34) ^ ROTR(x, 39)
#define SIG1(x) ROTR(x, 14) ^ ROTR(x, 18) ^ ROTR(x, 41)
#define Sig0(x) ROTR(x, 1) ^ ROTR(x, 8) ^ SHR(x, 7)
#define Sig1(x) ROTR(x, 19) ^ ROTR(x, 61) ^ SHR(x, 6)