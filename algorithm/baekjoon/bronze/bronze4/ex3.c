// 백준 (9498) 시험 성적

#include <stdio.h>

int main(){
    int A ;
    scanf("%d", &A);
    if (A>=90 && A <=100) 
    printf("A\n");
    else if(A>=80 && A <90)
    printf("B\n");
    else if(A>=70 && A <80)
    printf("C\n");
    else if(A>=60 && A< 70)
    printf("D\n");
    else 
    printf("F\n");
    return 0;
}