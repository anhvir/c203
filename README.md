 c203 Week 02:
=======

  * `random_friend.c` is a program which lists the names of my friends and also pick a random one from them. But this program doesn't work, as it contains a number of bugs.
  * `Makefile1`, `Makefile2`, and `Makefile3` are all equivalent. They are simple. You can use and have a look at each of them (in the order) to understand a bit about Makefile.
  * Playing with `make` and `gdb` using `random_friend.c`: 
    * First, copy `Makefile1` to `Makefile` (using command `cp Makefile1 Makefile`, and try `make`,
    * Then, run the executable `afriend`,
    * Now, you probably saw that the program crashed. Use `gdb` to find errors and fix the program.
  * Explore `Makefile2` and `Makefile3`. They are equivalent to `Makefile1` but are in a more conventional and useful format. Next week we will see the use of `Makefile2` and `Makefile3` in a more complicated context.


---------------------------------------------------------
**HOW_TO: download/copy the files from this github repository**

If you just want a single file, say, **Makefile**:
  * Click on the link **Makefile** (at the top of this github) and you will see its content 
  * Copy the content and paste into your editor's window before saving on a driver. The easiest way to copy is (a) click on `Raw` to see the plain text content, then (b) press Ctrl-A then Ctrl-C to copy the whole content.  

If you want to download the whole directory:
  * Download this whole directory by clicking `Clone or Download` --> `Download ZIP`, it will normally be downloaded to your *Downloads* directory under the name **c203** or **c203.ZIP** (it might also have a suffix **-master**)
  * Then copy or move the directory **c203** from **Downloads** to under your working directory **week2/**
  * If the downloaded **c203** has the extension **.ZIP**, you likely need to expand the zipped file with command **unzip c203.ZIP**

**How to dowload a file or the whole directory from this github site into your JupyterLab working directory?**  Sorry, I still don't know howto. If you know, please advise. Thanks! 

-------------------------------------------------------------
by anhvir@gmail.com, for use in unimelb COMP20003 workshops.

For a teaching week, a new content is (normally) uploaded at the very beginning of the week, and that content is removed one week later.
