// 백준(2750) 수 정렬하기

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void sort(int arr[], int N){
    int temp = 0;
    for(int i=0; i<N; i++){
       for(int j= i+1; j<N; j++){
           if(arr[i]>arr[j]){
               temp = arr[j];
               arr[j] = arr[i];
               arr[i] = temp;
           } //배열을 돌면서 맨 앞부터 비교하면서 스왑해주기
           else continue;
       }
    }//for_i
    for(int i=0; i<N; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void){
    int N;
    scanf("%d",&N);
    int arr[N];
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr,N);
    return 0;
}