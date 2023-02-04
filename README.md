# Linux-Process-and-Thread-Scheduling
> This repository has three folders. One demonstrates using Linux scheduling policies to **schedule 3 threads** running parallely. Second is 
using Linux Scheduling policies to demonstrate **process scheduling among 3 parallel processes**. Third is the implementation of a **Custom Syscall** in Linux.

--- 
> Below are the explainations for each of them:

# Linux Thread Scheduling

I am launching three threads, each of which relies on three different
functions, countA(), countB() and countC() respectively. Each function does the same
thing, i.e. counts from 1 – 2^32. The following is the detailed specification
of each of the threads, to being with:

1. Thread 1 (Thr-A()): Uses SCHED OTHER scheduling discipline
with standard priority (nice:0).

2. Thread 2 (Thr-B()): Uses SCHED RR scheduling discipline with
default priority.

3. Thread 3 (Thr-C()): Uses SCHED FIFO scheduling discipline with
default priority.

Each of these threads times the process of counting from 1 – 2^32. I have
used the clock gettime() function for obtaining the actual time ticks that
have been used to compute how long it took to complete a function.

After that, I am benchmarking these three schedulers by changing the scheduling
classes of the three threads (keeping the other scheduling priorities the same),
against the counting program.

For these cases, I am using pthread schedsetparam() and
related functions for the same. After running a test whose outputs have been stored in the files thrA.txt, thrB.txt, thrC.txt respectively,
I am generating histograms showing which scheduler completes the task when, depending upon the scheduling
policy. 

I have chosen different colors for the histogram bars, with one axis
showing the time to complete, and the other showing the thread priorities. For our benchmarking, we have chosen 10 values each. 

To run this on your system:
- Clone the repository
- Open the "threadScheduling" directory
- Run ```make```
- Input the priority values that you need to mention for each of the threads, and, enjoy :)

**Note**: A key difference between linux thread scheduling policies is that for the policies *SCHED_RR* and *SCHED_FIFO* the priority value
is can be set by us. Whereas for the scheduling policy *SCHED_OTHER*, priority is always default (i.e. 0) and we only change the **nice** value associated with it.


# Linux Process Scheduling















