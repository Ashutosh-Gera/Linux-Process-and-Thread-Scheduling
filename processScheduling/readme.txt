In our 1_2.c file, we are creating three simultaneous processes and assigning each of them a scheduling policy and 
then calculating the time taken by each process to compile the linux kernel on the basis of our bash scripts namely scriptA.sh, scriptB.sh and scriptC.sh respectively!


In order to achieve our goal of 5 simultaneous processes we were required in total FIVE fork calls (the structure of the program is like a tree)
On the basis of values of time obtained after compiling 3 kernel simultaneously, we have plotted the graph using python and can conclude that:

In general, SCHED_FIFO < SCHED_RR < SCHED_OTHER (in terms of time taken)

Thank you !
Ashutosh Gera
2021026
CSE