#include <iostream>
#include <algorithm>
#define MAX_SIZE 1000

using namespace std;

int flag = 0;
bool check = false;
void rec(int arr[][MAX_SIZE], int N, int len){
    flag = (N-1)/2;

    if(flag %2 == 0){
        flag = 0;
    }
    else flag = 1;

    int temp = N;
    int X , Y ;
    if(N==1){
        arr[len-1/2][len-1/2] = check; //배열의 길이
        flag = 1;
    }
    
    else{
         
        if(flag==0 ){
            X = ((len - N) /2) -1; //배열의 길이 - N /2
            Y = (len - N) /2; //배열의 길이 - N /2

            for(int j=0; j<temp; j++){
                    arr[Y][++X] = flag ;
                } //가장자리 배열 접근
                temp --;
            for(int j=0; j<temp; j++){
                arr[++Y][X] = flag;
            }
            for(int j=0; j<temp; j++){
                arr[Y][--X] = flag;
            }
                temp --;
            for(int j=0; j<temp; j++){
                arr[--Y][X] = flag;
            }
            flag = 1;
            check  = true;
        }
        else if(flag==1){
            X = ((len - N) /2) -1; //배열의 길이 - N /2
            Y = (len - N) /2; //배열의 길이 - N /2

            for(int j=0; j<temp; j++){
                    arr[Y][++X] = flag ;
                } //가장자리 배열 접근
                temp --;
            for(int j=0; j<temp; j++){
                arr[++Y][X] = flag;
            }
            for(int j=0; j<temp; j++){
                arr[Y][--X] = flag;
            }
                temp --;
            for(int j=0; j<temp; j++){
                arr[--Y][X] = flag;
            }
            flag = 0;
            check  = false;
        } //else if 
        rec(arr , N-2, len);
    } // N > 1    
} //함수종료

int main(){
    
    int Num = 0;
    cin >> Num;
    int len = Num;
    int arr[MAX_SIZE][MAX_SIZE];
    rec(arr, Num, len);
    for(int i=0; i<len ;i++){
        for(int j=0; j<len; j++){
            printf("%d " ,arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}