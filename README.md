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
