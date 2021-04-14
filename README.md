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
A repository for the main project for the module Theory of Algorithms.<br>
A program in the C programming language to calculate the SHA-512 value of an input file.


All weekly Labs for the module are located in [this repository](https://github.com/johnshields/SHA-256).

# About the SHA-512
SHA-512 (Secure Hash Algorithm) is part of the SHA-2 set of cryptographic hash functions, designed by the U.S. National Security Agency (NSA) and published in 2001 by the NIST as a U.S. Federal Information Processing Standard (FIPS). [[2]](https://md5hashing.net/hash/sha512) SHA-512 is used to digest any value given and hash (encrypt) it into 128 Hexadecimal characters. There are a lot of parts to SHA-512. The main ones being, Words, Bits, Bytes, Logical Functions, Message Blocks, Message Padding and Endianness.

For example, when a user fills out a registration form for a website with a password, this website could be using the SHA-512 to hash the password for security. For the example, let's say the website is using the SHA-512. When the user enters their details and clicks `Register`. Their password gets sent through a SHA-512 program to hash it and save the password's hashed value into the website's database. When the user logs in, the entered password gets sent through the same program and compares to the one in the database. If the hashes match, the user has entered their password correctly.

## Repository Contents
* [Program](https://github.com/johnshields/SHA512-Calculator/tree/main/program)
  - [main.c](https://github.com/johnshields/SHA512-Calculator/blob/main/program/main.c)
    - Source code of the main program for the SHA-512.
  - [input.txt](https://github.com/johnshields/SHA512-Calculator/blob/main/program/input.txt)
    - Input file for command line argument when running program from an executable file.
* [Workings](https://github.com/johnshields/SHA512-Calculator/tree/main/workings)
  - [images](https://github.com/johnshields/SHA512-Calculator/tree/main/workings/images)
    - Images for documentation.
  - [resources](https://github.com/johnshields/SHA512-Calculator/tree/main/workings/resources)
    - Resources that aided the development of the program.
  - [References.md](https://github.com/johnshields/SHA512-Calculator/blob/main/workings/Research.md)
    - URLs for citing
  - [Research-and-Development-Diary.md](https://github.com/johnshields/SHA512-Calculator/blob/main/workings/Research-and-Development-Diary.md)
    - A Diary of how the program came altogether from week-by-week work.
  - [Research.md](https://github.com/johnshields/SHA512-Calculator/blob/main/workings/Research.md)
    - Research undertook to understand the problem domain further.
* [.gitignore](https://github.com/johnshields/SHA512-Calculator/blob/main/.gitignore)
  - Files/Directories to ignore when committing to the Repository.
* [README.md](https://github.com/johnshields/SHA512-Calculator/blob/main/README.md)
  - Documentation of the programs Details.

# Run the Program
### Requirements
* [Git](https://git-scm.com/downloads)


* Option 1
  * [Subsystem (WSL2)](https://docs.microsoft.com/en-us/windows/wsl/install-win10#manual-installation-steps)
  * With a [Ubuntu Terminal](https://www.microsoft.com/en-us/p/ubuntu/9nblggh4msv6?activetab=pivot:overviewtab) or [Debian Terminal](https://www.microsoft.com/en-is/p/debian-gnu-linux/9msvkqc78pk6?cid=msft_web_appsforwindows_spotlight&activetab=pivot:overviewtab)


* Option 2
  * Install [gcc](https://preshing.com/20141108/how-to-install-the-latest-gcc-on-windows/) on your machine.


* Option 3
  * If your PC is a Mac, you can use [Clang](https://clang.llvm.org/get_started.html).


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

``input.txt`` contains the letters a, b and c.

When main is ran with this file the hash digest should look like this:

```bash
$ ./main input.txt
ddaf35a193617abacc417349ae20413112e6fa4e89a97ea20a9eeee64b55d39a2192992a274fc1a836ba3c23a3feebbd454d4423643ce80e2a9ac94fa54ca49f
```  

Now that you have the program up and running change the text in `input.txt` and run main again to see what the program can digest it to!

You can test it [here](https://emn178.github.io/online-tools/sha512.html) on an online SHA-512.

Or by typing this command in to the terminal with the file you wish to hash.
```bash
$ sha512sum input.txt
```

For more information on this command refer to [sha512sum](https://command-not-found.com/sha512sum).
***


## Why can't we reverse the SHA-512 algorithm to retrieve the original message from a hash digest?
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

From the statements above, it is pretty apparent why the SHA-512 is irreversible.
###### END OF README
