/**

@mainpage CS-F214 Assignment-2

@authors Saksham Attri 2021A7PS2950H, Pranav Dinesh Sharma 2021A7PS2818H, Pritam Basu 2021A7PS2175H


## Requirements: 
 - GCC to compile the C code
 - GNU Make 

## Instructions to run
* Download and extract the repo to `<some-directory>`
* Run (for the first time) with :
```console
make
```
* For subsequent runs, use :
```console
./exec
```
### If running without GNU Make
Run the following in `<some-directory>`:
```console
gcc -c main.c -o main.o
gcc -c Misc/inf/infixToPrefix.c -o inf.o
gcc -c AND-rule/and_intro.c -o and_intro.o
gcc -c AND-rule/and_elim.c -o and_elim.o
gcc -c OR-rule/or_intro.c -o or_intro.o
gcc -c IMP-rule/imp_elim.c -o imp_elim.o
gcc -c MT/modus_tollens.c -o modus_tollens.o
gcc -o exec main.o inf.o and_intro.o and_elim.o or_intro.o imp_elim.o modus_tollens.o
./exec

```
## Algorithm:
![A Flow Chart of the Algorithm] (flow.png)

## Code Design:

As seen in the flow chart above, after control flow passes to checkline(), we check for each line's correctness successively. If any line is found false, proof is deemed invalid, else valid. The checkline function() works as follows:
* Calculates index for the operator
* It makes temporary prefix buffers for both operands
* These are passed as deemed necessary to these functions:

  * and_elim()
  Depending on where it is AND elimination -1 or 2 , we compare the prefix and postfix expressions respectively for the appropriate length.

  * and_intro()
  Compares prefix1 and prefix2 (prefixes of the respective operands) with the prefix of the specified line argument.

  * imp_elim()
  * It uses and_elim() to compare the postfix of the argument with the postfix of the implication for the appropriate length and prefix of the first operand of the implication with the other suitable line argument given.  

  * modus_tollens()
  * It works very similar to the imp_elim(), major differences are that negation is used and the comparison is changed, between given line and prefix of first line argument, and postfixes of second line and first line arguments for the appropriate length while also taking negation into account.

  * or_intro()
  * It checks the prefix of the specified operand with the prefix of the given line argument.

We also have additional checks in place after returning from these functions, to finally pass a value to check().

## Example Output:
![Sample Output 1] (sampleOutput1.jpeg)
![Sample Output 2] (sampleOutput2.jpeg)
![Sample Output 3] (sampleOutput3.jpeg)
![Sample Output 4] (sampleOutput4.jpeg)
![Sample Output 5] (sampleOutput5.jpeg)

## Plans to Extend:
In the future, additional support for features such as assumption, box proofs, and other rules not in the scope of this project may be implented in a similar fashion.

## Specifications:
- Architecture:            x86_64
- CPU op-mode(s):          32-bit, 64-bit
- Address sizes:           39 bits physical, 48 bits virtual
- Byte Order:              Little Endian
- CPU(s):                  8
- On-line CPU(s) list:     0-7
- Vendor ID:               GenuineIntel
- Model name:              Intel(R) Core(TM) i5-1035G1 CPU @ 1.00GHz
- CPU family:              6
- Model:                   126
- Thread(s) per core:      2
- Core(s) per socket:      4
- Socket(s):               1
- Stepping:                5
- CPU max MHz:             3600.0000
- CPU min MHz:             400.0000
- BogoMIPS:                2380.80
- Virtualization:          VT-x
- Caches (sum of all):    
  - L1d:                   192 KiB (4 instances)
  - L1i:                   128 KiB (4 instances)
  - L2:                    2 MiB (4 instances)
  - L3:                    6 MiB (1 instance)
- RAM:                     20 GiB

We found the assignment really engaging and it was really fun to work in a team environment.
This assignment also helped deepen our insight into theoretical concepts behind propositional logic and proof verification.
We thank all our instructors for providing us this opportunity.

