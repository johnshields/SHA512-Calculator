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
  * In your chosen Terminal or Command Line if you have ``gcc`` installed. <br>
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
***
###### END OF README
