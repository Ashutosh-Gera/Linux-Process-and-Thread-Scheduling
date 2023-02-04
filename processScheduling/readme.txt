In our 1_2.c file, we are creating three simultaneous processes and assigning each of them a scheduling policy and 
then calculating the time taken by each process to compile the linux kernel on the basis of our bash scripts namely scriptA.sh, scriptB.sh and scriptC.sh respectively!


In order to achieve our goal of 5 simultaneous processes we were required in total FIVE fork calls (the structure of the program is like a tree)

To compile the linux kernel using this process scheduling and scripts, follow the following steps:

1. Have the linux kernel [whichever version u want to be compiled] downloaded in your VM.
2. Make 3 directories namely "a", "b" and "c" respectively.
3. Make sure the un-tar file of linux kernel is present in each of these directories.
4. Run `make` outside these directories and bingo! you'll have 3 linux kernels being compiled simultaneously in your VM.

I ran this file in a artix VM [hosted on Oracle virtual box] having Linux kernel 5.19.9 on Manjaro OS host and the time values plotted in the graph are the time it took for my VM to compile 
kernels [each using 2 cores]. This time can vary depending on your Host OS as well as the VM, it can rage from ~20 minutes upto ~1.5 hrs for some OSes.

On the basis of values of time obtained after compiling 3 kernel simultaneously, we have plotted the graph using python and can conclude that:


In general, SCHED_FIFO < SCHED_RR < SCHED_OTHER (in terms of time taken)

Thank you!
Ashutosh Gera