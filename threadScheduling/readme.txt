In this 1_1.c file we are making three threads run simultaneously and using different scheduling policy for each thread with different priority values!

The design of our program is as follows:

1. In the main function, after instantiation of required variables, we are running a loop in order to have 10 different priority values.
2. For each iteration, we create 3 threads with the starting routines as countA, countB and countC respectively.
3. For threadA, the scheduling policy used is SCHED_OTHER, which always has default priority value as 0, but we are changing its nice value according to our input
4. For threads B and C, the scheduling policies are SCHED_RR and SCHED_FIFO respectively, with their priority values as desired by input.
5. upon whole for loop iteration, we get three .txt files namely thrA.txt, thrB.txt, thrC.txt respectively which contain the 
6. values of time taken by each thread for the task

After obtaining these values, we use matplotlib, numpy, seaburn and pandas python libraries to get our plot

From the plot, we conclude that the general order of time taken by scheduling policies is:
SCHED_FIFO < SCHED_RR < SCHED_OTHER

Thank you
Ashutosh Gera 