<h1 align="center">Theory Of Algorithms</h1>

<a href="https://www.gmit.ie/" >
<p align="center"><img src="https://i.ibb.co/f1ZQSkt/logo-gmit.png"
alt="GMIT Logo" width="500" height="200"/>
</p></a>

#### John Shields - G00348436

***

# Project Details
| **Project Title** | SHA-512 Program in C |
| :------------- |:-------------|
| **Course**              | BSc (Hons) in Software Development |
| **Module**              | Theory Of Algorithms |
| **Institute**           | [Galway-Mayo Institute of Technology](https://www.gmit.ie/) |
| **Student**             | [John Shields](https://github.com/johnshields) |
| **Module Lecturer**     | Ian McLoughlin |

***
# SHA-512 Calculator
A program in the C programming language to calculate the SHA-512 value of an input file.


All weekly Labs for the module are located in [this repository](https://github.com/johnshields/SHA-256).

# About the SHA-512
SHA-512 (Secure Hash Algorithm) is part of the SHA-2 set of cryptographic hash functions, designed by the U.S. National Security Agency (NSA) and published in 2001 by the NIST as a U.S. Federal Information Processing Standard (FIPS). [[2]](https://md5hashing.net/hash/sha512) SHA-512 is used to digest any value given and hash it into 128 Hexadecimal characters. There are a lot of parts to SHA-512. The main ones being, Words, Bits, Bytes, Logical Functions, Message Blocks, Message Padding and Endianness.

For example, when a user fills out a registration form for a website with a password, this website could be using the SHA-512 to hash the password for security. For the example, let's say the website is using the SHA-512. When the user enters their details and clicks `Register`. Their password gets sent through a SHA-512 program to hash it and save the password's hashed value into the website's database. When the user logs in, the entered password gets sent through the same program and compares to the one in the database. If the hashes match, the user has entered their password correctly.

## Repository Contents
* [Program](https://github.com/johnshields/SHA512-Calculator/tree/main/program)
  - [main.c](https://github.com/johnshields/SHA512-Calculator/blob/main/program/main.c)
    - Source code of the program for the SHA-512.
  - [input.txt](https://github.com/johnshields/SHA512-Calculator/blob/main/program/input.txt)
    - Input file for command line argument when running program from an executable file.
  - [README.md](https://github.com/johnshields/SHA512-Calculator/tree/main/program/README.md)
    - An overview of how the program works.
* [Workings](https://github.com/johnshields/SHA512-Calculator/tree/main/workings)
  - [images](https://github.com/johnshields/SHA512-Calculator/tree/main/workings/images)
    - Images for documentation.
  - [References.md](https://github.com/johnshields/SHA512-Calculator/blob/main/workings/Research.md)
    - Resources & References that aided the development and research of the program.
  - [Research-and-Development-Diary.md](https://github.com/johnshields/SHA512-Calculator/blob/main/workings/Research-and-Development-Diary.md)
    - A Diary of how the program came altogether from week-by-week work.
  - [Research.md](https://github.com/johnshields/SHA512-Calculator/blob/main/workings/Research.md)
    - Research undertook to understand the problem domain further.
* [.gitignore](https://github.com/johnshields/SHA512-Calculator/blob/main/.gitignore)
  - Files/Directories to ignore when committing to the Repository.
* [README.md](https://github.com/johnshields/SHA512-Calculator/blob/main/README.md)
  - Documentation of the program's Details.

# Run the Program
### Requirements
* [Git](https://git-scm.com/downloads)


* Option 1
  * [Subsystem (WSL2)](https://docs.microsoft.com/en-us/windows/wsl/install-win10#manual-installation-steps)
  * With a [Ubuntu Terminal](https://www.microsoft.com/en-us/p/ubuntu/9nblggh4msv6?activetab=pivot:overviewtab) or [Debian Terminal](https://www.microsoft.com/en-is/p/debian-gnu-linux/9msvkqc78pk6?cid=msft_web_appsforwindows_spotlight&activetab=pivot:overviewtab)


* Option 2
  * Install [gcc](https://preshing.com/20141108/how-to-install-the-latest-gcc-on-windows/) on your machine.


* Option 3
  * If your machine is a Mac, you can use [Clang](https://clang.llvm.org/get_started.html).

## How to Run

* Step 1:
  * In your chosen Terminal or Command Line if you have ``gcc``  or ``Clang``. <br>
    Open a directory of your choice and enter:
```bash
$ git clone https://github.com/johnshields/SHA512-Calculator.git
$ cd program
```

* Step 2:
 * Make main.c into an executable file.
```bash
$ make main
```

* Step 3:
 * Run main with a command line argument of any file.
```bash
$ ./main input.txt
```

``input.txt`` contains the noun 'sea salt'.

When main is ran with this file the hash value should look like this:

```bash
$ ./main input.txt
fc8abd5f06410239f88596955f644d769cbeb625c847c90e400fe0b44b5fa4876c4fc59d8e7b6b2baedb4ae5757cfaf65f24278bdb0a9be47bca48f66d0abfaf
```  

Now that you have the program up and running change the text in `input.txt` and run main again to see what the program can digest it to!

You can test it [here](https://emn178.github.io/online-tools/sha512.html) on an online SHA-512.

Or by typing this command in to the terminal with the file you wish to hash.
```bash
$ sha512sum input.txt
```

For more information on this command refer to [sha512sum](https://command-not-found.com/sha512sum).
***

# Questions & Answers
## Why can't we reverse the SHA-512 algorithm to retrieve the original message from a hash digest?
SHA-512 is designed to be difficult to reverse the process; otherwise, the algorithm would be pointless.
The algorithm is often used for password hashing, thus why it is structured to be secure.
The algorithm is a one-way function, meaning when a message gets passed through it, it is chopped and changed around using the logical functions ROTR, SHR, Maj, and Cha.
'Big' and 'little' Sigmas work with these functions to get the hash computation.
With these functions in place, blocks of bytes and words are pre-processed, padded then hashed over. The message gets almost lost in the process and is transformed into 128 Hexadecimal characters.

NIST officially deprecated SHA-512's predecessor SHA-1 in 2011. However, many companies still rely on it.
GIT strongly depends on SHA-1 for the identification and integrity checking of all file objects and commits.
It is essentially possible to create two repositories with the same head commit hash and different contents, say a benign source code and a back-doored one.
An attacker could potentially selectively serve either repository to targeted users.
This vulnerability will require attackers to compute their collision. [[12]](http://shattered.io/)

SHA-512 was introduced to surmount these vulnerabilities. However, the original message must be complex. If the message was `abc` or anything being 1-3 characters long, it could be cracked with a brute force approach. Hence, most websites or apps ask for one uppercase and lowercase letters, a number, and a special character. e.g `@ $ * _ - /`. Having all these unique items in a password makes the hash even stronger.

For example, the SHA-512 hash value for the character `@` is:

```
e97b9cc0c1e22c66bff31f6c457c2b95b9f9af955c8a098e043734df7439031fd1c6748a139d99077eb2db5f3d98a0e9d05b6606e3d4010ec107a52cd7e43359
```

As you can see, it is quite complex, and a combination of unique characters makes the hash even more complicated. Just reversing the algorithm just for one character would be difficult and require a 'Brute Force' approach to crack one character. If the message is complex with many special characters, e.g., `@P&a$ss@w^/o|-r#_~d€¬56*`. It would be like going up against a supercomputer such as the Fugaku with a Nokia 3310.

Hashing often gets confused with encryption. Encryption can be reversed as the original message is still in there. As with encryption, it is turned into 'gibberish.' Whereas with hashing, the original message is lost. If the SHA-512 were potentially reversible, its source code would not be available worldwide as the source code could outline a possible way to reverse it. Since it is not, it is allowed to be boasted about and thought highly of.

The SHA-512 hash computation is the part that makes it irreversible. This is done after the message is padded. The C code below shows how the computation comes in.

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

#### After repeating steps one through four a total of N times (i.e., after processing M(N)), the resulting 512-bit message digest of the message, M, is:

```c
H0^(N)||H1^(N)||H2^(N)||H3^(N)||H4^(N)||H5^(N)||H6^(N)||H7^(N)
```
 [[1]](https://www.nist.gov/publications/secure-hash-standard) Section 6.4.2

From the statements and demonstration above, it is pretty apparent why the SHA-512 is irreversible.

## Can you design an algorithm that, given enough time, will find input messages that give each of the possible 512-bit strings?
An algorithm of such would require a lot of time and a lot of trial and error. 
Perhaps artificial intelligence could add this process. 
The Heuristic Simulated Annealing algorithm is used to crack ciphers. 
A common practice with heuristics is breaking a cipher by generating many keys, decrypt a cipher-text with each key, and then examine the resultant plaintext. 
This technique is very effective for breaking classical ciphers and has been shown to work well for Affine, Autokey, Bifid, Playfair, and Four-Square ciphers. 
[[13]](https://en.wikipedia.org/wiki/One-time_pad) & [[14]](https://www.r-bloggers.com/2012/01/decoding-a-substitution-cipher-using-simulated-annealing/)

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
Partial matching of a small group of hash bits is possible." [[15]](https://arxiv.org/pdf/1901.02438.pdf)
Keep in mind that this hash 'translation' is for SHA-1. 
Personally, at this current time, I believe that a NN does not stand a chance of finding the input messages that give each of the possible 512-bit strings.
It might be able to get part of it but not the whole message.

In summary, I do not think is it possible to design an algorithm, or a NN that can do this process. 



## How difficult is it to find a hash digest beginning with at least twelve zeros?

###### END OF README
