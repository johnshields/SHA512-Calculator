<h1 align="center">Theory Of Algorithms</h1>

<a href="https://www.gmit.ie/" >
<p align="center"><img src="https://i.ibb.co/f1ZQSkt/logo-gmit.png"
alt="GMIT Logo" width="500" height="200"/>
</p></a>

#### John Shields - G00348436

***

# Project Details
| **Project Title** | SHA-512 Algorithm in C |
| :------------- |:-------------|
| **Course**              | BSc (Hons) in Software Development |
| **Module**              | Theory Of Algorithms |
| **Institute**           | [Galway-Mayo Institute of Technology](https://www.gmit.ie/) |
| **Student**             | [John Shields](https://github.com/johnshields) |
| **Module Lecturer**     | Ian McLoughlin |

***

# SHA-512 Calculator
A repository for the main project for the module Theory of Algorithms.<br>
A program in the C programming language to calculate the SHA-512 (Secure Hash Standard) value of an input file.

All weekly Labs for the module are located in [this repository](https://github.com/johnshields/SHA-256).

## Repository Contents
* [Program](https://github.com/johnshields/SHA512-Calculator/tree/main/program)
  - [main.c](https://github.com/johnshields/SHA512-Calculator/blob/main/program/main.c)
    - Source code of the main program for the SHA-512 Algorithm.
  - [input.txt](https://github.com/johnshields/SHA512-Calculator/blob/main/program/input.txt)
    - Input file for command line argument when running program from a Makefile.
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

## Run the Program
### Requirements
* [Git](https://git-scm.com/downloads)


* Option 1
  * [Subsystem (WSL2)](https://docs.microsoft.com/en-us/windows/wsl/install-win10#manual-installation-steps)
  * With a [Ubuntu Terminal](https://www.microsoft.com/en-us/p/ubuntu/9nblggh4msv6?activetab=pivot:overviewtab) or [Debian Terminal](https://www.microsoft.com/en-is/p/debian-gnu-linux/9msvkqc78pk6?cid=msft_web_appsforwindows_spotlight&activetab=pivot:overviewtab)


* Option 2
  * Install [gcc](https://preshing.com/20141108/how-to-install-the-latest-gcc-on-windows/) on your machine.

***
### How to Run

* Step 1:
  * In your chosen Terminal or Command Line if you have ``gcc`` installed. <br>
    Open a directory of your choice and enter:
```bash
$ git clone https://github.com/johnshields/SHA512-Calculator.git
$ cd program
```

* Step 2:
 * Make main.c into a Makefile.
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

Now that you have the program up and running change the text in `input.txt` and run main again to see what the program can digest!
***
###### END OF README
