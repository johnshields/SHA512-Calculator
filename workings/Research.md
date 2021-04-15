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
SHA-512 is part of the SHA-2 set of cryptographic hash functions, designed by the U.S. National Security Agency (NSA) and published in 2001 by the NIST as a U.S. Federal Information Processing Standard (FIPS). A hash function is an algorithm that transforms (hashes) an arbitrary set of data elements, such as a text file, into a single fixed-length value (the hash). The computed hash value may then be used to verify the integrity of copies of the original data without providing any means to derive said original data. Irreversible, a hash value may be freely distributed, stored, and used for comparative purposes. SHA stands for Secure Hash Algorithm. SHA-2 includes a significant number of changes from its predecessor. [[2]](https://md5hashing.net/hash/sha512)

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
* May not be able to be reverse but a Brute Force attempt could possibly find the original value
* http://shattered.io/

SHA-512 is designed to be difficult to reverse the process; otherwise, the algorithm would be pointless.
The algorithm is often used for password hashing, thus why it is structured to be secure.
The algorithm is a one-way function, meaning when a message gets passed through it, it is chopped and changed around using the logical functions ROTR, SHR, Maj, and Cha.
'Big' and 'little' Simgas work with these functions to get the hash computation.
With these functions in place, blocks of bytes and words are pre-processed, padded then hashed over. The message gets almost lost in the process and is transformed into 128 Hexadecimal characters.

NIST officially deprecated SHA-512's predecessor SHA-1 in 2011. However, many companies still rely on it.
GIT strongly depends on SHA-1 for the identification and integrity checking of all file objects and commits.
It is essentially possible to create two repositories with the same head commit hash and different contents, say a benign source code and a backdoored one.
An attacker could potentially selectively serve either repository to targeted users.
This vulnerability will require attackers to compute their collision. [[12]](http://shattered.io/)

SHA-512 was introduced to surmount these vulnerabilities. However, the original message must be complex. If the message was `abc` or anything being 1-3 characters long, it could be cracked with a brute force approach. Hence, most websites or apps ask for one uppercase and lowercase letters, a number, and a special character. e.g `@ $ * _ - /`. Having all these unique items in a password makes the hash even stronger.

For example, the SHA-512 hash value for the character `@` is:

```
e97b9cc0c1e22c66bff31f6c457c2b95b9f9af955c8a098e043734df7439031fd1c6748a139d99077eb2db5f3d98a0e9d05b6606e3d4010ec107a52cd7e43359
```

As you can see, it is quite complex, and a combination of unique characters makes the hash even more complicated. Just reversing the algorithm just for one character would be difficult and require a 'Brute Force' approach to crack one character. If the message is complex with many special characters, e.g., `@P&a$ss@w^/o|-r#_~d€¬56*`. It would be like going up against a supercomputer such as the Fugaku with a Nokia 3310.

Hashing often gets confused with encryption. Encryption can be reversed as the original message is still in there. As with encryption, it is turned into 'gibberish.' Whereas with hashing, the original message is lost. If the SHA-512 were potentially reversible, its source code would not be available worldwide as the source code could outline a possible way to reverse it. Since it is not, it is allowed to be boasted about and thought highly of.

The SHA-512 hash computation is the part that makes it irreversible. The C code below shows how the computation comes in.

#### In the computation each message block, M(1), M(2), …, M(N), is processed in order, using the following steps: [[1]](https://www.nist.gov/publications/secure-hash-standard) Section 6.4.1 (Page 24)

#### Prepare the message schedule - [[1]](https://www.nist.gov/publications/secure-hash-standard) Section 6.4.2, part 1.
```c
for (t = 0; t < 16; t++)
    W[t] = M->words[t];
for (t = 16; t < 80; t++)
    W[t] = Sig1(W[t - 2]) + W[t - 7] + Sig0(W[t - 15]) + W[t - 16];
```

#### Initialize the eight working variables, a, b, c, d, e, f, g, and h, with the (i-1)st hash value. [[1]](https://www.nist.gov/publications/secure-hash-standard) Section 6.4.2, part 2.

```c
a = H[0]; b = H[1]; c = H[2]; d = H[3]; e = H[4]; f = H[5]; g = H[6]; h = H[7];
```

#### Bring in the Logical Functions SIG1, Ch, SIG0 and Maj [[1]](https://www.nist.gov/publications/secure-hash-standard) Section 6.4.2, part 3.

```c
for (t = 0; t < 80; t++) {
   T1 = h + SIG1(e) + CH(e, f, g) + K[t] + W[t];
   T2 = SIG0(a) + MAJ(a, b, c);

   h = g; g = f; f = e; e = d + T1;
   d = c; c = b; b = a; a = T1 + T2;
}
```

#### Compute the ith intermediate hash value H(i) next hash from current message block and previous hash value. [[1]](https://www.nist.gov/publications/secure-hash-standard) Section 6.4.2, part 4.
```c
  H[0] = a + H[0];
  H[1] = b + H[1];
  H[2] = c + H[2];
  H[3] = d + H[3];
  H[4] = e + H[4];
  H[5] = f + H[5];
  H[6] = g + H[6];
  H[7] = h + H[7];
```

From the statements above, it is pretty apparent why the SHA-512 is irreversible.

### Can you design an algorithm that, given enough time, will find input messages that give each of the possible 512-bit strings?
* AI
* Simulated Annealing is an algorithm that applies
* https://mathworld.wolfram.com/SimulatedAnnealing.html
* An NN could possibly be trained to do this, but even then it would need a lot of time as hashes do not have patterns making it very difficult for the train a NN off relevant data.
* NN vs Brute Force
* https://security.stackexchange.com/questions/135211/can-a-neural-network-crack-hashing-algorithms

An algorithm of such would require a lot of time and a lot of trial and error. 
Perhaps artificial intelligence could add this process. 
The Heuristic Simulated Annealing algorithm is used to crack ciphers. 
A common practice with heuristics is breaking a cipher by generating many keys, decrypt a cipher-text with each key, and then examine the resultant plaintext. 
This technique is very effective for breaking classical ciphers and has been shown to work well for Affine, Autokey, Bifid, Playfair, and Four-Square ciphers. 
https://en.wikipedia.org/wiki/One-time_pad) 
https://www.r-bloggers.com/2012/01/decoding-a-substitution-cipher-using-simulated-annealing/

However, these ciphers are not like hashes as the message is still in there. Therefore, the message can be found through all the jumbled characters.
As said above, the message gets lost in a hash, so decipher algorithm would not work for this situation.

Machine Learning is another possibility to use against hashes. 
A Neural Network (NN) could be trained with the original message and an expected hash value. 
This process would require a comprehensive and relevant data set for input messages that give each of the possible 512-bit strings.
This data set would have to cover the most common words, number, unique letters, characters, hexadecimal, etc.
A data set of such would take some time to put together.
Even then, with a data set, this would require a lot of time, and NNs rely on patterns that hashes do not have most of the time.
An NN could crack smaller hash algorithms such as the SHA-1, SHA-2, SHA-3, and MD5. 
For SHA-1, a "NN can invert 1 round with positive probability; for two rounds, there are at least ten misses, then the number of misses becomes more significant than the number of matched bits. 
The complete hash for more than 5–6 rounds with the accordingly long messages is almost invertible; 
the quick-convergence-to- 1 2 flaws of (unadjusted) fuzzy ops contributes to this barrier. 
Partial matching of a small group of hash bits is possible." 
https://arxiv.org/pdf/1901.02438.pdf

Keep in mind that this hash 'translation' is for SHA-1. Personally, at this current time, I believe that a NN does not stand a chance of finding the input messages that give each of the possible 512-bit strings.

### How difficult is it to find a hash digest beginning with at least twelve zeros?

* Bitcoin - SHA-256
* http://www.righto.com/2014/09/mining-bitcoin-with-pencil-and-paper.html

***
###### END OF RESEARCH
