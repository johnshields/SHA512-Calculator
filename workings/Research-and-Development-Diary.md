<h1 align="center">Research and Development Diary</h1>

All weekly Labs are located in [this repository](https://github.com/johnshields/TOA-Labs).

***
## Week One
In order to begin this project, a GitHub repository was set up. Then an environment was set up for the program. This consists of a [subsystem (WSL2)](https://docs.microsoft.com/en-us/windows/wsl/install-win10#manual-installation-steps) that works with a [Ubuntu Terminal](https://www.microsoft.com/en-us/p/ubuntu/9nblggh4msv6?activetab=pivot:overviewtab) and [Visual Studio Code](https://code.visualstudio.com/). I also have this set up with [JetBrains' CLion](https://www.jetbrains.com/clion/download) as I am comfortable with using their IDE tools. 

After setting up the environment I decided to do some [research](https://github.com/johnshields/SHA512-Calculator/wiki/Research) on the Secure Hash Standard and Secure Hash Algorithms. I found good resources that I believe will aid me in understanding and developing the program. I believe my main resources will be these three. 
1. [*Secure Hash Standard*, Quynh H. Dang](https://www.nist.gov/publications/secure-hash-standard)
2. [*Efficient Implementation of the SHA-512 Hash Function for 8-bit AVR Microcontrollers*](https://core.ac.uk/download/pdf/186473296.pdf)
3. [*US Secure Hash Algorithms*](https://tools.ietf.org/pdf/rfc4634.pdf)

I found an [Online SHA 512 Calculator](https://emn178.github.io/online-tools/sha512.html) and I believe it was good to experiment with it to see what the program's output is meant to look like.

To get a better understanding of this project I watched videos on YouTube and found these two to be very informative.
1. [*SHA: Secure Hashing Algorithm*, Computerphile](https://www.youtube.com/watch?v=DMtFhACPnTY&ab_channel=Computerphile)
2. [*Secure Hash Algorithm (SHA) 512*, Anny Kartika Sari](https://www.youtube.com/watch?v=Q0MSYPlGHyo&t=372s&ab_channel=AnnyKartikaSari)

Also this week the first [lab](https://web.microsoftstream.com/video/9e7f870c-309e-43eb-805e-ea4e7ee719e1) on [C bit operations](https://github.com/johnshields/TOA-Labs/blob/main/bit_operations/main.c) was done, and I believe I am beginning to grasp a concept for this project.

## Week Two
This week the Lab on [Bit Operations](https://github.com/johnshields/TOA-Labs/blob/main/bit_operations/main.c) was finished. What I mainly learned from the Lab is how to use the unary, binary, and ternary operators. I played around with them a lot by changing the ints and breaking apart the functions to understand how these operators all work. Also, this week in the Labs it was said that pages 24-26 of the [Secure Hash Standard](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf) describe the algorithm for the SHA-512. I had looked over this last week but I looked over it again to get a better understanding. 

## Week Three
This week in the labs focused on dealing with command line arguments in C using getopt, a C library function used to parse command-line options of the Unix/POSIX style. Also, in the labs, Turing's work on computability was looked into as it relates to work in this module in many ways. As well as Turning's work, in the labs, Chomsky's work on formal languages were also looked at to see how it relates to this module's work.

## Week Four
This week the theory side of automata and how they relate to formal languages. For partical work the functions `Ch` and `Maj` where done for the SHA-256. I got it done for SHA-512 for the main program and added in the command line arguments from last week. 


```c
#define WORD uint64_t
```

`Ch(x, y, z) = (x  y)(x  z)`
```c
WORD Ch(WORD x, WORD y, WORD z) {
    return (x & y) ^ (~x & z);
}
```

`Maj(x, y, z) = (x  y)(x  z)(y  z)`
```c
WORD Maj(WORD x, WORD y, WORD z) {
    return (x & y) ^ (~x & z) ^ (y & z);
}
```

***
###### END OF RESEARCH AND DEVELOPMENT DIARY
