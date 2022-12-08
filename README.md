# CS-F214-Assignment2
A simple tool for verifying whether a certain proof of a given sequent is valid or not

## Requirements 
* GCC
* GNU Make

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

## Documentation and Profiling
Refer to [Documentation](Documentation) .

## Examples
[Sample Output 1] (/Documentation/data/sampleOutput1.jpeg)
[Sample Output 2] (/Documentation/data/sampleOutput2.jpeg)
[Sample Output 3] (/Documentation/data/sampleOutput3.jpeg)
[Sample Output 4] (/Documentation/data/sampleOutput4.jpeg)
[Sample Output 5] (/Documentation/data/sampleOutput5.jpeg)
