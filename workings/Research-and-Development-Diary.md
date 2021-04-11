<h1 align="center">Research and Development Diary</h1>

All weekly Labs are located in [this repository](https://github.com/johnshields/SHA-256).

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
This week in the [labs](https://login.microsoftonline.com/common/oauth2/authorize?client_id=cf53fce8-def6-4aeb-8d30-b158e7b1cf83&response_mode=form_post&response_type=code+id_token&scope=openid+profile&state=OpenIdConnect.AuthenticationProperties%3dAQAAAAIAAAAJLnJlZGlyZWN0cGh0dHBzOi8vd2ViLm1pY3Jvc29mdHN0cmVhbS5jb20vdmlkZW8vZmJjNDVkYWQtMDQ4ZS00YmNkLWJjYjktOWVmNDdmMjEzNGI5P3JlZmVycmVyPWh0dHBzOi8vbGVhcm5vbmxpbmUuZ21pdC5pZS8Ibm9uY2VLZXmbATM0OFRJRE15UFFGT05NdnJDWDFhaDZnYjV1V0twMXd1cndBblhHSk9sdmhGNEY5dng0TDdTZHpXLW82d2l3RWJfNWJEUm0tM2YxZWdBcHdLRkFFRlBubzlnTllNMUlCdEVMeHNoOV8tQzcxZ0NlWDVfYXBra09EZ2huX1BLck9BalpJTEdQVE8yVDdNZnJ2XzR3cV9OZ0h4SzBv&nonce=637501369895087745.ODU3YjcwMzUtM2RmNC00M2M1LTk5MjItZmU4Mjc1MWQzYTM2ZWMxOGMwOTMtNzMzZi00NWU2LWFlOWYtNmUyYzdiYTQwYjQ1&nonceKey=OpenIdConnect.nonce.1XDpLvM6x160r5%2f24j6FBPFZXmJj9ZBe9F6aLx8uzqM%3d&site_id=500453&redirect_uri=https%3a%2f%2fweb.microsoftstream.com%2f&post_logout_redirect_uri=https%3a%2f%2fproducts.office.com%2fmicrosoft-stream&msafed=0&prompt=none) focused on dealing with command line arguments in C using getopt, a C library function used to parse command-line options of the Unix/POSIX style. Also, in the labs, [Turing's work on computability](https://web.microsoftstream.com/video/d13ae4c9-9ec6-47ce-8ab4-8e9c34b190a9) was looked into as it relates to work in this module in many ways. As well as Turning's work, in the labs, [Chomsky's work on formal languages](https://web.microsoftstream.com/video/51cd7c6b-1b13-4ef0-bcc2-d9f62f7b84a6) were also looked at to see how it relates to this module's work.

## Week Four
This week the [theory side of automata](https://web.microsoftstream.com/video/11a99321-8e4e-4456-9f11-8b2ca1787f29) was look into and how they relate to formal languages. For [partical work](https://web.microsoftstream.com/video/9d3237fb-55e9-4159-9e08-aa2e086495e5) the functions `Ch` and `Maj` where done for the SHA-256. I got it done for SHA-512 for the main program and added in the command line arguments from last week. Next step is to work out the functions for ROTR, ROTL and SIGMAS.

```c
#define WORD uint64_t
```

![ch](https://user-images.githubusercontent.com/26766163/109430258-56cc1e00-79f8-11eb-9790-d504cb43babc.png)
```c
#define CH(_x, _y, _z) ((_x & _y) ^ (~_x & _z))
```

![maj](https://user-images.githubusercontent.com/26766163/109430281-76634680-79f8-11eb-8a50-4f24855efa26.png)
```c
#define MAJ(_x, _y, _z) ((_x & _y) ^ (_x & _z) ^ (_y & _z))
```

## Week Five
Following last weeks [work](https://web.microsoftstream.com/video/4584d6ab-ad5d-472a-92d3-afc0aa7a060b) the functions for ROTR, ROTL and SIGMAS were done for SHA-256. Shortly after I applied these functions to SHA-512 for the program. These functions along with Ch and Maj operate on 64-bit words, which are represented as x, y, and z. The result of each function is a new 64-bit word.

![funcs](https://user-images.githubusercontent.com/26766163/109554954-d9bea880-7acc-11eb-8464-cd5aea42efd6.png)

* The rotate right (circular right shift) operation ROTR n (x), where x is a w-bit word and n is an integer with 0 < n < w.  [[1]](https://www.nist.gov/publications/secure-hash-standard) (Page 8)


* The right shift operation SHR n (x), where x is a w-bit word and n is an integer with 0 < n < w. [[1]](https://www.nist.gov/publications/secure-hash-standard) (Page 8)

* The rotate left (circular left shift) operation, ROTL n (x), where x is a w-bit word and n is an integer with 0 < n < w.  [[1]](https://www.nist.gov/publications/secure-hash-standard) (Page 9)

#### ROT functions

```c
#define ROTR(_x, _n) ((_x >> _n) | (_x << ((sizeof(_x)*8) - _n)))
#define SHR(_x, _n) (_x >> _n)
#define ROTL(_x, _n) ((_x << _n) | (_x >> ((sizeof(_x)*8) - _n)))
```
#### SIGMA functions

```c
#define SIG0(_x) (ROTR(_x, 28) ^ ROTR(_x, 34) ^ ROTR(_x, 39))
#define SIG1(_x) (ROTR(_x, 14) ^ ROTR(_x, 18) ^ ROTR(_x, 41))
#define Sig0(_x) (ROTR(_x, 1) ^ ROTR(_x, 8) ^ SHR(_x, 7))
#define Sig1(_x) (ROTR(_x, 19) ^ ROTR(_x, 61) ^ SHR(_x, 6))
```

## Week Six
This week for [practical work](https://github.com/johnshields/TOA-Labs/blob/main/funcs/pre_process.c), pre-processing and message padding were done to calculate how many bytes and bits are read from a file. I also added in the initial hash value 'H' for eight 64-bit words. This will be used later for pre-processing.

## Week Seven
This week more [work](https://github.com/johnshields/TOA-Labs/blob/main/funcs/pre_process.c) on pre-processing was done in the labs. After this was done I tried working it out to be able to put it into the main program. This will take some more work but first I need to understand it more. In order to achieve this I need to do more [research](https://github.com/johnshields/SHA512-Calculator/blob/main/workings/Research.md#pre-processing-and-padding-messages).

## Week Eight
This week concludes the work on the SHA-256 algorithm by putting the week-by-week work on command line arguments, bit operations, logical functions, pre-processing, and message padding altogether with the addition of getting the next hash and endianness.
The complete SHA-256 program is located [here](https://github.com/johnshields/SHA-256/blob/main/program/sha256.c).

Now that the SHA-256 is complete, I can now use it to help me finish the SHA-512 algorithm. I have begun by setting up the necessary structure, next is to implement the functions for the next block, next hash, and sha512.

## Week Nine
The SHA-512 algorithm is in place. However, it is not quite finished yet as the hashed output is incorrect.

As of now the output for `abc` is:

```bash
5b3b00839ea450dad75397c8b4f47a90745bd6f2c6b1f0660a59b4c027130088483e35478f6f5fc2fbc428956fbbfce9785632aecb7f23ce13926785359dc721
```

When it should be:

```bash
ddaf35a193617abacc417349ae20413112e6fa4e89a97ea20a9eeee64b55d39a2192992a274fc1a836ba3c23a3feebbd454d4423643ce80e2a9ac94fa54ca49f
```

The output's number of bits is correct, but it seems the hashing process is being affected somehow. Will need to pinpoint this issue in order to have the program complete.

## Week Ten
I can confirm that the hash value is now correct. The problem came down to how I was swaping the bytes.

Original I had:
```c
if (is_little_endian()) {
    for (int i = 0; i < 16; i++) {
        M->words[i] = bswap_34(M->words[i]);
    }
}
```

When it should have been:
```c
if (is_little_endian()) {
    for (int i = 0; i < 16; i++) {
        M->words[i] = bswap_64(M->words[i]);
    }
}
```

The SHA-512 program is officially complete.
![image](https://user-images.githubusercontent.com/26766163/114074001-d1137c00-989b-11eb-9cb8-7be7bcc3634f.png)

***
###### END OF RESEARCH AND DEVELOPMENT DIARY
