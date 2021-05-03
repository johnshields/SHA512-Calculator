<h1 align="center">Theory Of Algorithms</h1>

<a href="https://www.gmit.ie/" >
<p align="center"><img src="https://i.ibb.co/f1ZQSkt/logo-gmit.png"
alt="GMIT Logo" width="500" height="200"/>
</p></a>

#### John Shields - G00348436

***
# README Contents
* [About the SHA-512](https://github.com/johnshields/SHA512-Calculator#about-the-sha-512)
* [Repository Contents](https://github.com/johnshields/SHA512-Calculator#repository-contents)
* [Run the Program](https://github.com/johnshields/SHA512-Calculator#run-the-program)
  - [Requirements](https://github.com/johnshields/SHA512-Calculator#requirements)
  - [How to Run](https://github.com/johnshields/SHA512-Calculator#how-to-run)
  - [Testing](https://github.com/johnshields/SHA512-Calculator#testing)
* [Questions & Answers](https://github.com/johnshields/SHA512-Calculator#questions--answers)

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
SHA-512 (Secure Hash Algorithm) is part of the SHA-2 set of cryptographic hash functions, designed by the U.S. National Security Agency (NSA) and published in 2001 by the NIST as a U.S. Federal Information Processing Standard (FIPS). [[17]](https://md5hashing.net/hash/sha512) SHA-512 is used to digest any value given and hash it into 128 Hexadecimal characters. There are a lot of parts to SHA-512. The main ones being, Words, Bits, Bytes, Logical Functions, Message Blocks, Message Padding and Endianness.

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

***
# Run the Program
### Requirements
* [Git](https://git-scm.com/downloads)
* [sha512sum](https://command-not-found.com/sha512sum) (For Testing)


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
  * Make sha512calculator.c into an executable file.
```bash
$ make sha512calculator
```
  * Or use the `Makefile` you can also make it into an executable file by entering:
```bash
$ make
```

* Step 3:
  * Run sha512calculator with a command line argument of any file.
```bash
$ ./sha512calculator test_inputs/seasalt.txt
```

``seasalt.txt`` contains the noun 'sea salt'.

When the program is ran with this file the hash value should look like this:

```bash
$ ./sha512calculator test_inputs/seasalt.txt
fc8abd5f06410239f88596955f644d769cbeb625c847c90e400fe0b44b5fa4876c4fc59d8e7b6b2baedb4ae5757cfaf65f24278bdb0a9be47bca48f66d0abfaf
```

## Testing
With the Makefile you can do tests.

* Step 1
  * Call the Makefile to make an executable by entering:
```bash
$ make
```
* Step 2
  * You will need to make `tests.sh` runnable.
```bash
$ chmod u+x tests.sh
```
* Step 3
  * Call in the `make test`

```bash
$ make test
```

After running this command it will test the program with all the files in the directory `test_inputs` against [sha512sum](https://command-not-found.com/sha512sum).

You can expect to see this output:
```bash
 $ make test

./tests.sh

Checking file test_inputs/abc.txt
sha512calculator:  ddaf35a193617abacc417349ae20413112e6fa4e89a97ea20a9eeee64b55d39a2192992a274fc1a836ba3c23a3feebbd454d4423643ce80e2a9ac94fa54ca49f test_inputs/abc.txt
sha512sum:         ddaf35a193617abacc417349ae20413112e6fa4e89a97ea20a9eeee64b55d39a2192992a274fc1a836ba3c23a3feebbd454d4423643ce80e2a9ac94fa54ca49f test_inputs/abc.txt
Pass

Checking file test_inputs/barry_white.txt
sha512calculator:  65595324ac2b1372f131ff236698c1cc0e5162b7748e13d4eb3a592b28e2ca4694379f0a3b676ba5b9db36d2797a5cc67bcd0637554c5f62a94a3afd3d7960b7 test_inputs/barry_white.txt
sha512sum:         65595324ac2b1372f131ff236698c1cc0e5162b7748e13d4eb3a592b28e2ca4694379f0a3b676ba5b9db36d2797a5cc67bcd0637554c5f62a94a3afd3d7960b7 test_inputs/barry_white.txt
Pass

Checking file test_inputs/lorem.txt
sha512calculator:  3b8802540e449f6927aed811dbd41f7209a412dcb581a1a6ef5adf77f04808034700342a7ce0975157be493308e6d2655d0ac95b4b141f4d99203e871a2b6267 test_inputs/lorem.txt
sha512sum:         3b8802540e449f6927aed811dbd41f7209a412dcb581a1a6ef5adf77f04808034700342a7ce0975157be493308e6d2655d0ac95b4b141f4d99203e871a2b6267 test_inputs/lorem.txt
Pass

Checking file test_inputs/seasalt.txt
sha512calculator:  fc8abd5f06410239f88596955f644d769cbeb625c847c90e400fe0b44b5fa4876c4fc59d8e7b6b2baedb4ae5757cfaf65f24278bdb0a9be47bca48f66d0abfaf test_inputs/seasalt.txt
sha512sum:         fc8abd5f06410239f88596955f644d769cbeb625c847c90e400fe0b44b5fa4876c4fc59d8e7b6b2baedb4ae5757cfaf65f24278bdb0a9be47bca48f66d0abfaf test_inputs/seasalt.txt
Pass
```
***

# Questions & Answers
## 1. Why can't we reverse the SHA-512 algorithm to retrieve the original message from a hash digest?
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

SHA-512 was introduced to surmount these vulnerabilities. However, the original message must be complex. If the message was `abc` or anything being 1-3 characters long, it could be cracked (See Figure below).

##### The SHA-512 hash value for `abc` passing on a cracker site.
[![image](https://user-images.githubusercontent.com/26766163/115011154-2fe18280-9ea6-11eb-82c7-f6ab2e956025.png)](https://crackstation.net/)

Hence, most websites or apps ask for one uppercase and lowercase letters, a number, and a special character. e.g `@ $ * _ - /`. Having all these unique items in a password makes the hash even stronger.

For example, the SHA-512 hash value for the character `@` is:

```
e97b9cc0c1e22c66bff31f6c457c2b95b9f9af955c8a098e043734df7439031fd1c6748a139d99077eb2db5f3d98a0e9d05b6606e3d4010ec107a52cd7e43359
```

As you can see, it is quite complex, and a combination of unique characters makes the hash even more complicated. Just reversing the algorithm just for one character would be difficult and require a 'Brute Force' approach to crack one character. If the message is complex with many special characters, e.g., `@P&a$ss@w^/o|-r#_~d€¬56*`. It would be like going up against a supercomputer such as the Fugaku with a Nokia 3310.

##### The SHA-512 hash value for `@P&a$ss@w^/o|-r#_~d€¬56*` failing on a cracker site.
[![image](https://user-images.githubusercontent.com/26766163/115011549-aaaa9d80-9ea6-11eb-8446-9ae236ebe5c8.png)](https://crackstation.net/)

Hashing often gets confused with encryption. Encryption can be reversed as the original message is still in there. As with encryption, it is turned into 'gibberish.' Whereas with hashing, the original message is lost. If the SHA-512 were potentially reversible, its source code would not be available worldwide as the source code could outline a possible way to reverse it. Since it is not, it is allowed to be boasted about and thought highly of.

The SHA-512 hash computation is the part that makes it irreversible. This is done after the message is padded. The C code below shows how the computation comes in.

#### In the computation each message block, M(1), M(2), …, M(N), is processed in order, using the following steps: [[1]](https://www.nist.gov/publications/secure-hash-standard) Section 6.4.1 (Page 24)

#### Prepare the message schedule - [[1]](https://www.nist.gov/publications/secure-hash-standard) Section 6.4.2, part 1.
```c
for (t = 0; t < 16; t++) W[t] = M->words[t];
for (t = 16; t < 80; t++) W[t] = Sig1(W[t - 2]) + W[t - 7] + Sig0(W[t - 15]) + W[t - 16];
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

## 2. Can you design an algorithm that, given enough time, will find input messages that give each of the possible 512-bit strings?
An algorithm of such would require a lot of time and a lot of trial and error.
Perhaps artificial intelligence could add this process.
The Heuristic Simulated Annealing algorithm is used to crack ciphers.
A common practice with heuristics is breaking a cipher by generating many keys, decrypt a cipher-text with each key, and then examine the resultant plaintext.
This technique is very effective for breaking classical ciphers and has been shown to work well for Affine, Autokey, Bifid, Playfair, and Four-Square ciphers.
[[13]](https://en.wikipedia.org/wiki/One-time_pad) & [[14]](https://www.r-bloggers.com/2012/01/decoding-a-substitution-cipher-using-simulated-annealing/) However,
these ciphers are not like hashes as the message is still in there. Therefore, the message can be found through all the jumbled characters.
As said above, the message gets lost in a hash, so decipher algorithm would not work for this situation.

Machine Learning is another possibility to use against hashes. A Neural Network (NN) could be trained with hash values and expected original messages.
This process would require a comprehensive and relevant data set for input messages that give each of the possible 512-bit strings.
This data set would have to cover the most common words, number, unique letters, characters, hexadecimal, etc.
A data set of such would take some time to put together.
Even then, with a data set, this would require a lot of time, and NNs rely on patterns that hashes do not have most of the time.
An NN could crack smaller hash algorithms such as the SHA-1, SHA-2, SHA-3, and MD5.
For SHA-1, a
"NN can invert 1 round with positive probability; for two rounds, there are at least ten misses,
then the number of misses becomes more significant than the number of matched bits.
The complete hash for more than 5–6 rounds with the accordingly long messages is almost invertible;
the quick-convergence-to 1-2 flaws of (unadjusted) fuzzy ops contributes to this barrier.
Partial matching of a small group of hash bits is possible." [[15]](https://arxiv.org/pdf/1901.02438.pdf) (Page 8).
Keep in mind that this hash 'translation' is for SHA-1. Having a NN tackle an algorithm such as the SHA-256 or SHA-512 would not be significantly achievable.
Personally, at this current time, I believe that a NN does not stand a chance of finding the input messages that give each of the possible 512-bit strings.
It might be able to get part of it but not whole.

Bitcoin employs a 'Proof-of-Work' system that entails scanning a hashed value. With the SHA-256, the hash begins with zero bits.
The average amount of work required is proportional to the number of zero bits needed and checked with a single hash.
Even then, with a brute force attempt to put the SHA-256 back into its original message in bitcoin,
the process is working against thousands of machines as bitcoin uses a Peer-to-Peer system. [[16]](https://bitcoin.org/bitcoin.pdf)
This process could lead to an algorithm that can find input messages that give each of the possible 512-bit strings and require some time to achieve.

## 3. How difficult is it to find a hash digest beginning with at least twelve zeros?
Finding a hash digest beginning with at least twelve zeros is a shot in the dark. In Bitcoin, a "hit" hash needs to start with seventeen zeros, which is where Bitcoin mining comes in. Bitcoin mining is a critical component of the Bitcoin system's protection. Bitcoin miners group several Bitcoin transactions into a block, then perform a cryptographic operation known as hashing zillions of times until they find a unique, scarce hash value. By this time, the block has now been mined and is now part of the Bitcoin network. In and by itself, the hashing business accomplishes nothing useful. Nonetheless, the difficulty of finding a viable block means that no one person has the resources to take over the Bitcoin system. [[3]](http://www.righto.com/2014/09/mining-bitcoin-with-pencil-and-paper.html) This is where brute force strikes again. In order to achieve a hash with a certain number of zeros, many attempts have to be made as hash functions such as the SHA-256 and SHA-512 are irreversible. While it is possible, it would take a considerable amount of time.

[Project Nayuki](https://www.nayuki.io/page/lowest-sha512-value-by-brute-force) developed a couple of C and Python programs. These programs use brute force to find the lowest SHA-512 hash value. In Jupyter Notebook, I adapted the project's [Python code](https://www.nayuki.io/res/lowest-sha512-value-by-brute-force/lowest-sha512.py) to see if I could find a SHA-256 hash with twelve zeros. In the program, the most common number of zeros is between four and seven. It takes 16,098,229 trails to find seven zeros. This process took quite some time, and after that, the program bails out, or it is taking a very long time to find any more hash values beginning with more than seven zeros (See Figure below).

![image](https://user-images.githubusercontent.com/26766163/115027554-c66c6e80-9ebb-11eb-82e6-18cb2be0eb4a.png)

On [Project Nayuki](https://www.nayuki.io/page/lowest-sha512-value-by-brute-force) an image shows a C [program](https://www.nayuki.io/res/lowest-sha512-value-by-brute-force/lowest-sha512-quad-pthread.c) found a SHA-512 hash value with nine zeros (See the Figure below).

[![image](https://www.nayuki.io/res/lowest-sha512-value-by-brute-force/lowest-sha512-running.png)](https://www.nayuki.io/res/lowest-sha512-value-by-brute-force/lowest-sha512-running.png)

This program took 5.261 billion trails to find a hash with just nine zeros. This goes to shows that it is quite challenging to find a hash with at least twelve zeros even by brute force.

Project Nayuki was part of a ['hash challenge'](https://web.archive.org/web/20171002020748/http://www.h11e.com/) to find the lowest hash value of SHA-512. 
On the challenge's leaderboard the Nayuki did find a hash with twelve zeros which was the lowest hash value found (Figure below) along with two others with twelve zeros.

[![image](https://user-images.githubusercontent.com/26766163/116894774-5a636780-ac2a-11eb-9e4a-c7242113169a.png)](https://web.archive.org/web/20171002020748/http://www.h11e.com/)

However, according to a Stack Exchange post titled *[Which is the smallest hash that has ever been hashed?](https://bitcoin.stackexchange.com/a/105023)*. A reply showed a program that found four block hashes in Bitcoin beginning with twelve zeros in Java (See Figure below).   

[![image](https://user-images.githubusercontent.com/26766163/115032196-f5d1aa00-9ec0-11eb-8371-bdc8feef0439.png)](https://bitcoin.stackexchange.com/a/105023)

As the figure shows other hashes above twelve zeros were also found in some other blocks.

In conclusion, although finding a hash starting with twelve zeros is possible, it can be a difficult task and Bitcoin mining appears to be the only common place where this could happen.
***

###### END OF README
