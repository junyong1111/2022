// 예제9 : 2차원 배열의 임의의 수를 입력받아 각 행과 열의 합을 출력
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    int arr[3][4]; //2차원 배열 생성
    srand(time(NULL)); //랜덤 시드 
    int y_sum = 0;
    int x_sum = 0;

    for (int y=0; y<3; y++){
        for(int x=0; x<4; x++){
            arr[y][x] = rand() % 40+60;
        }
    }
    

    for(int i=0; i<3; i++){
        x_sum = 0;
        for(int j=0; j<4; j++){
            x_sum = x_sum + arr[i][j];
        }
         printf("%d %d", i, x_sum);
    }
    printf("\n");
    return 0;
}
