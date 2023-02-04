#include <stdio.h>
#include <stdint.h>
#include <sys/syscall.h>
#include <unistd.h>
#define SYS_kernel_2d_memcpy 451

int main(){

    float mat1[2][2];
    float mat2[2][2];
    int row = 2;
    int col = 2;
    for(int i = 0;i<2;i++){
        for(int j = 0;j<2;j++){
            mat1[i][j] = i+j;
        }
    }
    printf("Original matrix:\n");
    for(int i = 0;i<2;i++){
        for(int j = 0;j<2;j++){
            printf("%f ",mat1[i][j]);
        }
        printf("\n");
    }
    long x = syscall(SYS_kernel_2d_memcpy,mat1,mat2,row,col);
    printf("System call returned %d.\n",x);
    printf("Copied mat:\n");
    for(int i = 0;i<2;i++){
        for(int j = 0;j<2;j++){
            printf("%f ",mat2[i][j]);
        }
        printf("\n");
    }
    return 0;
}