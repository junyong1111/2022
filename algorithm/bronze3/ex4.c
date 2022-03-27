//백준(10872) 팩토리얼

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int Factorial(int n) {
    if (n > 1)
        return n * Factorial(n - 1);
    else return 1;
}
int main(void){
    int N;
    scanf("%d", &N);
    printf("%d\n",Factorial(N));

    return 0;
}