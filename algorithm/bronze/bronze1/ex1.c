//백준(1546) 평균

#include <stdio.h>
#include <stdlib.h>

int main(){
    int N ;
    scanf("%d", &N);
    float arr[N];
    int max = 0;
    float mean = 0;
    for(int i =0; i<N; i++){
        scanf("%f", &arr[i]);
    }
    max = arr[0];
    for(int i =1 ;i <N; i++){
        if(max <= arr[i]){max = arr[i];}
    }
    for(int i=0; i<N; i++){
        arr[i] = arr[i]/max*100;
        mean += arr[i];
    }
    mean = mean / N;
    printf("%.2f", mean);
    return 0;
}