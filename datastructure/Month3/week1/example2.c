// 예제_2: 성적출력
#include <stdio.h>

int main(void){
    int score ;
    scanf("%d", &score); // 성적 입력

    if(score<0 || score>100) // 0~100 이외 값 처리
        printf("Wrong Input\n"); 
    else{ //각각 점수에 맞게 성적 출력
        if(score >=90 && score <=100)
            printf("A\n");
        else if(score >=80 && score <90)
            printf("B\n");
        else if (score >= 70 && score <80)
            printf("C\n");
        else 
            printf("D\n");
    } // else

    return 0;
}