// 백준(10039) 평균 점수

#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[5] ={0}; // 학생 점수 저장 배열
    int avg = 0 ; // 평균값 저장 변수
    for(int i=0; i<5; i++)
        scanf("%d", &arr[i]); //점수 입력 받기
    for(int i=0;i<5;i++){
        if(arr[i] >=40)
            avg += arr[i];
        else
            avg += 40;
    }//for 40점 이상은 그대로 미만은 40으로 고정
    avg /= 5; //    점수총합/인원수
    
    printf("%d ", avg);
    printf("\n");
    return 0;
}