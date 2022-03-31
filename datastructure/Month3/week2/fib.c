#include <stdio.h>
#include <stdlib.h>

int rFib(int n){
    if(n==0) return 0;
    else if(n==1) return 1;
    else return rFib(n-1) + rFib(n-2);
}

int main(){
    int n ;
    scanf("%d", &n);
    printf("%d\n", rFib(n));

    return 0;
}