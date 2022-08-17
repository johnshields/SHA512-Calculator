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
| **Grade Achieved**     | B |

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

###### END OF README
