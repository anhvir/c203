COMP20003 Week 12: Notes on assignment 2
=======================


  # How to do the timing?
Function `clock()` in `<time.h>` return the current time. The returned value belongs
to the data type `clock_t`, but we don't need to know that data type. The code below shows
how to do the timing.
```c
#include <time.h>

   clock_t start= clock();  // start= current time

   // code fragment we want to do timing

   double secs= ((double) (clock() - start)) / CLOCKS_PER_SEC;
   printf("Time passed= %.6f seconds\n", secs);
```

  # What is minimal requirement for the experiments?
  You need to run at least 72 experiments ( 3 levels x 2 propagations x 4 budgets x 3 samples ). Suppose that your program outputs required data into 
`output.txt` as asked for by the specs. Then you can use the following script
to run all 72 experiments and gather all output into a single file called 
`acc_output.txt`. Later on you can read that file and build your tables and graphs.
The content of the script is:
```bash
for level in 1 2 3 
do
  for s in max avg 
  do
    for budget in 10 100 1000 2000
    do  
      for exp in 1 2 3 
      do  
        echo ./pacman $level ai $s $budget >> acc_output.txt 
        ./pacman $level ai $s $budget 
        cat ./output.txt >> acc_output.txt
      done
    done
  done
done
```
  # How to use the above script: 
First copy the content into file `run_expts` in your `assg2` directory.
Then execute command:
```bash
chmod 777 ./run_expts
```
Now, it's ready for running. You will run it with:
```bash
./run_expts
```
  # Note 1: 
The script will invoke your program 72 times! Make sure that before 
running script you change `Makefile` to have the flag `-O3` to allow the executable program to run faster. That is, the 
first 3 lines of `Makefile` now should be changed to:
```make
CC=gcc
CPPFLAGS=-Wall   -O3 -std=gnu99
#CPPFLAGS=   -g  -std=gnu99
``` 
and of course, run
```bash
make clean
make
```
to rebuild `pacman` after changing `Makefile`.

  # Note 2:
The script might take a few hours to run (perhaps 4-8 hours in my trial, but it might be totally different for your case). Make sure that you keep your laptop connected to the power!
To have a better estimation of time: Just run `./pacman 2 ai max 1000` to see how long it takes, then multiply that time by 72 * 1.5 (well, I hope that the coefficient 1.5 covers well the worst case!) 
   
Happy Coding!

