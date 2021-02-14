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

## Main Questions
### Why can't we reverse the SHA512 algorithm to retrieve the original message from a hash digest?
* It is a one-way function
* Obvious Password security reasons

### Can you design an algorithm that, given enough time, will find input messages that give each of the possible 512-bit strings?

### How difficult is it to find a hash digest beginning with at least twelve zeros?

***
###### END OF RESEARCH 
