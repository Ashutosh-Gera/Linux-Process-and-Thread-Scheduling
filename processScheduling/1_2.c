#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(void) {

    pid_t n1;
    struct sched_param param;
    n1 = fork();

    if (n1 == -1) {
        //fork failed
        perror("Error occurred in calling function fork()");
    } else if (n1 == 0) {
        //child process is executing
        pid_t pidOne = getpid(); // process id of first child

        pid_t n2;
        n2 = fork();

        if (n2 == -1) {
            perror("error occured in calling fork()");
        } else if (n2 == 0) {
            //child

            pid_t pidTwo = getpid();

            pid_t n3;
            n3 = fork();

            double timeA = 0.0;
            clock_t beginA;
            clock_t endA;

            pid_t pidThree;
            beginA = clock();
            if (n3 == -1) {
                perror("error occured in calling fork()");
            } else if (n3 == 0) {
                //child
                param.sched_priority = 30;
                if (sched_setscheduler(n3, SCHED_RR, &param)) {
                    perror("COuldn't change scheduling class");
                }
                pidThree = getpid();
                // beginA = clock();
                // clock_t beginA = clock();

                execvp("./scriptA.sh", NULL);

            } else {
                //parent
                wait(NULL);
                endA = clock();

                timeA += (double)(endA - beginA) / CLOCKS_PER_SEC;

                printf("The elapsed time by A is %f seconds\n", timeA);

            }
        
        } else {
            //parent
            pid_t n4;
            n4 = fork();

            double timeB = 0.0;
            clock_t beginB;
            clock_t endB;

            pid_t pidFour;
            beginB = clock();
            if (n4 == -1) {
                perror("error occured in calling fork()");
            } else if (n4 == 0) {
                //child
                pidFour = getpid();
                param.sched_priority = 30;
                if (sched_setscheduler(n4, SCHED_FIFO, &param)) {
                    perror("Couldn't change scheduling class!");
                }
                // beginB = clock();
                // clock_t beginA = clock();

                execvp("./scriptB.sh", NULL);

            } else {
                //parent
                wait(NULL);
                endB = clock();

                timeB += (double)(endB - beginB) / CLOCKS_PER_SEC;

                printf("The elapsed time is %f seconds\n", timeB);
            }
        }

    } else {

        pid_t n5;
        n5 = fork();

        double timeC = 0.0;
        clock_t beginC;
        clock_t endC;

        pid_t pidFive;
        beginC = clock();
        if (n5 == -1) {
            perror("error occured in calling fork()");
        } else if (n5 == 0) {
            //child
            pidFive = getpid();
            // beginC = clock();
            // clock_t beginA = clock();

            execvp("./scriptC.sh", NULL);

        } else {
            //parent
            wait(NULL);
            endC = clock();

            timeC += (double)(endC - beginC) / CLOCKS_PER_SEC;

            printf("The elapsed time is %f seconds\n", timeC);
        }


    }

}
