// 백준(2577) 숫자의 개수

#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b, c;
    int sum = 0;
    int arr[10] = {0} ;
    scanf("%d %d %d", &a, &b,&c);
    sum = a * b * c;
    int cnt = 0;

    while(sum!=0){
        cnt = sum %10;
        switch (cnt)
        {
        case 0 :
            arr[0] ++;
            sum = sum /10;
            break;
        case 1 :
            arr[1] ++;
            sum = sum /10;
            break;
        case 2 :
            arr[2] ++;
            sum = sum /10;
            break;
        case 3 :
            arr[3] ++;
            sum = sum /10;
            break;
        case 4 :
            arr[4] ++;
            sum = sum /10;
            break;
        case 5 :
            arr[5] ++;
            sum = sum /10;
            break;
        case 6 :
            arr[6] ++;
            sum = sum /10;
            break;
        case 7 :
            arr[7] ++;
            sum = sum /10;
            break;
        case 8 :
            arr[8] ++;
            sum = sum /10;
            break;
        default:
            arr[9] ++;
            sum = sum /10;
            break;
        }
    }
    for(int i=0; i<10; i++){
        printf("%d\n", arr[i]);
    }



    return 0;
}