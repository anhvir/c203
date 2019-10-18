COMP20003 Week 12: Notes on assignment 2
=======================


  # How to do the timing?
Function clock() in <time.h> return the current time. The returned value belongs
to the data type clock_t, but we don't need to know it. The code below shows
how to do the timing.
```c
#include <time.h>

   clock_t start= clock();  // start= current time

   // code fragment we want to do timing

   double secs= ((double) (clock() - start)) / CLOCKS_PER_SEC;
   printf("Time passed= %.6f seconds\n", secs);

  # What is minimal requirement for the experiment?
    <I will fill in a bit later, but definitely by Sunday> 

