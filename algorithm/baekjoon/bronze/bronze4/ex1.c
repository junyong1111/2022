// 백준(1008) A/B

#include <stdio.h>

int main(){
    double A,B;
    long double C ;
    scanf("%1lf %1lf", &A, &B);
    C = A/ B;
    printf("%.13Lf\n",C);
    return 0;   
}