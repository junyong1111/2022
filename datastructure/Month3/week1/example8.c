//예제_8: 2차원 배열 생성
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    int Arr[3][4] ={
        {0,1,2,3},
        {10,11,12,13},
        {20,21,22,23},
    };
    for(int y=0; y<3; y++)
    {
        for(int x=0; x<4; x++){
            printf("%2d ", Arr[y][x]);
        }
        printf("\n");   
    }


    return 0;
}
