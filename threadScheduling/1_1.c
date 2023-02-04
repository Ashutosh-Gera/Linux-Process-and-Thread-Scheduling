#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

int i = 1; // global var
//pthread_t id[3];

void* countA(void* priorityValue) {
    
    long long max = pow(2, 32);
    long long i = 1;
    int priority_value = *(int *) priorityValue;
    struct sched_param param;
    //For SCHED_OTHER, priority is always default(0)
    param.sched_priority =0;
    nice(priority_value);
    //nice(0);
    pthread_t thrA = pthread_self();
    double timeSpent = 0.0;
    clock_t begin = clock();
    int err;

    // FILE *fptr;
    // fptr = fopen("/home/ashu/ques1_1/thrA.txt", "a");

    // if (fptr == NULL) {
    //     printf("Error!");
    //     exit(1);
    // }

    if (pthread_setschedparam(thrA, SCHED_OTHER, &param) == 0) {
        printf("Thread A created successfully! using SCHED_OTHER policy and priority: %i \n", priority_value);
    } else {
        printf("\ncan't create thread :[%s]\n", strerror(err));
        printf("%i",pthread_setschedparam(thrA, SCHED_OTHER, &param));
    }

    for (i; i <= max; i++){
        //printf("%lli\n", i);
        continue;
    }
    //printf("%lli %lli", max, i);
    clock_t end = clock();

    timeSpent += (double)(end - begin) / CLOCKS_PER_SEC;

    //fprintf(fptr, "%f Priority: %i\n", timeSpent, priority_value);
    //fclose(fptr);

    printf("The elapsed time by A is %f seconds\n", timeSpent);
    pthread_exit(&i);
}

void* countB(void* priorityValue) {
    long long max = pow(2, 32);
    long long i = 1;
    int priority_value = *(int *) priorityValue;
    struct sched_param param;
    //For SCHED_RR, priority is aset by us
    param.sched_priority = priority_value;
    //nice(0)
    pthread_t thrB = pthread_self();
    double timeSpent = 0.0;
    clock_t begin = clock();
    int err;

    // FILE *fptr;
    // fptr = fopen("/home/ashu/ques1_1/thrB.txt", "a");

    // if (fptr == NULL) {
    //     printf("Error!");
    //     exit(1);
    // }

    if (pthread_setschedparam(thrB, SCHED_RR, &param) == 0) {
        printf("Thread B created successfully! using SCHED_RR policy and priority: %i \n", priority_value);
    } else {
        printf("\ncan't create thread :[%s]\n", strerror(err));
        printf("%i",pthread_setschedparam(thrB, SCHED_RR, &param));
    }

    for (i; i <= max; i++){
        //printf("%lli\n", i);
        continue;
    }
    //printf("%lli %lli", max, i);
    clock_t end = clock();

    timeSpent += (double)(end - begin) / CLOCKS_PER_SEC;

    //fprintf(fptr, "%f Priority: %i\n", timeSpent, priority_value);
    //fclose(fptr);
    
    printf("The elapsed time by B is %f seconds\n", timeSpent);
    pthread_exit(&i);
}

void* countC(void* priorityValue) {
    long long max = pow(2, 32);
    long long i = 1;
    int priority_value = *(int *) priorityValue;
    struct sched_param param;
    //For SCHED_FIFO, priority is aset by us
    param.sched_priority = priority_value;
    //nice(0)
    pthread_t thrC = pthread_self();
    double timeSpent = 0.0;
    clock_t begin = clock();
    int err;

    // FILE *fptr;
    // fptr = fopen("/home/ashu/ques1_1/thrC.txt", "a");

    // if (fptr == NULL) {
    //     printf("Error!");
    //     exit(1);
    // }

    if (pthread_setschedparam(thrC, SCHED_FIFO, &param) == 0) {
        printf("Thread C created successfully! using SCHED_FIFO policy and priority: %i \n", priority_value);
    } else {
        printf("\ncan't create thread :[%s]\n", strerror(err));
        printf("%i",pthread_setschedparam(thrC, SCHED_RR, &param));
    }

    for (i; i <= max; i++){
        //printf("%lli\n", i);
        continue;
    }
    //printf("%lli %lli", max, i);
    clock_t end = clock();

    timeSpent += (double)(end - begin) / CLOCKS_PER_SEC;

    //fprintf(fptr, "%f Priority: %i \n", timeSpent, priority_value);
    //fclose(fptr);
    
    printf("The elapsed time by C is %f seconds\n", timeSpent);
    pthread_exit(&i);
}

int main(void) {
    
    pthread_t id[3];

    int priorityA, priorityB;
    int priorityC;
    
    //A for SCHED_OTHER
    //B for SCHED_RR
    //C for SCHED_FIFO

    for (int i = 0; i < 10; i++) {

        printf("Enter priority for thread A(SCHED_OTHER): ");
        scanf("%i", &priorityA);
        printf("Enter priority for thread B(SCHED_RR): ");
        scanf("%i", &priorityB);
        printf("Enter priority for thread c(SCHED_FIFO): ");
        scanf("%i", &priorityC);

        pthread_create(&id[0], NULL, countA, &priorityA);
        pthread_create(&id[1], NULL, countB, &priorityB);
        pthread_create(&id[2], NULL, countC, &priorityC);

        int* ptr1;
        int* ptr2;
        int* ptr3;
        
        pthread_join(id[0], (void**)&ptr1);
        pthread_join(id[1], (void**)&ptr2);
        pthread_join(id[2], (void**)&ptr3);
    }

    return 0;




    // int priority_valueA = 6;
    // pthread_create(&id[0], NULL, countA, &priority_valueA);

    // int* ptr;
    // pthread_join(id[0], (void**)&ptr);
    // printf("Value recevied by parent from child: ");
    // printf("%i\n", *ptr);    


}


//int pthread_equal(pthread_t tid1, pthread_t tid2); returns non zero value if two thread ids are equal
//pthread_t pthread_self(void); function used by a thread to print its own thread id


//countA();
    // double time_spent = 0.0;
 
    // clock_t begin = clock();
 
    // countA();
 
    // clock_t end = clock();
 
    // time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    // printf("The elapsed time is %f seconds", time_spent);
 
    // return 0;