// 다항식 덧셈 계산 구현
#include <stdio.h>
#include <stdlib.h>
#define MAX_DEGREE 100
typedef struct
{
    int degree ; // 최고차항 차수 기억
    int coef[MAX_DEGREE];
}Poly;
void print(Poly p){
    int i, j;
    for(i=0, j= p.degree; i<p.degree; i++, j-- ){
        printf("%2dx^%d +", p.coef[i], j);
    }
    printf("%2d\n", p.coef[p.degree]);
}
Poly addPoly(Poly A, Poly B){
    Poly C;
    int Apos = 0, Bpos = 0, Cpos = 0;
    int degA = A.degree;
    int degB = B.degree;
    C.degree = (degA >= degB) ? degA : degB;

    while(Apos <= A.degree && Bpos <= B.degree){
        if(degA > degB){
            C.coef[Cpos] = A.coef[Apos];
            Apos ++ ;
            Cpos ++ ;
            degA -- ; 
        } // if
        else if(degA == degB) {
            C.coef[Cpos] = A.coef[Apos] + B.coef[Bpos];
            Apos ++;
            Bpos ++;
            Cpos ++;
            degA --;
            degB --;
        } // else if
        else {
            C.coef[Cpos] = B.coef[Bpos];
            Bpos++; Cpos ++; degB -- ;
        } // else
    } //while
    return C;
}

int main(void){
    Poly a, b, c;
    scanf("%d %d", &a.degree, &b.degree);

    for (int i=0; i<=a.degree; i++)
        scanf("%d", &a.coef[i]);
    for (int i=0; i<=b.degree; i++)
        scanf("%d", &b.coef[i]);

    print(a);
    print(b);
    c= addPoly(a,b);
    printf("=====================================================================\n");
    print(c);

    return 0;
}