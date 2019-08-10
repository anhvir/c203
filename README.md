 c203 Week 03 Story
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

**My first attempt**
I start with main.c program, where the main() function just looks like:

```c
for (i=0; i<m; i++) {
    founds += (search(B[i],A,n,&cmps) != NOT_FOUND);
    total_cmps += cmps;
}   

```
In my intention, I'll function `search(key, A, n, &cmps)` that search 
for `key` in the array A[n], and also places the number of comparisons 
employed for the search into `cmps`. The function should return the 
index `i` where `A[i]==key`, or `NOT_FOUND` (which should be pre-defined 
as `-1`, right?) otherwise. 

As I want to measure the speed of the algorithm `search`, it's not fair
to run just one searach, so I will prepare an array `B[m]` of search keys,
perform these `m` search then get average performance.

For simplicity, I will just deal with `int`. That is, `A[n]` and `B[m]`
are just arrays of `int`. I imagine that at the end, I want to test
my program with various values of `m` and `n`, so `A` and `B` should 
be declared as `int *` for use with dynamic memory!

**Trying multiple files:**
Of course I could put all needed functions inside `main.c`. 
But how about putting all tools for creating arrays is one .c file,
and creating `search()` in another file? Wow, it would be a good idea:
next time, whenever I want to use these tools again in a new project,
I just need to copy these files into the new project folder for use.
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
As a rule, I should place the above two function prototype. But there is
a better way: I created file `intArray.h` that essentially contains
these 2 prototypes. Then, on top of my `main.c` I put:
```c
#include "intArray.h"
```
Note that: a) `intArray.h` is called a *header file*, and b) in the above 
line, we use **"intArray.h"**, not **<intArray.h>**.
    
### First attempt to  compile
Now, after finishing the typing for `main.c`, `intArray.h`, and `intArray.c`,
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
`createSortedArray()` ). The last step links the object files 
and create the executable `search`.  

### First attempt to use make, to compile and test
But hand on, we knew a bit about `make`, and I want to employ that for
auto-compiling my project. So far I know that
  * If from Terminal, I invoke `make`, the command will automatically
reads from a special text file named `Makefile`, and I need to build
that `Makefile` myself; 
  * My `Makefile` should optionally have a number of defintions, and, most 
importantly, one or a few *targets*. Each target has a *target name* 
and is associated with one or more Terminal's commands (such as `gcc`).
  * If I run `make` from Terminal, it automatically runs the commands
which are associated with the *first* target in my `Makefile`.

So, I use `Text File` to write my first ever `Makefile` with the content:
```make
# my first Makefile just has one simple target
all: intArray.h intArray.c main.c Makefile
	gcc -Wall -o search main.c intArray.c

# Explanations:
#  "all" is a target
#  target "all" depends on 4 files: intArray.h, intArray.c, ...
#     which means that whenever at least one of these files changed
#     the target need to be rebuilt by "make"
#  target "all" is associated with the command gcc
#     which means that when builds or rebuilds the target,
#     "make" just run the command gcc
#
# Important note: the Makefile syntax is a bit picky, before each 
#    associated command (such as the above "gcc") we have to put one
#    exacly one "<TAB>" character, blank characters NOT accepted.   
```
Now, from Terminal, I run `make`, and voila, I can see that the above
`gcc` command was invoked! After that I can try `./search` to run my
project. Great!

### Adding sequential search module
Now, of course, the best way to implement sequential search is just 
to build 2 other text files,namely, `search.h` and `seq_search.c`.
Forthunately, I already have the .c program for sequential search
in the lecture slides! I came there, copy the content, paste and 
save it as "seq_search.c". Essentially, I don't need to make a lot 
of changes here, just some simple things to pack that C program
into *a function*. I ended up with my files (`search.h`)[./search.h]
and (`seq_search.c`)(./seq_search.c).

After that I change my `Makefile` to:
```make
# my 2nd Makefile, with added seq_search.c
all: intArray.h intArray.c main.c Makefile seq_search.c
	gcc -Wall -o search main.c intArray.c
```
Now, I can try `make` and `search`, it works for me after a few 
corrections of syntax errors.

### Adding binary search module
    

Content for this week: a number of file for a software called `toy`:
  * `intArray.h` and `intArray.c`: functions for generating a random array and counting number of prime numbers in an array
  * `prime.h` and `prime.c`: functions for checking if a number is a prime number and ...
  * `main.c` : the main program that actually employ the fuctions defined in the above module to do some (kind of) experiment on primr numbers
  * `Makefile1`, `Makefile2`, `Makefile3`, `Makefile4` : these files are all equivalent to some extent, and is a valid candidate for the `Makefile` of this `toy` project. If you want to use, say, `Makefile4` you need to:

      cp Makefile 4 Makefile

      make
 
    and that `make` will compile the `toy` software for you.
  * Why 4 versions of `Makefile`? Just only for you to compare them and learn a bit about Makefile.   

If you just want a single file, say, `main.c`:
  * Click on `main.c` and you will see its content 
  * Copy the content and paste into your jEdit/editor window, then save as `main.c`

If you want to download the whole directory:
  * Download this whole directory by clicking `Clone or Download` --> `Download ZIP`, it will normally be downloaded to your `Downloads` folder under the name `c203-master` or `c203-master.ZIP`
  * Then copy or move the folder `c203` from `Downloads` to under your working folder `week3/`
  * If the downloaded `c203-master` has the extension `.ZIP`, you likely need to expand the zipped file with command `unzip c203-master.ZIP`
 
-------------------------------------------------------------

Note: For this week, the workshop slides are also included as a .PDF file. Enjoy! 

-------------------------------------------------------------
by anhvir@gmail.com, for use in unimelb COMP20003 workshops.

For a teaching week, a new content is (normally) uploaded at the very beginning of the week, and that content is removed one week later.
