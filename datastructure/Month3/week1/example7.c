// 예제_7 : 주사위를 10000번 던져 각 면이 나오는 횟수를 시물레이션 하는 프로그램 작성
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    int arr[6] ={0};
    //  여러개를 한번에 0으로 초기화
    srand(time(NULL));
    for(int i=0; i<10000; i++){
        arr[rand()%6]++;
    }
    for(int i=0; i <6; i++){
        printf("%d %d\n", i+1, arr[i]);
    }



    return 0;
}