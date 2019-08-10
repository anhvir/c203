 c203: Week 03 Story - This page is under construction, please visit later. It shoulkd be ready by Sunday midnight.
=======
Inspired by our lectures last week, I wants to implement sequential and
binary search, and through these implementations, convince myself about
the complexity behaviour of O(n) and O(logn) of the two algorithms.

I'm aware that if we want to build a (well, complicated) application in C,
we'd probably build not a single .c file, but several of them. 
My project today might be not too complicated (or, is it?), but I'll 
try to build it as a multiple-file project anyway, just to learn,
and perhaps to be ready for assignment 1. 

**Technical issues:**
Of course, I should create a new directory/folder for this project.
In a Jupyter terminal I run `mkdir Search` and then `cd Search` 
for this purpose. I will also use Jupyter "Text File" to edit all
of my project's files. Of course, I can do al these things using 
minGW/jEdit or some other combinations, but why not just try Jupyter?

### The main logic 
I love the top-down design approach. 
I start with `main.c` program, where the main() function just looks like:

```c
for (i=0; i<m; i++) {
    founds += (search(B[i],A,n,&cmps) != NOT_FOUND);
    total_cmps += cmps;
}   

```
In my intention, function `search(key, A, n, &cmps)` searches 
for `key` in the array A[n], and also places the number of comparisons 
employed during the search into `cmps`. The function should return the 
index `i` if it finds `i` such that `A[i]==key`, 
or `NOT_FOUND` (which should be pre-defined 
as `-1`, right?) otherwise. 

As I want to measure the speed of the algorithm `search`, it's not fair
to run just one search, so I will prepare an array `B[m]` of search keys,
perform these `m` searches then get average performance. Note that
the performance is indicated by `total_cmps`, and perhaps by measuring
the real CPU time.

With respect to the type of data, 
I will just deal with `int`. That is, `A[n]` and `B[m]`
are just arrays of `int`. In addition, 
I imagine that at the end, I want to test
my program with various values of `m` and `n`, so `A` and `B` should 
be declared as `int *` for use with dynamic memory!

### Using multiple files
Of course I could put all needed functions inside `main.c`. 
But how about putting all tools for creating arrays is one .c file,
and creating `search()` in another file? Wow, it would be a good idea:
next time, whenever I want to use these tools again in a new project,
I just need to copy these files into the new project folde.
That would save my time!

So I build `intArray.c` with 2 functions: 
```c
/*  Creates an array of n integers
    and populates it random numbers, in strictly increasing order     */
int *createSortedArray(int n);

/*  Creates an array of m integers,
    and populates it with random elements of array A[n] */
int *createRandomArrayFromA(int m, int *A, int n);
``` 
As a rule, I should place the above two function prototypes on top 
of my `main.c`. But there is
a better way: I created file `intArray.h` that essentially contains
these 2 prototypes. Then, on top of my `main.c` I just need to put:
```c
#include "intArray.h"
```
Note that: a) `intArray.h` is called a *header file*, and b) in the above 
line, we use **"intArray.h"**, not **<intArray.h>**.
    
### First attempt to  compile
Now, after finishing the typing and saving (`main.c`)[./main.c], 
(`intArray.h`)[./intArray.h], and (`intArray.c`)[./intArray.c]
(yes, you can click on these links to see the codes),
I am thinking about compiling. I can use the Terminal to compile with:
```bash
gcc -Wall -o search main.c intArray.c
```
which tell `gcc` to compile and pack both `main.c` and `intArray.c` into
a single executable file `search` (note: if you do the same thing, you
should comment out the line starting with `search()` in `main.c`).
I also can compile my unfinished project in 3 steps as follow:
```bash
gcc -Wall -c main.c
gcc -Wall -c intArray.c
gcc -o search main.o search.o
```
in which the first step ask `gcc` to translate `main.c` into the 
*object* format, which is a file in machine language, but is not
an executable file (because, say, there is no possible link to 
`createSortedArray()` from `main.c` alone).
 The last step links the object files 
together and create the executable file `search`. Oh yes, my `./search`
is running, but it doesn't do any search!  

### First attempt to use `make`
But hand on, we know a bit about `make`, and I want to employ that for
auto-compiling my project. So far I know that
  * If from Terminal, I invoke `make`, the command will automatically
reads from a special text file named `Makefile`, and I need to build
that `Makefile` in advance; 
  * My `Makefile` should at least contain 
one or a few *targets*. Each target has a *target name* 
and is associated with one or more Terminal's commands (such as `gcc`).
  * If I run `make` from Terminal, `make` automatically runs the commands
which are associated with the *first target* in my `Makefile`.

So, I use `Text File` to write my first ever `Makefile` with the content of:
```make
# my first Makefile just has one simple target
all: intArray.h intArray.c main.c Makefile
	gcc -Wall -o search main.c intArray.c

# Explanations:
#  "all" is a target
#  target "all" depends on 4 files: intArray.h, intArray.c, ...
#     which means that whenever at least one of these dependencies changed
#     the target need to be rebuilt by "make"
#  target "all" is associated with the command "gcc"
#     which means that when building or rebuilding the target,
#     "make" just run that command "gcc"
#
# Important note: the Makefile syntax is a bit picky, before each 
#    associated command (such as the above "gcc") we have to put one
#    and exacly one "<TAB>" character, blank characters are NOT accepted.   
```
Now, from Terminal, I run `make`, and voila, I can see that the above
`gcc` command was invoked! After that I can try `./search` to run my
project. Great!

### Adding sequential search module
Now, of course, I need to supply the search function.
I start with implementing the sequential search algorithm.
The best way to do that implementation is just 
to build 2 other text files, namely, `search.h` and `seq_search.c`.
Fortunately, I already have the `.c` program for sequential search
in the lecture slides! I came there, copied the content, pasted and 
saved it as "seq_search.c". Essentially, I don't need to make a lot 
of changes here, just some simple things to pack that C program
into *a function*. I ended up with my files (`search.h`)[./search.h]
and (`seq_search.c`)(./seq_search.c) (agian, when you see a link, you
can just click on that for the content).

After that I change my `Makefile` to:
```make
# my 2nd Makefile, with added seq_search.c
all: intArray.h intArray.c main.c Makefile seq_search.c
	gcc -Wall -o search main.c intArray.c seq_search.c
```
Now, I can try `make` and `search`, it works for me after a few 
corrections of syntax errors.

### Adding binary search module
There is certainly a number of ways to add binary search into my project.
But here, I choose the following way: Since I can have several targets
in my `Makefile`, I will create two separate targets, one for 
sequential, and one for binary search. I also come up with an interesting
idea: building `bin_search.c` for implementing binary search, and use
the same function name `search` for both sequential and binary search.
It is possible because I will not compile both `seq_search.c` and
`bin_search` into a single executable file. Yes, I went to the lecture
slide again, stole Nir's code, changed a bit, and have my
(`bin_search.c`)[./bin_search.c]. Note that I don't need another
`.h` file because `bin_search.c` has the same interface as `seq_search.c`.

Now my `Makefile` would look like:
```make
# my 3rd Makefile, for both seq and bin search:
all: seq_search bin_search

seq_search: intArray.h intArray.c main.c Makefile seq_search.c
	gcc -Wall -o search main.c intArray.c seq_search.c

bin_search: intArray.h intArray.c main.c Makefile bin_search.c
	gcc -Wall -o search main.c intArray.c bin_search.c

#Note 1: If we just want to build one of the targets, say, "bin_search",
#        all we need is to run:
#           make bin_search 

#Note 2: "all" is the first target, it doesn't have accompanied commands
#       but it has seq_search and bin_search as its dependencies
#       hence, "make" or "make all" is equivalent to two commands:
#            make seq_search
#            make bin_search
```
My project now is ready for use!     

### Improving `Makefile`
I don't actually like the above `Makefile`. at least because I have to
repeat each file name twice. That also means that if I build a new
project, I have to write `Makefile` from scratch.

After a bit of research, I came up with the following 
(`Makefile`)[./Makefile]. Have a look at that file, and you could
see that we can easily adapt it for a new project. If you need 
some more explanations, please click on 
(`Makefile_explaned`)[./Makefile_explained].

### Enjoy!
Suppose that I want to get data for a graph showing the performance
of binary and sequential search, I can run
```bash
./bin_search n m
./bin_search n m

```
with different values of n, and with m=100 (say), and collect the data
into Excel sheet for a graph. If I am good at writing scripts, I can
also build a shell script for running a serie of experiments and
automatically collecting the data into a table. Or, I can just change my
main.c so that it run a bundle of experiments with 
n=1,10,100,1000,...,1000000000 and output efficiency data in a
table format... If you have time, build that graph of running time
(or of number of comparisons) for 
one or both algorithms, you will see the O(n) and O(logn) 
in action!   

### Summary
This story gives examples of
  # Building a multiple-file C project
  # Using `make` and `Makefile`
  # Organizing experiments to measure algorithm/program performance
  # Timing in C code
  # Packing a C program into a function
  # `malloc` and `free`   

-------------------------------------------------------------------
## HOW_TO: download/copy the files from this github repository

If you just want a single file, say, **Makefile**:
  * Click on the link **Makefile** (at the top of this github) and you will see its content 
  * Copy the content and paste into your editor's window before saving on a driver. The easiest way to copy is (a) click on `Raw` to see the plain text content, then (b) press Ctrl-A then Ctrl-C to copy the whole content.  

If you want to download the whole directory:
  * Download this whole directory by clicking `Clone or Download` --> `Download ZIP`, it will normally be downloaded to your *Downloads* directory under the name **c203** or **c203.ZIP** (it might also have a suffix **-master**)
  * Then copy or move the directory **c203** from **Downloads** to under your working directory **week2/**
  * If the downloaded **c203** has the extension **.ZIP**, you likely need to expand the zipped file with command **unzip c203.ZIP**

**How to transfer a file or the whole directory from this github site into your JupyterLab working directory?**  Sorry, I still don't know howto. If you know, please advise. Thanks! 

-------------------------------------------------------------
by avo@unimelb.edu.au, for use in unimelb COMP20003 workshops.

For a teaching week, a new content is (normally) uploaded at the very beginning of the week, and that content is removed one week later.
