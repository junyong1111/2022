// 구조체 동적배열 사용
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int sNum;
    char sName[20];
}Student;


int main(){
    int n;
    scanf("%d", &n);
    Student* S = (Student*)malloc(sizeof(Student) *n );
    for(int i=0; i<n; i++){
        scanf("%d %s", &S[i].sNum, S[i].sName);
    }
    for(int i=0; i<n; i++){
        printf("%d : %s\n", S[i].sNum, S[i].sName);
    }

    //int * arr = (int *)malloc(sizeof(int) * n);
    int * arr = malloc(n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
     for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}