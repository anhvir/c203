# c203: Week 09 

This week, you will implement natural mergesort. For that, you should start
from the programs you built for the last workshop. Alternatively, you can
employ the implemented files supplied here. Note that here, 2 versions 
are supplied: one for array-based, one for llist-based. You can download/transfer the whole directory into your work space, and then try the implemetations with:
```bash
make
./array_msort
./list_msort
```
After that you can pick one of the files: `array_msort.c` or `list_msort.c` and change it for implementing natural mergesort. 

  * `array_msort.c`: a single `.c` file implementing array-based bottom-up mergesort.
  * `list_msort.c` and `.h`: an implementation of bottom-up mergesort.
  *  `linked_list.c` and `.h`: a ready-to-use implementation of linked lists, it would be useful to have a look at this file and learn some techniques from here.
  *  `queue.c` and `.h`: a ready-to-use implementation of queue. Note: yhis implementation is different from what supplied in `p.7.1.c`. Again, it would be useful to have a look at this file and learn some techniques from here.
  * `main.c`: driver for testing `list_msort`.

------------------------------------------------------
### How to transfer a file or the whole directory from this github site into your JupyterLab working directory?

You can just use `git clone`. Run the following command in a Jupyter's Terminal window:
```bash
git clone http://github.com/anhvir/c203
```
And you will see a new folder `c203` under your current directory.

-------------------------------------------------------------
by avo@unimelb.edu.au, for use in unimelb COMP20003 workshops.

For a teaching week, a new content is (normally) uploaded at the very beginning of the week, and that content is removed one week later.
