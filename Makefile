# ---- A very simple Makefile --------------------------------------------
# ---- for compiling random_friend.c ----
# Anh Vo, for unimelb.COMP20003.workshop.week2
# the lines preceded by # are just comments
#

# The actual content of this "Makefile" file is just in lines 9-13

afriend: random_friend.c
	gcc -g -o afriend random_friend.c

clean: 
	rm -f *.o afriend


# Explainations:
# In lines 9 and 12, "afriend" is a target, "clean" is a target
 
# target "afriend" has 1 dependency: random_friend.c,
#      that is, it depends on these files (explained later).
   
# target "friend" is associated with command (called recipe):
#	gcc -g -o afriend random_friend.c
#      ( which contains a single <TAB> at the beginning of the line)
    
# If we want to run the recipe of "afriend", ie. the
# "gcc" command in line 10,  all we need to do is to run the
# following command (from your terminal command line):
#
#        make afriend
# where "make" is the command, "afriend" is the target "afriend" just described 
# above.

# How does it work?
#   - command "make" will automatically read from the file "Makefile"
#     in your current directory
#   - it look for a tagtet named "afriend", and then just executes the commands
#     associated with the target
#   - REMEMBER that you must have the file "Makefile", and that you should
#     not change the filename. If you accidently have Makefile.txt instead,
#     then you have to change the name, by typing the command:
#          mv Makefile.txt Makefile
 
# So, what are the dependencies for?
#   - after you ran "make afriend" successfully, if you try to re-run
#     "make afriend", nothing will happen, because "make" sees no need
#     to re-execute the command "gcc"
#   - but, say, if you now make change to "main.c", and then run "make afriend",
#     the "gcc" command will be executed again. That is where dependencies 
#     work. "make" sees that "afriend" depends on "main.c", hence when "main.c"
#     change, "make" know that it has to rerun the "gcc".
#
# What is the target "clean" (in our file "Makefile") for?
#     The target "clean" is associated with command "rm -t *.o afriend".
#     The command "rm -f *.o afriend" means remove (or delete) all files 
#     ended in ".o"  and file "afriend" (they all are ouput of gcc).
#     So when we run "make clean", all outputs of gcc are deleted.
#     After that, if you run "make afriend", the "gcc ..." command will 
#     be executed even if you did not make any change to any files.

# Final notes:
# (1) If you run just
#         make
#     (ie with no argument), "make" will search for the first target
#     in "Makefile" and execute that target. In our case, "make" 
#     is equivalent to "make afriend".
# (2) Have a look at Makefile2, Makefile3, Makefile4 (in order). Each
#     of them is equivalent to this "Makefile", but is a bit more 
#     complicated (and more useful). Learn from them!
               
