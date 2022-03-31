//예제_5 : 추를 이용한 경우의 수
#include <stdio.h>
//함수 구현
void sumOfWeghit(int G){ 
    // 3중 반복문을 이용하여 모든 경우의 수 확인
    int cnt = 0;
    for (int i=1; i<11; i++)
        for(int j=1; j<11; j++)
            for(int k=1; k<11; k++)
                if((2*i + 3*j + 5*k) == G ){
                    printf("%d %d %d\n", i, j, k);
                    cnt ++;
                }
    // 경우의 수 출력
    if (cnt == 0){
        printf("%d\n" , cnt);
    }
    else{
        printf("%d\n", cnt);
    }
};



int main(void){
    int G ;
    scanf("%d" , &G);
    sumOfWeghit(G);
    return 0;
}
