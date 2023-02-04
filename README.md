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
I am generating histograms [file named plot.ipynb] showing which scheduler completes the task when, depending upon the scheduling
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

This part involves creating three process, instead of the three
threads. Each of these process involves compiling a copy of the Linux kernel source (with the minimal config, download by clicking [here](https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.19.8.tar.xz)). The three processes are created with fork() and thereafter the child processes is using the execl() family system calls to run a different a different bash script(namely scriptA.sh, scriptB.sh and scriptC.sh), each
of which comprises of the commands to compile a copy of the kernel. To
time the execution, the parent process is getting the clock timestamp (using
clock gettime()) before the fork and after each process terminates returns.

After running the three compiling processes parallely, we get the time value taken by each scheduling policies and plot a histogram 
using those values [present in the file plot2.ipynb file].

To compile the linux kernel using this process scheduling and scripts, follow the following steps:

- Have the linux kernel [whichever version u want to be compiled] downloaded in your VM.
- Make 3 directories namely "a", "b" and "c" respectively.
- Make sure the un-tar file of linux kernel is present in each of these directories.
- Run `make` outside these directories and bingo! you'll have 3 linux kernels being compiled simultaneously in your VM.

**Key-point**: In order to run the 3 processes paraellely and also to track the time taken by each process to complete, we were required **5** fork() calls.

# Simple-Syscall-Implementation

## Explanation
Firstly add the new syscall to the table of already existing syscalls
in ```build/linux-5.xx.xx/arch/x86/entry/syscalls/syscall_64.tbl``` add

    451 kern_2D_memcpy sys_kern_2D_memcpy

Then implement the same syscall in `sys.c` located at `buiild/linux-5.xx.xx/kernal/sys.c`
    
Where we define the following function 

    SYSCALL_DEFINE4(kern_2D_memcpy, float *, MAT1, float *, MAT2, int, ROW, int, COL)

We take the pointers to the two float matrices where `MAT1` is the destination matrix and `MAT2` is the source matrix. 
We create a new matrix of dimensions ROWxCOL in the kernel space to which we then copy the contents of `MAT2` using `copy_from_user` and then we copy it to `MAT1` using `copy_to_user`
If any of the above are not possible we return `-EFAULT` else return `0` incase of success.

<br>

## Building/Compiling the syscall
After adding the syscalls we need to run the following commands to configure our kernel

    make

    make modules_install

    cp arch/x86_64/boot/bzImage /boot/vmlinuz-linux-5.19.9-gb0ccfee715-dirty
    
    cp System-5.19.9.map System-5.19.9-gb0ccfee715-dirty.map

    mkinitcpio -k 5.19.9-gb0ccfee715-dirty -g /boot/initramfs-linux-5.19.9-gb0ccfee715-dirty.img

    grub-mkconfig -o /boot/grub/grub.cfg

    reboot
<br>

## Test the syscall
Make the test files in any directory and then run

    gcc test.c -o test
    ./test


> Note: Each of the folders have a readMe.txt of their own too, inside. You can use those for further reference.

> Thank you for visiting. Hope it helps.

# Made with :blue_heart: by Ashutosh Gera


















