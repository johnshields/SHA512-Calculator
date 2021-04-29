## Secure Hash Standard
When a message of any length less than `264 bits` `(for SHA-1, SHA-224, and SHA-256)` or less than `2128 bits` `(for SHA-384, SHA-512, SHA-512/224
and SHA-512/256)` is input to a hash algorithm, the result is an output called a message digest.
The message digests range in length from `160` to `512 bits`, depending on the algorithm. Secure
hash algorithms are typically used with other cryptographic algorithms, such as digital signature
algorithms and keyed-hash message authentication codes, or in the generation of random
numbers (bits).

The `SHA-1, SHA-224, SHA-256, SHA-384, SHA512, SHA-512/224`, and `SHA-512/256` algorithms are iterative, one-way hash
functions that can process a message to produce a condensed representation called a message
digest. These algorithms enable the determination of a message’s integrity: any change to the
message will, with a very high probability, result in a different message digest. This property is
useful in the generation and verification of digital signatures and message authentication codes,
and in the generation of random numbers or bits.

The algorithms differ in terms of the size of the blocks and words of data that are
used during hashing or message digest sizes. [[1]](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf)

[![SHA Properties](https://github.com/johnshields/SHA512-Calculator/blob/main/workings/images/SHA_properties%20.png?raw=true)](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf)


## SHA-512
SHA-512 is part of the SHA-2 set of cryptographic hash functions, designed by the U.S. National Security Agency (NSA) and published in 2001 by the NIST as a U.S. Federal Information Processing Standard (FIPS). A hash function is an algorithm that transforms (hashes) an arbitrary set of data elements, such as a text file, into a single fixed-length value (the hash). The computed hash value may then be used to verify the integrity of copies of the original data without providing any means to derive said original data. Irreversible, a hash value may be freely distributed, stored, and used for comparative purposes. SHA stands for Secure Hash Algorithm. SHA-2 includes a significant number of changes from its predecessor. [[17]](https://md5hashing.net/hash/sha512)

### Experimenting with [Online SHA-512 Calulator](https://emn178.github.io/online-tools/sha512.html).
[![Online SHA-512 Calulator](https://github.com/johnshields/SHA512-Calculator/blob/main/workings/images/SHA-512_online.png?raw=true)](https://emn178.github.io/online-tools/sha512.html)

### getopts
getopt is a C library function used to parse command-line options of the Unix/POSIX style. It is a part of the POSIX specification and is universal to Unix-like systems. It is also the name of a Unix program for parsing command-line arguments in shell scripts.
[[8]](https://g.co/kgs/aeVskU)

### SHA-384, SHA-512, SHA-512/224 and SHA-512/256 Functions
Six logical functions are used in SHA-384, SHA-512, SHA-512/224, and SHA-512/256, with each function running on 64-bit words represented as x, y, and z. Each function generates a new 64-bit word as a result. [[1]](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf)

1. The & (bitwise AND) in C takes two numbers as operands and does AND on every bit of two numbers. The result of AND is 1 only if both bits are 1.
2. The | (bitwise OR) in C takes two numbers as operands and does OR on every bit of two numbers. The result of OR is 1 if any of the two bits is 1.
3. The ^ (bitwise XOR) in C takes two numbers as operands and does XOR on every bit of two numbers. The result of XOR is 1 if the two bits are different.
4. The << (left shift) in C takes two numbers, left shifts the bits of the first operand, the second operand decides the number of places to shift.
5. The >> (right shift) in C takes two numbers, right shifts the bits of the first operand, the second operand decides the number of places to shift.
6. The ~ (bitwise NOT) in C takes one number and inverts all bits of it.

[[9]](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/)

### Logical Functions
![funcs](https://user-images.githubusercontent.com/26766163/109554954-d9bea880-7acc-11eb-8464-cd5aea42efd6.png)

* The rotate right (circular right shift) operation ROTR n (x), where x is a w-bit word and n is an integer with 0 < n < w.  [[1]](https://www.nist.gov/publications/secure-hash-standard) (Page 8)


* The right shift operation SHR n (x), where x is a w-bit word and n is an integer with 0 < n < w. [[1]](https://www.nist.gov/publications/secure-hash-standard) (Page 8)

* The rotate left (circular left shift) operation, ROTL n (x), where x is a w-bit word and n is an integer with 0 < n < w.  [[1]](https://www.nist.gov/publications/secure-hash-standard) (Page 9)

### Pre-processing and Padding Messages
For SHA-384, SHA-512, SHA-512/224 and SHA-512/256, the message and its padding are
parsed into N 1024-bit blocks.  Since the 1024 bits of the input block may be
expressed as sixteen 64-bit words, the first 64 bits of message block i are denoted
M0^i, the next 64 bits are M1^i, and so on up to M15^i. [[1]](https://www.nist.gov/publications/secure-hash-standard) (Page 14)

The hash functions are used to generate a message digest from an input message or data file.
A bit string should be used to describe the message or data file.
The length of a message is the number of bits (the empty message has a length of 0).
A message in hex for compactness may represent if the number of bits in it is a multiple of 8.
Message padding is used to render a padded message's total length a multiple of 512 for SHA-224 and SHA-256, or a multiple of 1024 for SHA-384 and SHA-512.

A "1" is appended to the end of the message, followed by multiple "0s," followed by a 64-bit or 128-bit integer, resulting in a padded message of length 512^n or 1024^n.
The criterion is met by using the smallest number of "0"s available. The appended integer represents the length of the original message.
The hash function then processes the padded message as n 512-bit or 1024-bit blocks. [[5]](https://tools.ietf.org/pdf/rfc4634.pdf) (Page 6)

### Endianness
"The attribute of a system that indicates whether integers are represented with the most significant byte stored at the lowest address (big endian) or at the highest address (little endian)." [[11]](https://developer.ibm.com/technologies/systems/articles/au-endianc/)

## Main Questions
### Why can't we reverse the SHA-512 algorithm to retrieve the original message from a hash digest?
* It is a one-way function
* Designed to make it difficult to reverse the process
* Obvious Password security reasons
* it should be impossible but if 1-3 characters as input could be done.
* May not be able to be reverse, but a Brute Force attempt could possibly find the original value
* http://shattered.io/

### Can you design an algorithm that, given enough time, will find input messages that give each of the possible 512-bit strings?
* AI
* Simulated Annealing is an algorithm that applies
* https://mathworld.wolfram.com/SimulatedAnnealing.html
* An NN could possibly be trained to do this, but even then it would need a lot of time as hashes do not have patterns making it very difficult for the train a NN off relevant data.
* NN vs Brute Force
* https://security.stackexchange.com/questions/135211/can-a-neural-network-crack-hashing-algorithms
* https://en.wikipedia.org/wiki/One-time_pad
* https://www.r-bloggers.com/2012/01/decoding-a-substitution-cipher-using-simulated-annealing/
* https://arxiv.org/pdf/1901.02438.pdf
* https://bitcoin.org/bitcoin.pdf

### How difficult is it to find a hash digest beginning with at least twelve zeros?
* Bitcoin Mining - SHA-256
* http://www.righto.com/2014/09/mining-bitcoin-with-pencil-and-paper.html
* https://data.bitcoinity.org/bitcoin/difficulty/5y?r=day&t=l



***
###### END OF RESEARCH
