//백준(10951) A+B - 4

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
    int A,B;

    while((scanf("%d %d", &A, &B)) ==2){
        printf("%d\n", A+B);
    }

    return 0;
}